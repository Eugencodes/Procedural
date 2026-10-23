#include <stdio.h>
#include <stdlib.h>

void crearArr(int *&arreglo, int N);
void cargaArr(int *&arreglo, int N, int i);
void productoEsc(int *&arreglo, int *&arreglo2, int N, int *producto);
void crearPares(int *&arreglo, int *&subarre, int N);
void cargarSub(int *&arreglo, int *&subarre, int N);

int main(){
	int *arreglo = NULL, *arreglo2 = NULL, *subarre = NULL, N, i, producto, j, *puntero;
	i=0;
	producto = 0;
	printf("ingrese el tamaño de los arreglos\n");
	scanf("%d",&N);
	crearArr(arreglo,N);
	crearArr(arreglo2,N);
	cargaArr(arreglo,N,i);
	cargaArr(arreglo2,N,i);
	productoEsc(arreglo,arreglo2,N,&producto);
	printf("producto escalar: %d\n",producto);
	crearPares(arreglo,subarre,N);
	cargarSub(arreglo,subarre,N);
	return 0;
}

void crearArr(int *&arreglo, int N){
	arreglo = (int *) malloc(N * sizeof(int));
	return;
}

void cargaArr(int *&arreglo, int N, int i){
	if(i<N){
		printf("Ingrese valor %d de %d\n",i+1,N);
		scanf("%d",&arreglo[i]);
		cargaArr(arreglo,N,i+1);
	}
	return;
}

void productoEsc(int *&arreglo, int *&arreglo2, int N, int *producto){
	int i;
	for(i=0;i<N;i++){
		*producto += arreglo[i] * arreglo2[i];
	}
	return;
}

void crearPares(int *&arreglo, int *&subarre, int N){
	int cont = 0;
	for(int i=0;i<N;i++){
		if(arreglo[i] % 2 == 0){
			cont += 1;
		}
	}
	crearArr(subarre,cont);
}

void cargarSub(int *&arreglo, int *&subarre, int N){
	int i, j;
	j=0;
	for(i=0;i<N;i++){
		if(arreglo[i]%2 == 0){
			subarre[j] = arreglo[i];
			j++;
		}
	}
	return;
}


