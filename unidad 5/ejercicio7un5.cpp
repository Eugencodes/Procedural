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
void eliminarinsc(info curso[N], int dning);
void mostrarcurso(info curso[N], int dning2, int i, puntero aux);
void intercambiar(info curso[N]);

int main(){
	info curso[N];
	int dning,dning2, i;
	i=0;
	crearNodo(curso);
	carga(curso);
	procesa(curso);
	printf("ingrese DNI para eliminar inscripcion\n");
	scanf("%d",&dning);
	eliminarinsc(curso, dning);
	printf("ingrese DNI para conocer cursos inscriptos\n");
	scanf("%d",&dning2);
	mostrarcurso(curso,dning2,i,curso[0].cab);
	intercambiar(curso);
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

void eliminarinsc(info cursos[N], int dning){
	int i;
	puntero anterior, p;
	for(i=0;i<N;i++){
		if ((cursos[i].cab != NULL) && (cursos[i].cab->dni == dning)){ // Caso 1: Es la cabeza
			p = cursos[i].cab;
			cursos[i].cab = cursos[i].cab->sig;
			free (p); // Liberación física
		}else{
			p = cursos[i].cab;
			anterior = cursos[i].cab;
			while (p != NULL && p->dni != dning) {
				anterior = p; // Resguardo del anterior
				p = p->sig;
			}
			if (p != NULL){ // Caso 2: Se encontró adentro o al final
				anterior->sig = p->sig; // Salto del nodo p
				free (p) ;
			}
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

void intercambiar (info curso[N]){
	
}
