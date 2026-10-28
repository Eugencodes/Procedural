#include <stdio.h>
#include <string.h>

typedef struct{
	char condicion;
	char nombre[30];
	int registro;
}alumno;

void grabar(FILE *archi);
void mostrar(FILE *archi);
void comparar(FILE *archi, FILE *archi2);
void tercerArchi(FILE *archi, FILE *archi2, FILE *archi3);
int mayorAprobados(FILE *archi, FILE *archi2, int &cont1);

int main(){
	FILE *archi;
	FILE *archi2;
	FILE *archi3;
	archi = fopen("alumnosPP.dat", "wb");
	int cont2, cont1;
	cont1 = 0;
	if(archi != NULL){
		printf("alumnos de programacion procedural\n");
		printf("\n");
		grabar(archi);
		fclose(archi);
	}else{
		printf("el archivo no se abrio correctamente\n");
	}
	archi2 = fopen("alumnosAL.dat", "wb");
	if(archi2 != NULL){
		printf("\n");
		printf("alumnos de algebra lineal\n");
		printf("\n");
		grabar(archi2);
		fclose(archi2);
	}else{
		printf("el archivo no se abrio correctamente\n");
	}
	archi = fopen("alumnosPP.dat", "rb");
	if(archi != NULL){
		printf("listado con los datos de los alumnos de programacion procedural:\n");
		mostrar(archi);
		fclose(archi);
	}
	archi2 = fopen("alumnosAL.dat","rb");
	if(archi2 != NULL){
		printf("listado con los datos de los alumnos de algebra lineal:\n");
		mostrar(archi2);
		fclose(archi2);
	}
	comparar(archi,archi2);
	tercerArchi(archi,archi2,archi3);
	cont2 = mayorAprobados(archi,archi2, cont1);
	if(cont1 == cont2){
		printf("ambas materias tienen la misma cantidad de aprobados\n");
		printf("\n");
	}else if(cont1 > cont2){
		printf("programacion procedural tuvo mas aprobados que algebra\n");
		printf("\n");
	}else{
		printf("algebra tuvo mas aprobados que programacion procedural\n");
		printf("\n");
	}
	archi3 = fopen("nuevoArchivo.dat", "rb");
	if(archi3 != NULL){
		printf("listado con los datos de los alumnos que aprobaron ambas materias:\n");
		mostrar(archi3);
		fclose(archi3);
	}
}

void grabar(FILE *archi){
	alumno aux;
	printf("ingrese numero de registro, 0 para finalizar\n");
	scanf("%d",&aux.registro);
	while(getchar() != '\n');
	while(aux.registro != 0){
		printf("ingrese nombre del alumno\n");
		fgets(aux.nombre,30,stdin);
		printf("ingrese condicion del alumno\n");
		scanf("%c",&aux.condicion);
		fwrite(&aux,sizeof(alumno),1,archi);
		printf("ingrese numero de registro, 0 para finalizar\n");
		scanf("%d",&aux.registro);
		while(getchar() != '\n');
	}		
}

void mostrar(FILE *archi){
	alumno aux;
	if(archi != NULL){
		printf("\n");
		printf("\n");
		while(fread(&aux,sizeof(alumno),1,archi) == 1){ //fread recupera los datos del archivo, mientras que fwrite los graba en el
			printf("nombre: %s",aux.nombre);
			printf("registro: %d\n",aux.registro);
			printf("condicion: %c\n",aux.condicion);
			printf("\n");
		}
	}else{
		printf("el archivo no se abrio correctamente");
	}
	fclose(archi);
}

void comparar(FILE *archi, FILE *archi2){
	archi=fopen("alumnosPP.dat", "rb");
	archi2=fopen("alumnosAL.dat", "rb");
	if(archi != NULL && archi2 != NULL){
		alumno aux1,aux2;
		int read1,read2;
		read1=fread(&aux1,sizeof(alumno),1,archi);
		read2=fread(&aux2,sizeof(alumno),1,archi2);
		printf("listado de alumnos registrados en ambas materias:\n");
		printf("\n");
		while(read1 == 1 && read2 == 1){
			if(aux1.registro == aux2.registro){
				printf("Nombre de alumno: %s\n",aux1.nombre);
				read1=fread(&aux1,sizeof(alumno),1,archi);
				read2=fread(&aux2,sizeof(alumno),1,archi2);
			}else if(aux1.registro < aux2.registro){
				read1=fread(&aux1,sizeof(alumno),1,archi);
			}else{
				read2=fread(&aux2,sizeof(alumno),1,archi2);
			}
		}
		fclose(archi);
		fclose(archi2);
  	}else{
  		printf("uno o mas archivos no se abrieron correctamente\n");
	}
	printf("\n");
}

void tercerArchi(FILE *archi, FILE *archi2, FILE *archi3){
	archi = fopen("alumnosPP.dat", "rb");
	archi2 = fopen("alumnosAL.dat", "rb");
	archi3 = fopen("nuevoArchivo.dat", "wb");
	if(archi != NULL && archi2 != NULL && archi3 != NULL){
		alumno aux1,aux2, reg;
		int read1,read2;
		read1=fread(&aux1,sizeof(alumno),1,archi);
		read2=fread(&aux2,sizeof(alumno),1,archi2);
		while(read1 == 1 && read2 == 1){
			if(aux1.registro == aux2.registro){
				if(aux1.condicion == 'A' && aux2.condicion == 'A'){
					reg = aux1;
					fwrite(&reg,sizeof(alumno),1,archi3);
				}
				read1=fread(&aux1,sizeof(alumno),1,archi);
				read2=fread(&aux2,sizeof(alumno),1,archi2);
				}else if(aux1.registro < aux2.registro){
					read1=fread(&aux1,sizeof(alumno),1,archi);
				}else{
					read2=fread(&aux2,sizeof(alumno),1,archi2);
				}
		}
	}else{
		printf("uno o mas archivos no se abrieron correctamente\n");
	}
	fclose(archi);
	fclose(archi2);
	fclose(archi3);
}

int mayorAprobados(FILE *archi, FILE *archi2, int &cont1){
	int cont2 = 0;
	archi=fopen("alumnosPP.dat", "rb");
	archi2=fopen("alumnosAL.dat", "rb");
	if(archi != NULL && archi2 != NULL){
		alumno aux,aux2;
		int read1,read2;
		read1=fread(&aux,sizeof(alumno),1,archi);
		read2=fread(&aux2,sizeof(alumno),1,archi2);
		while(read1 == 1){
			if(aux.condicion == 'A'){
				cont1+=1;
			}
			read1=fread(&aux,sizeof(alumno),1,archi);
		}
		while(read2 == 1){
			if(aux2.condicion == 'A'){
				cont2+=1;
			}
			read2=fread(&aux2,sizeof(alumno),1,archi2);
		}
		fclose(archi);
		fclose(archi2);
	}else{
		printf("uno o mas archivos no se abrieron correctamente\n");
	}
	return cont2;
}
