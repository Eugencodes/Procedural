#include <stdio.h>
#define N 3
void carga(int arreglo[], int i){
	if(i<N){
		printf("Ingrese la edad del competidor %d\n",i+1);
		scanf("%d",&arreglo[i]);
		carga(arreglo,i+1);
	}	
}

void mostrar(int arreglo[],int i){
	if(i<N){
		mostrar(arreglo, i+1);
		printf("edad del competidor %d: %d\n",i+1,arreglo[i]);
	}
	return;
}

void PosNeg(int arreglo[], int i, int *cantpos,int &cantneg){
	if (i<N){
		if (arreglo[i] > 0){
			*cantpos = *cantpos +1;
		}else{
			cantneg = cantneg +1;
		}
		PosNeg(arreglo, i+1, cantpos, cantneg);
	}
	return;
}	

int main(){
	int arreglo[N], cantpos, cantneg;
	cantpos = 0;
	cantneg = 0;
	carga(arreglo,0);
	mostrar(arreglo,0);
	PosNeg(arreglo,0, &cantpos, cantneg);
	printf("Cantidad de positivos: %d\n", cantpos);
	printf("Cantidad de negativos: %d\n", cantneg);
	return 0;
}
