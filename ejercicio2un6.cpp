#include <stdio.h>
#include <string.h>
#define N 3

typedef struct{
	int legajo;
	char nombre[15];
	float notaf;
}datos;

void grabar(FILE *archi, datos alumno);
void promedio(FILE *archi, datos alumno);

int main(){
	FILE *archi;
	datos alumno;
	archi=fopen("calificaciones.txt", "w");
	if(archi != NULL){
		grabar(archi,alumno);
		fclose(archi);
	}
	promedio(archi,alumno);
}

void grabar(FILE *archi, datos alumno){
	int i;
	for(i=0;i<N;i++){
		printf("ingrese nombre de alumno, 'fin' para terminar\n");
		gets(alumno.nombre);
		printf("ingrese numero de legajo\n");
		scanf("%d",&alumno.legajo);
		printf("ingrese nota final\n");
		scanf("%f",&alumno.notaf);
		fprintf(archi, "legajo: %d\nnombre: %s\nnota final: %.2f",alumno.legajo,alumno.nombre,alumno.notaf);
	}
}

void promedio(FILE *archi, datos alumno){
	archi = fopen("calificaciones.txt","r");
	alumno aux;
	float acum, prom;
	acum = 0;
	while(!feof(archi)){
		if (fscanf(archi,"%d","%s","%f",&alumno.legajo,alumno.nombre,&alumno.notaf == 3){
		acum+=alumno.notaf;
		printf
		printf
		printf
		}
	}
	prom=acum/3;
	printf("promedio general de las notas: %.2f",prom);
}
