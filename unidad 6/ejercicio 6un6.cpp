#include <stdio.h>
#include <string.h>

typedef struct{
	int codigo;
	char titulo[40];
	char autor[40];
	int stock;
}info;

//Ejercicio 6 (Sistemas de Gestión con Menú y Acceso Secuencial)
//La biblioteca de la facultad de Ingeniería cuenta con el archivo TITULOS.DAT con los siguientes datos para cada libro:
//(Código 1..500, Título, Autor, Stock), ordenado por código. Mediante un menú modular, codificar un programa que dé
////solución a los siguientes requerimientos:
//a) Dado un código, recupere la información del libro e informe su título y la cantidad de ejemplares en stock.
//b) Dado el nombre de Autor, muestre todos sus libros registrados y la cantidad total de libros que tiene tal
//autor.
//c) Dado el título de un libro, mostrar el autor.
//d) Implemente una función que permita agregar un nuevo libro al final del archivo preservando la secuencia
//del Código.
//e) Realizar el préstamo de un libro dado su número de código.

void menu(FILE *archi);
void grabar(FILE *archi);
void informar(FILE *archi, int ingresado);
void datosAutor(FILE *archi, char ingresado2[40]);
void mostrarAutor(FILE *archi, char ingresado3[40]);
void ingresarAlfinal(FILE *archi, int coding);
void prestamo(FILE *archi, int ingresado4);

int main(){
	FILE *archi;
	grabar(archi);
	menu(archi);
}

void menu(FILE *archi){
	int opciones, codigo;
	char titulo[40], autor[40];
		printf("--------------------MENU---------------------\n\n");
	do{
		printf("\n");
		printf("\ningrese un numero segun la operacion que desee realizar, 0 para salir\n");
		printf("\n");
		printf("1. Ingresar codigo para conocer titulo y ejemplares en stock\n");
		printf("2. Ingresar un autor y mostrar sus libros registrado y cantidad de libros\n");
		printf("3. Ingresar un titulo de libro para conocer autor\n");
		printf("4. Agregar un libro al catalogo\n");
		printf("5. Realizar prestamo de un libro\n");
		printf("\n");
		scanf("%d",&opciones);
		switch(opciones){
			case 1:
				printf("ingrese el codigo\n");
				scanf("%d",&codigo);
				informar(archi,codigo);
				break;
			case 2:
				printf("ingrese el autor\n");
				while(getchar() != '\n');
				fgets(autor,40,stdin);
				datosAutor(archi, autor);
				break;
			case 3:
				printf("ingrese el titulo del libro\n");
				while(getchar() != '\n');
				fgets(titulo,40,stdin);
				mostrarAutor(archi,titulo);
				break;
			case 4:
				ingresarAlfinal(archi, codigo);
				break;
			case 5:
				printf("ingrese el codigo del libro para realizar el prestamo\n");
				scanf("%d",&codigo);
				prestamo(archi, codigo);
				break;
		}	
	}while(opciones != 0);
}

void grabar(FILE *archi){
	archi=fopen("TITULOS.dat","wb");
	if(archi != NULL){
		info aux;
		printf("ingrese el titulo del libro, FIN para terminar\n");
		fgets(aux.titulo,40,stdin);
		while(strcmp(aux.titulo, "FIN\n") != 0){		
			fseek(archi,0,SEEK_END);
			long tam=ftell(archi);
			int cod = (int)(tam/sizeof(info)+1);
			aux.codigo=cod;
			printf("codigo: %d\n",cod);
			printf("ingrese el autor del libro\n");
			fgets(aux.autor,40,stdin);
			printf("ingrese el stock\n");
			scanf("%d",&aux.stock);
			while(getchar() != '\n');
			fwrite(&aux,sizeof(info),1,archi);
			fclose(archi);
			printf("\n");
			printf("ingrese el titulo del libro\n");
			fgets(aux.titulo,40,stdin);
		}
	}else{
		printf("el archivo no se abrio correctamente\n");
	}
}

void informar(FILE *archi, int ingresado){
	archi=fopen("TITULOS.dat","rb");
	if(archi != NULL){
		info aux;
		fseek(archi,(ingresado-1) * sizeof(info),SEEK_SET);
		fread(&aux,sizeof(info),1,archi);
		printf("titulo del libro: %s",aux.titulo);
		printf("stock disponible: %d\n",aux.stock);
		fclose(archi);
	}else{
		printf("el archivo no se abrio correctamente\n");
	}
}

void datosAutor(FILE *archi, char ingresado2[40]){
	archi=fopen("TITULOS.dat","rb");
	int read;
	if(archi != NULL){
		int acum = 0;
		info aux;
		read=fread(&aux,sizeof(info),1,archi);
		while(read == 1){
			if(strcmp(aux.autor, ingresado2) == 0){
				printf("libro: %s",aux.titulo);
				printf("stock: %d\n",aux.stock);
				acum+=aux.stock;
			}
			read=fread(&aux,sizeof(info),1,archi);
		}
		printf("cantidad total de libros en stock del autor %s: %d",ingresado2,acum);
		fclose(archi);
	}else{
		printf("el archivo no se abrio correctamente\n");
	}
}

void mostrarAutor(FILE *archi, char ingresado3[40]){
	archi=fopen("TITULOS.dat","rb");
	int read, encontrado;
	encontrado = 0;
	if(archi != NULL){
		info aux;
		read=fread(&aux,sizeof(info),1,archi);
		while(read == 1 && encontrado == 0){
			if(strcmp(aux.titulo, ingresado3) == 0){
				printf("autor: %s",aux.autor);
				encontrado = 1;
			}else{
				read=fread(&aux,sizeof(info),1,archi);
			}
		}
		fclose(archi);
	}else{
		printf("el archivo no se abrio correctamente\n");
	}
}

void ingresarAlfinal(FILE *archi, int coding){
	archi=fopen("TITULOS.dat","ab+");
	if(archi != NULL){
		info aux, nuevo;
		printf("ingrese el codigo del libro\n");
		scanf("%d",&nuevo.codigo);
		while(getchar() != '\n');
		fseek(archi,-(long)sizeof(info),SEEK_END);
		fread(&aux,sizeof(info),1,archi);
		while(nuevo.codigo != aux.codigo+1){
			printf("codigo invalido, ingrese nuevamente\n");
			printf("ingrese el codigo del libro\n");
			scanf("%d",&nuevo.codigo);
			while(getchar() != '\n');
		}
		printf("ingrese el titulo del libro\n");
		fgets(nuevo.titulo,40,stdin);
		printf("ingrese el autor\n");
		fgets(nuevo.titulo,40,stdin);
		printf("ingrese el stock\n");
		scanf("%d",&nuevo.stock);
		while(getchar() != '\n');
		fseek(archi,0,SEEK_END);
		fwrite(&nuevo,sizeof(info),1,archi);
		fclose(archi);
	}else{
		printf("el archivo no se abrio correctamente\n");
	}
}

void prestamo(FILE *archi, int ingresado4){
	archi = fopen("TITULOS.dat", "rb+");
	if(archi != NULL){
		info aux;
		fseek(archi,(ingresado4-1)*sizeof(info),SEEK_SET);
		fread(&aux,sizeof(info),1,archi);
		aux.stock--;
		fseek(archi,-(long)sizeof(info),SEEK_CUR);
		fwrite(&aux,sizeof(info),1,archi);
		fclose(archi);
	}else{
		printf("el archivo no se abrio correctamente\n");
	}
}
