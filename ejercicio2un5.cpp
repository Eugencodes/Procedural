#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int dni;
	char tipo;
	char estado[10];
	int edad;
}t_socio;

void crearArre(t_socio *&arreglo, int N);
void carga(t_socio *&arreglo, int N);
void filtrar(t_socio *&arreglo, int *&subarre, int N, int cont);
void generarsub(t_socio *&arreglo, int *&subarre, int N, int i, int *j);

int main(){
	t_socio *arreglo = NULL;
	int *subarre = NULL, i, N, j, cont;
	cont = 0;
	j=0;
	i=0;
	printf("ingrese cantidad de socios\n");
	scanf("%d",&N);
	crearArre(arreglo,N);
	carga(arreglo,N);
	filtrar(arreglo,subarre,N, cont);
	generarsub(arreglo,subarre,N,i,&j);
	return 0;
}

void crearArre(t_socio *&arreglo, int N){
	arreglo = (t_socio*) malloc (N*sizeof(t_socio));
	return;
}

void carga(t_socio *&arreglo, int N){
	int i;
	for(i=0;i<N;i++){
		printf("ingrese edad del socio\n");
		scanf("%d",&arreglo[i].edad);
		while(getchar() != '\n');		
		printf("ingrese estado del socio\n");
		fgets(arreglo[i].estado,10,stdin);
		printf("ingrese tipo del socio\n");
		scanf("%c",&arreglo[i].tipo);
		while(getchar() != '\n');
		printf("ingrese dni del socio\n");
		scanf("%d",&arreglo[i].dni);
	}
	return;
}

void filtrar(t_socio *&arreglo, int *&subarre, int N, int cont){
	int i;
	cont = 0;
	for(i=0;0<N;i++){
		if((arreglo[i].tipo == 'a' || arreglo[i].tipo == 'A') && (arreglo[i].edad > 40)){
			cont += 1;
		}
	}
		subarre = (int*) malloc (cont*sizeof(int));
}

void generarsub(t_socio *&arreglo, int *&subarre, int N, int i, int *j){
	if(i<N){
		if((arreglo[i].tipo == 'a' || arreglo[i].tipo == 'A') && (arreglo[i].edad > 40)){
			subarre[*j] = arreglo[i].dni;
			(*j)++;
		}
		generarsub(arreglo,subarre,N,i+1,j);
	}
	return;
}

