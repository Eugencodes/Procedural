//a) Pasaje de parametros: es la forma en que se envia informacion a una funcion.
//   - Por valor: se copia el dato en un parametro local de la funcion. Los cambios
//     que haga la funcion mueren al terminar, el original no se modifica.
//     Ej: 'cont2' en promedio(), por eso hay que devolverlo con return.
//   - Por referencia (en C, con punteros): se envia la direccion de memoria de la
//     variable. La funcion accede al original y lo modifica de forma permanente.
//     Ej: 'contador' y 'acumulador', por eso se pasan con & y se usan con *.
//   - Los arreglos en C siempre se pasan por referencia: el nombre del arreglo ya
//     es la direccion de su primer elemento.
#include <stdio.h>
#define N 25

typedef struct{
	float peso;
	float altura;
}operario;

void carga(operario arreglo[N], int i);
void contar(operario arreglo[N],int *contador, int i);
int promedio(operario arreglo[N],float *acumulador,int i,int cont2);

int main(){
	operario arreglo[N];
	int cont2,contador;
	float acumulador;
	acumulador = 0;
	contador = 0;
	carga(arreglo,0);
	contar(arreglo,&contador,0);
	printf("la cantidad de operarios con un peso mayor a 60kg es de %d operarios\n",contador);
	cont2 = promedio(arreglo,&acumulador,0,0);
	printf("el peso promedio de los operarios con altura superior a 1.5 metros es de: %.2fkg\n",acumulador/cont2);
	return 0;
}

void carga(operario arreglo[N],int i){
	if(i<N){
		printf("ingrese el peso del operador\n");
		scanf("%f",&arreglo[i].peso);
		printf("ingrese la altura del operador\n");
		scanf("%f",&arreglo[i].altura);
		carga(arreglo,i+1);
	}
	return;
}

void contar(operario arreglo[N],int *contador, int i){
	if(i<N){
		if(arreglo[i].peso >60){
			*contador = *contador + 1;
		}
		contar(arreglo,contador,i+1);
	}
	return;
}

int promedio(operario arreglo[N],float *acumulador,int i,int cont2){
	if(i<N){
		if(arreglo[i].altura > 1.5){
			cont2=cont2+1;
			*acumulador = *acumulador + arreglo[i].peso;
		}
		return promedio(arreglo,acumulador,i+1,cont2);
	}
	return(cont2);
}
