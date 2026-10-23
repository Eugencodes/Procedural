#include <stdio.h>
#include <string.h>
#define N 180

typedef struct{
	int id;
	char puesto[50];
	char dedicacion[50];
	float sueldo;
}oferta;

void carga(oferta ofertas[N]){
	int i, contador;
	for(i=0;i<N;i++){
		printf("ingrese id:\n");
		scanf("%d",&ofertas[i].id);
		while(getchar() != '\n');
		printf("ingrese el nombre del puesto: \n");
		fgets(ofertas[i].puesto,50,stdin);
		printf("ingrese la dedicacion\n");
		fgets(ofertas[i].dedicacion,50,stdin);
		printf("ingrese el sueldo propuesto:\n");
		scanf("%f",&ofertas[i].sueldo);
		while(ofertas[i].sueldo < 0){
			printf("el valor de sueldo ingresado no es valido, vuelva a ingresarlo\n");
			scanf("%f",&ofertas[i].sueldo);
		}
		if((ofertas[i].sueldo < 800000) && (ofertas[i].dedicacion == "full time")){
			contador = contador + 1;
		}
	}
	return;
}

int string(oferta ofertas[N]){
	int contador = 0;
	int i;
	for(i=0;i<N;i++){
		if(strcmp(ofertas[i].dedicacion, "full time\n") == 0 && (ofertas[i].sueldo <800000)){
			contador = contador + 1;
		}
	}
	return (contador);
}

void mostrarString(oferta ofertas[N],char nombre[50]){
	int i;
	printf("las siguientes ofertas corresponden al puesto %s\n",nombre);
	for(i=0;i<N;i++){
		if(strcmp(ofertas[i].puesto, nombre)==0){
			printf("\noferta %d:\n",i+1);
			printf("su dedicacion es: %s\n",ofertas[i].dedicacion);
			printf("y su sueldo es: %.1f\n",ofertas[i].sueldo);
		}
	}
}


int main(){
	oferta ofertas[N];
	int p;
	char nombre[50];
	carga(ofertas);
	p = string(ofertas);
	printf("%d ofertas son de full time con un sueldo propuesto menor a 800000\n",p);
	printf("ingrese un puesto para conocer las ofertas coincidentes: \n");
	while(getchar() != '\n');
	fgets(nombre,50,stdin);
	mostrarString(ofertas, nombre);
}
