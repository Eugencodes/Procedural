#include <stdio.h>
#include <string.h>
#define N 2

typedef struct{
	int codigo;
	char nombre[30];
	int disponibles;
	int inscriptos[N];
}categorias;



void ingreso(FILE *archi);
void masInscriptos(FILE *archi, char xcat[30]);
void modificar(FILE *archi, char xcat[30], int xyear);
float promedio(FILE *archi);
void mayorPromedio(FILE *archi);
void actualizar(FILE *archi);

int main(){
	int ingresado, xyear;
	char xcat[30];
	FILE *archi;
	archi=fopen("Categorias.dat","wb");
	if(archi != NULL){
		ingreso(archi);
		fclose(archi);
	}else{
		printf("ERROR: el archivo no se abrió correctamente, intentelo de nuevo\n");
	}
	printf("ingrese un nombre de categoría para determinar el año con mayor cantidad de inscriptos\n");
	fgets(xcat,30,stdin);
	masInscriptos(archi,xcat);
	printf("ingrese un año (1 a 20) si desea modificar la cantidad de inscriptos de dicho año (0 si no desea modificar nada)\n");
	scanf("%d",&xyear);
	while(getchar() != '\n');
	if(xyear != 0){
		printf("ingrese nombre de la categoria a modificar\n");
		fgets(xcat,30,stdin);
		modificar(archi,xcat,xyear);
	}
	mayorPromedio(archi);
	actualizar(archi);
}

void ingreso(FILE *archi){
	categorias fulbo;
	int i;
	printf("ingrese el nombre de la categoria para almacenar sus datos, 'fin' para terminar\n");
	fgets(fulbo.nombre,30,stdin);
	while(strcmp(fulbo.nombre, "fin\n") != 0 && strcmp(fulbo.nombre, "FIN\n") != 0){
		printf("ingrese codigo de categoria\n");
		scanf("%d",&fulbo.codigo);
		printf("ingrese cantidad de clubes disponibles\n");
		scanf("%d",&fulbo.disponibles);
		for(i=0;i<N;i++){
			printf("ingrese la cantidad de inscriptos de la categoria %s en el year %d\n",fulbo.nombre,i+2007);
			scanf("%d",&fulbo.inscriptos[i]);
		}
		while(getchar() != '\n');
		fwrite(&fulbo,sizeof(categorias),1,archi);
		printf("ingrese el nombre de la categoria para almacenar sus datos, 'fin' para terminar\n");
		fgets(fulbo.nombre,30,stdin);
	}
}

void masInscriptos(FILE *archi, char xcat[30]){
	archi=fopen("Categorias.dat", "rb");
	if(archi != NULL){
		categorias fulbo;
		int encontrado, read, max, aux, i;
		encontrado = 0;
		max = 0;
		read = fread(&fulbo,sizeof(categorias),1,archi);
		while(read == 1 && encontrado == 0){
			if(strcmp(xcat, fulbo.nombre) == 0){
				encontrado = 1;
				for(i=0;i<N;i++){
					if(fulbo.inscriptos[i] > max){
						max = fulbo.inscriptos[i];
						aux = i+1;
					}
				}
			}
			read=fread(&fulbo,sizeof(categorias),1,archi);
		}
		if(encontrado == 1){
			printf("la maxima cantidad de inscriptos registrados en la categoría %s, es %d inscriptos en el año %d\n",xcat,max,aux);
		}else{
			printf("el codigo ingresado no fue encontrado\n");
		}
		fclose(archi);
	}	
}

void modificar(FILE *archi, char xcat[30], int xyear){
	archi=fopen("Categorias.dat", "rb+");
	if(archi != NULL){
		categorias fulbo;
		int read, encontrado;
		encontrado = 0;
		read=fread(&fulbo,sizeof(categorias),1,archi);
		while(read == 1 && encontrado == 0){
			if(strcmp(xcat,fulbo.nombre) == 0){
				encontrado = 1;
				printf("ingrese cantidad de clubes para sobreescribir el dato anterior del año %d\n",xyear);
				scanf("%d",&fulbo.inscriptos[xyear-1]);
				fseek(archi,-(long)sizeof(categorias),SEEK_CUR);
				fwrite(&fulbo,sizeof(categorias),1,archi);
			}
		}
		fclose(archi);
	}else{
		printf("ERROR: el archivo no se abrio correctamente\n");
	}
}

float promedio(FILE *archi){
	int read, cont; 
	float acum;
	acum = 0;
	cont = 0;  
	categorias fulbo;
	read = fread(&fulbo, sizeof(categorias), 1, archi);
	while(read == 1){
		acum += fulbo.disponibles;
		cont += 1;
		read = fread(&fulbo, sizeof(categorias), 1, archi);
	}
	return acum/cont;
}

void mayorPromedio(FILE *archi){
	archi=fopen("Categorias.dat","rb");
	if(archi != NULL){
		float prom = promedio(archi);
		int read;
		categorias fulbo;
		fseek(archi,0,SEEK_SET);
		read=fread(&fulbo,sizeof(categorias),1,archi);
		while(read == 1){
			if(fulbo.disponibles > prom){
				printf("la categoria %s supera al promedio total de inscriptos\n",fulbo.nombre);
			}
			read=fread(&fulbo,sizeof(categorias),1,archi);
		}
		fclose(archi);
	}else{
		printf("ERROR: el archivo no se abrio correctamente\n");
	}
}

void actualizar(FILE *archi){
	archi=fopen("Categorias.dat","r+b");
	if(archi != NULL){
		int read, encontrado;
		categorias fulbo;
		encontrado = 0;
		read=fread(&fulbo,sizeof(categorias),1,archi);
		while(read == 1 && encontrado == 0){
			if(strcmp(fulbo.nombre, "NACIONAL B\n") == 0 || strcmp(fulbo.nombre, "Nacional B") == 0){
				encontrado = 1;
				printf("ingrese la cantidad de clubes disponibles en la categoria nacional B para actualizar la información\n");
				scanf("%d",&fulbo.disponibles);	
	    		fseek(archi, -(long)sizeof(categorias), SEEK_CUR);
   				fwrite(&fulbo, sizeof(categorias), 1, archi);
			}
			read=fread(&fulbo,sizeof(categorias),1,archi);	
		}	
		fclose(archi);	
	}else{
	printf("ERROR: el archivo no se abrio correctamente\n");	
	}
}



























