#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nombre[50];
	char carrera[50];
}alumno;

struct nodo2{
	alumno datos;
	struct nodo2 *sig;
};
typedef struct nodo2 *puntero2;

typedef struct{
	int id;
	puntero2 cab;
}libros;

struct nodo1{
	libros datos;
	struct nodo1 *sig;
};
typedef struct nodo1 *puntero1;

void crear(puntero1 &cab);
void insertarCola(puntero1 &cab);
void insertarLibros(puntero1 &cab);
void busqueda(puntero1 xp, int id);
void insertarCola(puntero2 &cab);
void insertarAl(puntero1 &cab);


int main(){
	puntero1 cab = NULL;
	crear(cab);
	insertarLibros(cab);
	insertarAl(cab);
}

void crear(puntero1 &cab){
	cab = NULL;
}

void insertarLibros(puntero1 &cab){
	puntero1 n;
	int id;
	printf("Ingrese id de libro: (0 para finalizar) \n");
	scanf("%d", &id);
	while(id != 0){
		n = (puntero1)malloc(sizeof(nodo1));
		n->datos.id = id;
		n->datos.cab = NULL;
		n->sig = cab;
		cab = n;
		printf("Ingrese id de libro: (0 para finalizar) \n");
		scanf("%d", &id);	
	}
}

void busqueda(puntero1 xp, int id){
	if (xp != NULL){
		if(xp->datos.id == id){
			insertarCola(xp->datos.cab);
		}else{
			busqueda(xp->sig, id);
		}
	}else{
		printf("Libro no encontrado\n");
	}
}

void insertarCola(puntero2 &cab){
	puntero2 nuevo, p;
	nuevo = (puntero2)malloc(sizeof(nodo2));
	printf("Ingrese nombre del alumno: \n");
	fgets(nuevo->datos.nombre, 50, stdin);
	printf("Ingrese carrera del alumno: \n");
	fgets(nuevo->datos.carrera, 50, stdin);
	nuevo->sig = NULL;
	if(cab == NULL){
		cab = nuevo;
	}else{
		p = cab;
		while(p->sig != NULL){
			p = p->sig;
		}
		p->sig = nuevo;
	}
}

void insertarAl(puntero1 &cab){
	int id;
	printf("Ingrese id del libro: (0 para terminar) \n");
	scanf("%d", &id);
	while(getchar()!='\n');
	while(id != 0){
		busqueda(cab, id);
		printf("Ingrese id del libro: (0 para terminar) \n");
		scanf("%d", &id);
		while(getchar()!='\n');
	}
}
