#include <stdio.h>
#define N 20

void carga(int arreglo[]){
	int i;
	for(i=0;i<N;i++){
		printf("ingrese el peso %d\n",i+1);
		scanf("%d", &arreglo[i]);
	}
}

int buscar(int arreglo[]){
	int i = 0;
	while(arreglo[i] != 0 && i<N){
		i++;
	}
	return(i);
}
int main(){
	int arreglo[N];
	carga(arreglo);
	
}

