#include <stdio.h>
#include <string.h>
#define N 50 

typedef struct{
	char nombre[50];
	char sexo;
	int dni;
	int edad;
	int cod;
}info;

void carga(info arreglo[N]){
	int i, cod;
	for (i=0;i<N;i++){
		printf("ingrese nombre: \n");
		fgets(arreglo[i].nombre,50,stdin);
		printf("ingrese sexo (F o M)\n");
		scanf(" %c", &arreglo[i].sexo);
		printf("ingrese dni\n");
		scanf("%d", &arreglo[i].dni);
		printf("ingrese edad\n");
		scanf("%d", &arreglo[i].edad);
		printf("ingrese codigo de localizacion del 1 al 19\n");
		scanf("%d", &cod);
		while (cod < 1 || cod > 19){
			scanf("%d", &cod);
		}
		arreglo[i].cod = cod;
		getchar();
	}
	return;
}

void postFem(info arreglo[N]){
	int i,cont;
	cont=0;
	for(i=0;i<N;i++){
		if((arreglo[i].sexo == 'f' || arreglo[i].sexo == 'F') && (arreglo[i].edad < 30)){
			cont = cont+1;
		}
	}
	printf("la cantidad de postulantes mujeres menores de 30 es: %d postulantes\n",cont);
	return;
}

void edadPromedio(info arreglo[N]){
	int i, acum, cont;
	float prom;
	acum=0;
	cont=0;
	for(i=0;i<N;i++){
		if((arreglo[i].sexo == 'm')||(arreglo[i].sexo == 'M')){
			cont = cont + 1;
			acum = acum + arreglo[i].edad;
		}	
	}
	prom = acum/cont;
	printf("el promedio de edad de los postulantes masculinos es de %.2f anios\n",prom);
	return;
}


void localidadCa(info arreglo[N]){
	int i;
	printf("listado de postulantes de la localidad 14:\n");
	for(i=0;i<N;i++){
		if(arreglo[i].cod == 14){

			
			puts(arreglo[i].nombre);
			printf("Dni: %d\n",arreglo[i].dni);
		}
	}
	return;
}

void veterano(info arreglo[N]){
	int i, max, aux;
	max=0;
	for(i=0;i<N;i++){
		if(arreglo[i].edad > max){
			max = arreglo[i].edad;
			aux = i;
		}
	}
	printf("el postulante de mayor edad es: ");
	puts(arreglo[aux].nombre);
	printf("y su dni es: %d\n",arreglo[aux].dni);
	return;
}

//strcpy(nombre, arreglo[i].nombre) para copiar una cadena en otra variable 

void ordenar(info arreglo[N]){
	int i, k,
	cota;
	info aux;
	k=1;
	cota=N-1;
	while(k!=-1){
		k=-1;
		for(i=0;i<cota;i++){
			if(arreglo[i].edad > arreglo[i+1].edad){
				aux = arreglo[i];
				arreglo[i] = arreglo[i+1];
				arreglo[i+1] = aux;
				k=i;
			}
		}
		cota = k;
	}
	return;
}

void mostrarOrdenado(info arreglo[N]){
	int i;
	for(i=0;i<N;i++){
		printf("\npostulante %d:\n",i+1);
		printf("\nnombre:");
		puts(arreglo[i].nombre);
		printf("DNI: %d\n",arreglo[i].dni);
		printf("sexo: %c\n",arreglo[i].sexo);
		printf("edad: %d anios\n",arreglo[i].edad);
		printf("localidad: %d\n",arreglo[i].cod);
	}
	return;
}
int main(){
	info arreglo[N];
	carga(arreglo);
	postFem(arreglo);
	edadPromedio(arreglo);
	localidadCa(arreglo);
	veterano(arreglo);
	ordenar(arreglo);
	mostrarOrdenado(arreglo);
}
