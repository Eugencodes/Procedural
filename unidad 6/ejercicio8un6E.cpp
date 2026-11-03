#include <stdio.h>
#include <string.h>

typedef struct{
	int codigo;
	char titulo[30];
	char director[30];
	int espectadores;
}pelicula;

void ingreso(FILE *archi);
void mostrar(FILE *archi);
void cant_esp(FILE *archi, int ingresado);
void director(FILE *archi, char ing[30]);
void crearArchivo2(FILE *archi, FILE *archi2);
void masEspectadores(FILE *archi2);
void bytesArchi(FILE *archi, FILE *archi2);

int main(){
	FILE *archi = NULL, *archi2 = NULL;
	int ingresado;
	char ing[30];
	ingreso(archi);
	mostrar(archi);
	printf("ingrese una cantidad de espectadores para modificar la pelicula con codigo 5\n");
	scanf("%d",&ingresado);
	cant_esp(archi,ingresado);
	printf("ingrese un titulo de pelicula para conocer su director\n");
	fgets(ing,30,stdin);
	director(archi,ing);
	crearArchivo2(archi,archi2);
	masEspectadores(archi2);
	bytesArchi(archi,archi2);
}

void ingreso(FILE *archi){
	archi=fopen("CINE.dat","wb");
	if(archi != NULL){
		pelicula ingresos;
		printf("ingrese el titulo de la pelicula, 'fin' para terminar\n");
		fgets(ingresos.titulo,30,stdin);
		while(strcmp(ingresos.titulo, "fin\n") != 0){
			fseek(archi,0,SEEK_END);
			long tam = ftell(archi);
			int cod = (int) (tam/sizeof(pelicula)+1);
			ingresos.codigo=cod;
			printf("ingrese el director de la pelicula\n");
			fgets(ingresos.director,30,stdin);
			printf("ingrese la cantidad de espectadores de la pelicula\n");
			scanf("%d",&ingresos.espectadores);
			while(getchar() != '\n');
			fwrite(&ingresos,sizeof(pelicula),1,archi);
			printf("ingrese el titulo de la pelicula, 'fin' para terminar\n");
			fgets(ingresos.titulo,30,stdin);
		}
		fclose(archi);
	}else{
		printf("\nERROR: el archivo no se abrio correctamente\n");
	}
}

void mostrar(FILE *archi){
	archi = fopen("CINE.dat", "rb");
	if(archi != NULL){
		pelicula ingresos;
		int read = fread(&ingresos,sizeof(pelicula),1,archi);
		while(read == 1){
			printf("Codigo: %d\n",ingresos.codigo);
			printf("Titulo: %s",ingresos.titulo);
			printf("Director %s",ingresos.director);
			printf("cantidad de espectadores: %d\n",ingresos.espectadores);
			read = fread(&ingresos,sizeof(pelicula),1,archi);
		}
		fclose(archi);
	}else{
		printf("\nERROR: el archivo no se abrio correctamente\n");
	}
}

void cant_esp(FILE *archi, int ingresado){ 
	archi = fopen("CINE.dat","r+b");
	if(archi != NULL){
		pelicula ingresos;
		fseek(archi,0,SEEK_SET);
		fseek(archi, (5-1)*sizeof(pelicula),SEEK_CUR);
		fread(&ingresos,sizeof(pelicula),1,archi);
		ingresos.espectadores = ingresado;
		fseek(archi, -(long)sizeof(ingresos),SEEK_CUR);
		fwrite(&ingresos,sizeof(pelicula),1,archi);
		fclose(archi);
	}else{
		printf("\nERROR: el archivo no se abrio correctamente\n");
	}
}

void director(FILE *archi, char ing[30]){
	archi = fopen("CINE.dat","rb");
	if(archi != NULL){
		int read, encontrado;
		encontrado = 0;
		pelicula ingresos;
		read = fread(&ingresos,sizeof(pelicula),1,archi);
		while(read == 1 && encontrado == 0){
			if(strcmp(ingresos.titulo, ing) == 0){
				encontrado = 1;
				printf("Director de la pelicula: %s",ingresos.director);
			} 
			read = fread(&ingresos,sizeof(pelicula),1,archi);
		}
		fclose(archi);
	}else{
		printf("\nERROR: el archivo no se abrio correctamente\n");
	}
}

void crearArchivo2(FILE *archi, FILE *archi2){
	archi=fopen("CINE.dat","rb");
	archi2=fopen("exitos.dat","wb");
	if(archi != NULL && archi2 != NULL){
		pelicula ingresos;
		int read = fread(&ingresos,sizeof(pelicula),1,archi);
		while(read == 1){
			if(ingresos.espectadores > 100000){
				fwrite(&ingresos,sizeof(pelicula),1,archi2);
			}
			read = fread(&ingresos,sizeof(pelicula),1,archi);
		}
		fclose(archi);
		fclose(archi2);
	}else{
		printf("\nERROR: uno o mas archivos no se abrieron correctamente\n");
	}
}

void masEspectadores(FILE *archi2){
	archi2=fopen("exitos.dat","rb");
	if(archi2 != NULL){
		int max, read;
		pelicula ingresos;
		read=fread(&ingresos,sizeof(pelicula),1,archi2);
		max = 0;
		char aux[30];
		while(read == 1){
			if(ingresos.espectadores > max){
				max = ingresos.espectadores;
				strcpy(aux,ingresos.titulo);
			}
			read=fread(&ingresos,sizeof(pelicula),1,archi2);
		}
		fclose(archi2);
		printf("Titulo de la pelicula con mas espectadores: %s",aux);
	}else{
		printf("\nERROR: uno o mas archivos no se abrieron correctamente\n");
	}
}

void bytesArchi(FILE *archi, FILE *archi2){
	archi = fopen("CINE.dat","rb");
	archi2 = fopen("exitos.dat","rb");
	if(archi != NULL && archi2 != NULL){
		fseek(archi,0,SEEK_END);
		fseek(archi2,0,SEEK_END);
		long tam1 = ftell(archi);
		long tam2 = ftell(archi2);
		printf("tamano en bytes del archivo CINES.dat: %ld\n",tam1);
		printf("tamano en bytes del archivo exitos.dat: %ld\n",tam2);
		fclose(archi);
		fclose(archi2);
	}else{
		printf("\nERROR: uno o mas archivos no se abrieron correctamente\n");
	}
}
