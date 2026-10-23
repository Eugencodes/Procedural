#include <stdio.h>

typedef struct{
	float precio;
	int cant;
}productos;

void carga(productos arreglo[], int N, int i);
void maximo(productos arreglo[], int N, int i, float *max);
int subarre(productos arreglo[], productos subarreglo[], int N, int i, int j, float *prom, float acumulador);
float minmax(productos subarreglo[], int j, int i, float *max, float min);






int main(){
	int N, j;
	float prom, max, min, acumulador;
	acumulador=0;
	max=0;
	min=9999;
	j=0;
	printf("ingrese la cantidad de productos comercializados\n");
	scanf("%d",&N);
	productos arreglo[N], subarreglo[N];
	carga(arreglo,N,0);
	maximo(arreglo,N,0,&max);
	j= subarre(arreglo,subarreglo,0,N,j,&prom,acumulador);
	min=minmax(subarreglo,j,0,&max,min);
	printf("el precio maximo registrado es %.2f\n",max);
	printf("el precio minimo registrado es %.2f\n",min);
}

void carga(productos arreglo[], int N, int i){
	if(i<N){
		printf("ingrese el stock del producto %d\n",i+1);
		scanf("%d",&arreglo[i].cant);
		printf("ingrese el precio del producto %d\n",i+1);
		scanf("%f",&arreglo[i].precio);
		carga(arreglo, N, i+1);
	}
	return;
}

void maximo(productos arreglo[], int N, int i, float *max){
	if(i<N){
		if(arreglo[i].precio > *max){
			*max = arreglo[i].precio;
		}
		maximo(arreglo, N, i+1, max);
		if(arreglo[i].precio == *max){
			printf("el producto %d coincide con el maximo precio registrado, y tiene %d de stock disponible\n",i+1,arreglo[i].cant);
		}
	}
	return;
}


int subarre(productos arreglo[],productos subarreglo[],int i,int N, int j, float *prom, float acumulador){
	if(i<N){
		acumulador = acumulador + arreglo[i].precio;
		j = subarre(arreglo,subarreglo,i+1,N,j,prom,acumulador);
		if(arreglo[i].precio >= *prom){
			subarreglo[j] = arreglo[i];
			j++;
		}
	}else{
		*prom = acumulador/N;
		}
	return j;
}

float minmax(productos subarreglo[], int j, int i, float *max, float min){
	if(i<j){
		if(subarreglo[i].precio < min){
			min = subarreglo[i].precio;
		}
		if(subarreglo[i].precio > *max){
			*max = subarreglo[i].precio;
		}
		return minmax(subarreglo,j,i+1,max,min);
	}
	return min;
}








