#include <stdio.h>
#include <string.h>
#define N 4
#define M 3
typedef struct{
	char nombre[50];
	int cupomax;
}generos;


void carga(generos arreglo[N]){
	int i;
	for (i=0;i<N;i++){
		printf("Ingrese nombre del genero: \n");
		while(getchar != '\0');
		fgets(arreglo[i].nombre, 50, stdin);
		printf("Ingrese cupo disponible: \n");
		scanf("%d", &arreglo[i].cupomax);
		}
	return;
}

void cereo(int tabla[N][M]){
	int i, j;
	for (i=0;i<N;i++){
		for(j=0;j<M;j++){
			tabla[i][j]=0;
		}
	}
	return;
}

int buscar(char xgen[50], generos arreglo[N]){
	int i;
	i = 0;
	while ((i<N) &&(strcmp(xgen, arreglo[i].nombre) != 0)){
		i++;
	}
	return(i);
}

void altAs(generos arreglo[N], int tabla[N][M]){
	char xgen[50];
	int fun, p;
	printf("Ingrese genero: \n");
	fgets(xgen, 50, stdin);
	while (strcmp(xgen, "fin") != 0){
		printf("Ingrese numero de funcion: \n");
		scanf("%d", &fun);
		while(getchar() != '\n');
		p=buscar(xgen, arreglo);
		if (p<N){
			if (arreglo[p].cupomax > 0){
				arreglo[p].cupomax = arreglo[p].cupomax -1;
				tabla[p][fun-1]++;
			}
		}
		printf("Ingrese genero: \n");
		fgets(xgen, 50, stdin);
	}
	return;
}

void asistencia(int tabla[N][M], generos arreglo[N]){
	int i, j, max, min, aux1, aux2;
	max = 0;
	min = 9999;
	for (i=0;i<N;i++){
		max = 0;
		min = 9999;;
		for(j=0;j<M;j++){
			if (tabla[i][j] > max){
				max = tabla[i][j];
				aux1 = j+1;
			}else{
				if(tabla[i][j] < min){
					min = tabla[i][j];
					aux2 = j+1;
				} 
			}
		}
		printf("La funcion con mas asistencias del genero %s es la funcion %d \n",arreglo[i].nombre, aux1);
		printf("La funcion con menos asistencias del genero %s es la funcion %d \n",arreglo[i].nombre, aux2);
	}
	return;
}

void menorIns(int tabla[N][M], generos arreglo[N]){
	int i, j, acum, min, aux;
	min = 9999;
	for (i=0;i<N;i++){
		acum = 0;
		for (j=0;j<M;j++){
			acum = acum + tabla[i][j];	
		}
		if (acum < min){
			min = acum;
			aux = i;
		}
	}
	printf("El genero con menor cantidad de inscriptos es: %s  \n", arreglo[aux].nombre);
	return;
}

void cereo(int acums[N]){
	int i;
	for (i=0;i<N;i++){
		acums[i]=0;
	}
	return;
}

void calculoTotal(int tabla[N][M], int acums[N], int *total){
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			acums[i] = acums[i] + tabla[i][j];
		}
		*total = *total + acums[i];
	}
	return;
}

int main(){
	generos arreglo[N];
	int tabla[N][M], acums[N], total, i;
	total = 0;
	carga(arreglo);
	cereo(tabla);
	altAs(arreglo, tabla);
	asistencia(tabla, arreglo);
	menorIns(tabla, arreglo);
	cereo(acums);
	calculoTotal(tabla, acums, &total);
	for (i = 0; i < N; i++) {
  		   printf("Genero: %s - Total de asistentes: %d\n",
           arreglo[i].nombre,
           acums[i]);
       }
    printf("Total general de asistentes: %d\n", total);
	return 0;	
}
