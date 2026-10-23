#include <stdio.h>
#define N 4
#define M 3

void cerear(int arreglo[N][M]){
	int i, j;
	for (i=0;i<N;i++){
		for (j=0;j<M;j++){
			arreglo[i][j]=0;
		}
	}
	return;
}

void carga(int arreglo[N][M]){
	int curso, turno, cant;
	printf("Ingrese curso: \n");
	scanf("%d", &curso);
	while (curso != 0){
		printf("Ingrese turno: \n");
		scanf("%d", &turno);
		printf("Ingrese cantidad de inscriptos: \n");
		scanf("%d", &cant);
		arreglo[curso-1][turno-1] = cant;
		printf("Ingrese curso: \n");
		scanf("%d", &curso);
	}
	return;
}

void total(int arreglo[N][M]){
	int i, j, acum;
	acum = 0;
	for (i=0;i<N;i++){
		for (j=0;j<M;j++){
			acum = acum + arreglo[i][j];
		}	
	}
	printf("Cantidad total absoluta de alumnos inscriptos en toda la oferta académica: %d \n", acum);
	return;
}

void focoDeCurso(int arreglo[M], int xcurso){
	int i,acum, max, aux;
	max=0;
	acum=0;
	for(i=0;i<M;i++){
		acum = acum + arreglo[i];
		if(arreglo[i] > max){
			max = arreglo[i];
			aux=i;
		}
	}
	printf("el turno con mayor cantidad de inscriptos en el curso %d es el turno %d con %d inscriptos\n",xcurso,aux+1, max);
	printf("el total de inscriptos en este curso entre todos los turnos es de %d alumnos\n",acum);
}

void focoTurno(int arreglo[N][M], int xturno){
	int i,acum,max,aux;
	max=0;
	acum=0;
	for(i=0;i<N;i++){
		acum = acum + arreglo[i][xturno-1];
		if(arreglo[i][xturno-1] > max){
			max = arreglo[i][xturno-1];
			aux=i;
		}
	}
	printf("el curso mas demandado en el turno %d es el curso %d con %d inscriptos\n",xturno,aux+1,max);
	printf("el total de inscriptos en todo el turno %d es de %d inscriptos\n",xturno,acum);
	return;
}
 
void mayorCurso(int arreglo[N][M], char cursos[N][50]){
	int i, j, max, acum, aux;
	max = -1;
	aux=0;
	for (i=0;i<N;i++){
		acum = 0;
		for (j=0;j<M;j++){
			acum = acum + arreglo[i][j];	
		}
		    if (acum > max){
		    max = acum;
		    aux = i;
		}
	}
	printf("El curso con mayor cantidad de inscriptos es el curso de %s", cursos[aux]);
	return;
}

void mayorTurno(int arreglo[N][M]){
	int i, j, max, acum, aux;
	max = 0;
	for (j=0;j<M;j++){
		acum = 0;
		for (i=0;i<N;i++){
			acum = acum + arreglo[i][j];	
		}
			if (acum > max){
		        max = acum;
		        aux = j;
	}
	}
	printf("El turno con mayor cantidad de inscriptos es el turno %d \n", aux+1);
	return;
}

int main(){
	int arreglo[N][M], xcurso, xturno;
	char cursos[N][50] = {
		"IA Generativa",
		"Administracion de Base de Datos\n",
		"Cableado de Datos\n",
		"Gestion Inteligente de APs\n"
	};
	cerear(arreglo);
	carga(arreglo);
	total(arreglo);
	printf("Ingrese un curso para conocer la cantidad de estudiantes: \n");
	scanf("%d", &xcurso);
	focoDeCurso(arreglo[xcurso-1], xcurso);
	printf("Ingrese un turno para conocer la cantidad de estudiantes: \n");
	scanf("%d", &xturno);
	focoTurno(arreglo, xturno);
	mayorCurso(arreglo, cursos);
	mayorTurno(arreglo);
}

