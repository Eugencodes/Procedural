#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10

struct nodo{
	int dni;
	struct nodo *sig;
};
typedef struct nodo *puntero;

typedef struct{
	char titulo[40];
	puntero cab;
}info;

void crearNodo(info curso[N]);
void carga(info curso[N]);
void procesa(info curso[N]);
void eliminarinscRec(info cursos[N], int dning, int i, puntero &aux);
void mostrarcurso(info curso[N], int dning2, int i, puntero aux);
void intercambiar(puntero &cab);

int main(){
	info curso[N];
	puntero aux;
	int dning,dning2, i;
	i=0;
	crearNodo(curso);
	carga(curso);
	procesa(curso);
	printf("ingrese DNI para eliminar inscripcion\n");
	scanf("%d",&dning);
	eliminarinscRec(curso,dning,0,curso[0].cab);
	printf("ingrese DNI para conocer cursos inscriptos\n");
	scanf("%d",&dning2);
	mostrarcurso(curso,dning2,i,curso[0].cab);
	intercambiar(curso[6].cab);
}

void crearNodo(info curso[N]){
	int i;
	for(i=0;i<N;i++){
		curso[i].cab=NULL;
	}
}

void carga(info curso[N]){
	int i;
	for(i=0;i<N;i++){
		printf("ingrese el titulo de curso con id %d\n",i+1);
		fgets(curso[i].titulo,40,stdin);
	}	
	return;
}	

void procesa(info curso[N]){
	int dni, cur;
	puntero nuevo;
	printf("ingrese dni, 0 para finalizar\n");
	scanf("%d",&dni);
	while(dni != 0){
		printf("ingrese curso\n");
		scanf("%d",&cur);
		nuevo=(puntero)malloc(sizeof(struct nodo));
		nuevo->dni=dni;
		nuevo->sig=curso[cur-1].cab;
		curso[cur-1].cab=nuevo;
		printf("dsaopdjas");	
	}	
}

void eliminarinscRec(info cursos[N], int dning, int i, puntero &aux){
	if(i<N){
		if(aux != NULL){
			if(dning == aux->dni){
				puntero aux1 = aux;
				aux = aux->sig;	
				free(aux1);		
			}else{
				eliminarinscRec(cursos,dning,i,aux->sig);		
			}
		}else if(i+1<N){	
    		eliminarinscRec(cursos, dning, i+1, cursos[i+1].cab);
		}
	}
}

void mostrarcurso(info curso[N], int dning2, int i, puntero aux){
	if(i<N){
		if(aux->dni == dning2 && aux != NULL){
			printf("el alumno con dni %d esta inscripto al curso %d",dning2,i+1);
		}else if(aux != NULL && aux->dni != dning2){
			mostrarcurso(curso,dning2,i,aux->sig);
		}
	}else{
		mostrarcurso(curso,dning2,i+1,curso[i+1].cab);	
	}
}

void intercambiar (puntero &cab){
	puntero aux1,aux2;
	if(cab!=NULL && cab->sig != NULL && cab->sig->sig != NULL){
		aux1=cab->sig;
		aux2=aux1->sig;
		aux1->sig = aux2->sig;
		aux2->sig=aux1;
		cab->sig=aux2;
	}
}
