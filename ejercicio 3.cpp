#include <stdio.h>
#define N 4

void carga(int arreglo[N][N]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
		    printf("ingrese unidades vendidas en el trimestre %d de la sucursal %d\n",i+1,j+1);
		    scanf("%d",&arreglo[i][j]);
	}
	}
}

void recorrer(int arreglo[N][N]){
	int i,j;
	printf("ingrese el trimestre para conocer las ventas por sucursal\n");
	scanf("%d",&i);
	if(i<=N){
	    for(j=0;j<N;j++){
		    printf("Unidades vendidas de la sucursal %d en el trimestre %d: %d \n",j+1, i, arreglo[i-1][j]);
	    }
    }else{
    	printf("el trimestre ingresado no es valido\n");
	}
	return;
}

void rendimiento(int arreglo[N][N], int sub[N]){
	int i,j;
	for(i=0;i<N;i++){
		sub[i] = 0;
	}
	for(i=0;i<N;i++){
	    for(j=0;j<N;j++){
		    sub[i] = sub[i] + arreglo[i][j];
	}	
    }
return;
}


void sumatoria(int arreglo[N][N]){
	int i,j, aux;
	for(j=0;j<N;j++){
		aux = 0;
	    for(i=0;i<N;i++){
		    aux = aux + arreglo[i][j];
	}	
	    printf("el total vendido de la sucursal %d es: %d\n",j+1,aux);
    }
return;
}

float promedio(int arreglo[N][N]){
	int i, acum;
	acum = 0;
	for(i=0;i<N;i++){
		acum = acum + arreglo[i][i];
	}
	return(acum/N);
}

int umbral(int arreglo[N][N], int umbr){
	int i, j, cont;
	cont = 0;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(arreglo[i][j] > umbr){
				cont = cont + 1;
			}
		}
	}
	return(cont);
}








int main(){
	int arreglo[N][N],sub[N],umbr, cant;
	float prom;
	carga(arreglo);
	recorrer(arreglo);
	rendimiento(arreglo,sub);
	sumatoria(arreglo);
	prom = promedio(arreglo);
	printf("ingrese el valor umbral:\n");
	scanf("%d",&umbr);
	cant = umbral(arreglo,umbr);
	printf("%d celdas superaron el valor umbral %d\n",cant,umbr);
	return 0;
}
