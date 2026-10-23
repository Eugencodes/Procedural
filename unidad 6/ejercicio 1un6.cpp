#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void grabar(FILE *archi);
void leer(FILE *archi);
void agregar(FILE *archi);


int main(){
	FILE *archi;
	archi = fopen("bitacora.txt", "w");
	if(archi != NULL){
		grabar(archi);
		fclose(archi);
	}else{
		printf("el archivo no se encontró o no se abrió correctamente\n");
	}
	leer(archi);
	agregar(archi);	
}

void grabar(FILE *archi){
	char texto[200];
	printf("ingrese texto para agregar al archivo\n");
	gets(texto);
	while((strcmp(texto, "fin") != 0)){
		fputs(texto, archi);
		printf("ingrese texto para agregar al archivo\n");
		gets(texto);
	}
}

void leer(FILE *archi){
	archi=fopen("bitacora.txt", "r");
	char texto[250];
	if(archi != NULL){
		while(fgets(texto,sizeof(texto),*&archi) != NULL){
			printf("\ntexto ingresado:");
			printf("%s",&texto);
		}
		fclose(archi);
	}else{
		printf("el archivo no se abrio correctamente o no se encontro\n");
	}
}

void agregar(FILE *archi){
	archi=fopen("bitacora.txt", "a"); //"a" se diferencia de "w" porque con write se sobrescriben los datos 
	char texto[200];                //pero en append se abre el archivo para agregar informacion al final
	gets(texto);
	if(archi != NULL){
		while((strcmp(texto, "fin") != 0)){
			printf("ingrese texto para agregar al archivo, 'fin' para finalizar\n");
			fputs(texto, archi);
			gets(texto);	
		}
	}
}












