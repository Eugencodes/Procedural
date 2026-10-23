#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 150

typedef struct{
	int codigo;
	char nombre[50];
	float precioun;
	int stock;
} producto;

void cargaProd(producto arreglo[N]){
	int i;
	for(i=0;i<N;i++){
		arreglo[i].codigo = rand()%150+1;
		printf("codigo: %d\n", arreglo[i].codigo);
		printf("ingrese el nombre del producto:\n");
		fgets(arreglo[i].nombre,50,stdin); 
		printf("ingrese el precio unitario\n");
		scanf("%f",&arreglo[i].precioun);
		printf("ingrese el stock inicial\n");
		scanf("%d",&arreglo[i].stock);
		while(getchar() != '\n');
	}
	return;
}
int buscar(producto arreglo[N], int codigo){
	int i = 0;
	while((i<N) && (arreglo[i].codigo != codigo)){
		i++;
	}
	return(i);
}
void procesa(producto arreglo[N]){
	int i,codigo,p, unidades;
	float acum = 0;
	printf("ingrese el codigo del producto para procesar la venta\n");
	scanf("%d",&codigo);
	while(codigo != 0){
		printf("ingrese la cantidad de unidades vendidas\n");
		scanf("%d",&unidades);
		p=buscar(arreglo,codigo);
		if(p<N){
			arreglo[p].stock = arreglo[p].stock - unidades;
			acum = acum + (arreglo[p].precioun * unidades);
		}
		printf("ingrese el codigo del producto para procesar la venta\n");
		scanf("%d",&codigo);
	}
	printf("Importe total recaudado por las ventas: %.1f\n", acum);
	return; 
}

void ordenar(producto arreglo[N]){
	int i, j, min;
	producto aux;
	for(i=0;i<N-1;i++){
		min = i;
		for (j=i+1;j<N;j++){
			if(arreglo[j].stock < arreglo[min].stock){
				min = j;
			}
		}
		aux = arreglo[i];
		arreglo[i] = arreglo[min];
		arreglo[min] = aux;
	}
	for (i=0;i<N;i++){
		printf("\n\nproducto: %s\n",arreglo[i].nombre);
		printf("codigo: %d\n",arreglo[i].codigo);
		printf("stock: %d\n",arreglo[i].stock);
		printf("precio unitario: %.1f\n",arreglo[i].precioun);
	}
	return;
}

void informar(producto arreglo[N]){
	int i, cont;
	cont = 0;
	while(arreglo[i].stock == 0){
			cont = cont +1;
			i++;
		}
	printf("Cantidad de productos con stock = 0: %d\n", cont);
	return;
}

void total(producto arreglo[N]){
	int i;
	float acum;
	acum = 0;
	for (i=0;i<N;i++){
		acum = acum + arreglo[i].stock * arreglo[i].precioun;
	}
	printf("monto total invertido en mercaderia actualmente disponible: %.1f\n", acum);
	return;
}

int main(){
	producto arreglo[N];
	cargaProd(arreglo);
	procesa(arreglo);
	ordenar (arreglo);
	informar(arreglo);
	total(arreglo);
	return 0;
}
