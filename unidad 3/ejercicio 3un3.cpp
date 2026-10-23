#include <stdio.h>
#include <string.h>
#define M 10
#define N 6

typedef struct{
	char nombre[50];
	float precioxton;
}producto;

void cargaArre(producto arr[M]){
	int i;
	for(i=0;i<M;i++){
		printf("ingrese el nombre del producto\n");
		fgets(arr[i].nombre,50,stdin);
		printf("ingrese el precio por tonelada\n");
		scanf("%f",&arr[i].precioxton);
		while(getchar() != '\n');
	}
	return;
}

void cerear(float tabla[N][M]){
	int i, j;
	for (i=0;i<N;i++){
		for (j=0;j<M;j++){
			tabla[i][j] = 0;
		}
	}
	return;
}

void cargaTabla(float tabla[N][M]){
	int zona, codigo;
	float ton;
	printf("Ingrese numero de zona: \n");
	scanf("%d", &zona);
	while (zona != 0){
		printf("Ingrese codigo: \n");
		scanf("%d", &codigo);
		printf("Ingrese la cantidad de toneladas: \n");
		scanf("%f", &ton);
		tabla[zona-1][codigo-1] = ton;
		printf("Ingrese numero de zona: \n");
		scanf("%d", &zona);
	}
	return;
}

float totalZona(float tabla[M]){
	int i;
	float acum;
	acum = 0;
	for(i=0;i<M;i++){
		acum = acum + tabla[i];
	}
	return(acum);
}

void totalPorProd(float tabla[N][M], producto arr[M]){
	int i, j;
	float acum, calc;
	for(j=0;j<M;j++){
		acum = 0;
		for(i=0;i<N;i++){
			acum = acum + tabla[i][j];
		}
		calc = acum * arr[j].precioxton;
		printf("importe total exportado de %s: %.1f\n", arr[j].nombre,calc);
	}
	return;	
}

int infMin(float tabla[N][M]){
	int i,j, auxmin;
	float min;
	min=9999;
	for (i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(tabla[i][j] < min){
				min=tabla[i][j];
				auxmin = j+1; 
			}
		}
	}
	return(auxmin);
}

int infMax(float tabla[N][M]){
	int i,j, auxmax;
	float max;
	max=0;
	for (i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(tabla[i][j] > max){
				max=tabla[i][j];
				auxmax = j+1; 
			}
		}
	}
	return(auxmax);
}

int main(){
	producto arr[M];
	int xzona, max, min;
	float tabla[N][M], total;
	cargaArre(arr);
	cerear(tabla);
	cargaTabla(tabla);
	printf("Ingrese zona de exportación: \n");
	scanf("%d", &xzona);
	total = totalZona(tabla[xzona-1]);
	printf("La cantidad total de toneladas de la zona %d es: %.1f\n",xzona, total);
	totalPorProd(tabla, arr);
	min = infMin(tabla);
	max = infMax(tabla);
	printf("Codigo del producto  menos exportado: %d\n", min);
	printf("Codigo del producto  mas exportado: %d\n", max);
	return 0;
}
