#include <stdio.h>
#define N 8
#define M 4

void carga(int arreglo[N][M]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("ingrese la nota %d del alumno %d\n",j+1,i+1);
			scanf("%d",&arreglo[i][j]);
			if(arreglo[i][j] > 10){
				printf("la nota ingresada no es valida, reinicie la ejecución del programa\n");
			}
		}
	}
	return;
}


void informarPromedio(int arreglo[N][M]){
	int i,j;
	float prom[N], acum[N];
	for(i=0;i<N;i++){
		acum[i] = 0;
		for(j=0;j<M;j++){
			acum[i] = acum[i] + arreglo[i][j];
		}
	}
	for(i=0;i<N;i++){
		prom[i] = acum[i] / M;
		printf("el promedio del alumno %d es de %.2f\n",i+1,prom[i]);
		if(prom[i]<4){
			printf("el alumno %d se encuentra en estado libre\n",i+1);
        }else if(prom[i] > 7){
        	printf("el alumno %d ha promocionado\n",i+1);
		}else{
			printf("el alumno %d ha regularizado\n",i+1);
		}
	}
	return;
}

void promedioComision(int arreglo[N][M]){
	int i,j,auxmax,auxmin;
	float prom[N], acum[N], max, min;
	for(j=0;j<M;j++){
		acum[j] = 0;
		for(i=0;i<N;i++){
			acum[j] = acum[j] + arreglo[i][j];
		}
	}
	max=0;
	min=11;
	for(j=0;j<M;j++){
		prom[j] = acum[j] / N;
		printf("el promedio del examen %d es de %.2f\n",j+1,prom[j]);
		if(prom[j]<min){
		    min = prom[j];
			auxmin=j;
		}
		if(prom[j]>max){
			max = prom[j];
			auxmax = j;
		}
	}
	printf("el examen con mayor promedio general fue el examen %d, con un promedio de %.2f\n",auxmax+1,prom[auxmax]);
	printf("el examen con menor promedio general fue el examen %d, con un promedio de %.2f\n",auxmin+1,prom[auxmin]);
	return;
}

void maxmin(int arreglo[N][M]){
	int i,j, max, min, auxima, auxjma, auximin, auxjmin;
	max = 0;
	min = 11;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(arreglo[i][j] < min){
				min = arreglo[i][j];
				auximin = i+1;
				auxjmin = j+1;
			}
			if(arreglo[i][j] > max){
				max = arreglo[i][j];
				auxima = i+1;
				auxjma = j+1;
			}
		}
	}
	printf("la nota mas baja registrada fue %d, en el parcial %d realizado por el alumno %d\n"),min,auxjmin,auximin;
	printf("la nota mas alta registrada fue %d, en el parcial %d realizado por el alumno %d\n"),max,auxjma,auxima;
	return;
}

int alulibres(int arreglo[N][M]){
	int i,j, cont;
	float prom[N], acum[N];
	for(i=0;i<N;i++){
		acum[i] = 0;
		for(j=0;j<M;j++){
			acum[i] = acum[i] + arreglo[i][j];
		}
	}
	for(i=0;i<N;i++){
		prom[i] = acum[i] / M;
		if(prom[i]<4){
            cont = cont + 1;
        }
    }
    return(cont);
}



int main(){
	int arreglo[N][M], cant;
	carga(arreglo);
	informarPromedio(arreglo);
	promedioComision(arreglo);
	maxmin(arreglo);
	cant = alulibres(arreglo);
	printf("hay %d alumnos libres",cant);
}
