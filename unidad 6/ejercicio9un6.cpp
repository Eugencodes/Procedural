#include <stdio.h>
#include <string.h>

typedef struct{
	int dni;
	float sueldo;
	char empleado[30];
	char empresa[30];
}datos;

void grabar(FILE *archi);
void corteControl(FILE *archi);
void nuevoArchi(FILE *archi, FILE *archi2, char ingresado[30]);

int main(){
	FILE *archi = NULL, *archi2 = NULL;
	char ingresado[30];
	archi=fopen("EMPLEADOS.dat","wb");
	if(archi != NULL){
		grabar(archi);
		fclose(archi);
	}else{
		printf("ERROR: el archivo no se abrio correctametente\n");
	}
	archi = fopen("EMPLEADOS.dat","r+b");
	if(archi != NULL){
		corteControl(archi);
		fclose(archi);
	}else{
		printf("ERROR: el archivo no se abrio correctametente\n");
	}
	archi = fopen("EMPLEADOS.dat","rb");
	archi2=fopen("EMPLEADOSnuevo.dat","wb");
	if(archi != NULL && archi2 != NULL){
		printf("\ningrese un nombre de empresa para eliminarla del archivo\n");
		fgets(ingresado,30,stdin);
		nuevoArchi(archi,archi2,ingresado);
		fclose(archi2);
		fclose(archi);
	}else{
		printf("ERROR: el archivo no se abrio correctamente\n");
	}
}

void grabar(FILE *archi){
	datos emp;
	printf("ingrese el nombre de la empresa, 'fin' para terminar\n");
	fgets(emp.empresa,30,stdin);
	while(strcmp(emp.empresa, "fin\n") != 0){
		printf("ingrese el nombre del empleado\n");
		fgets(emp.empleado,30,stdin);
		printf("ingrese su DNI\n");
		scanf("%d",&emp.dni);
		while(getchar() != '\n');
		printf("ingrese su sueldo\n");
		scanf("%f",&emp.sueldo);
		while(getchar() != '\n');
		fwrite(&emp,sizeof(datos),1,archi);
		printf("ingrese el nombre de la empresa, 'fin' para terminar\n");
		fgets(emp.empresa,30,stdin);
	}
}

void corteControl(FILE *archi){
    datos emp;
    float acum1, acum2;
    acum1 = 0;
    acum2 = 0;
    char aux[30];
    int read = fread(&emp, sizeof(datos), 1, archi);
    if(read == 1){
        strcpy(aux, emp.empresa);
        printf("Empresa: %s", aux);
        while(read == 1){
            if(strcmp(emp.empresa, aux) != 0){
                printf("Total a pagar por la empresa %s: %.2f\n", aux, acum1);
                acum1 = 0;
                strcpy(aux, emp.empresa);
                printf("Empresa: %s", emp.empresa);
            }
            printf("\nNombre del empleado: %s", emp.empleado);
            printf("\nDNI: %d", emp.dni);
            printf("\nSueldo a pagar: %.2f\n", emp.sueldo);
            acum1 += emp.sueldo;
            acum2 += emp.sueldo;
            read = fread(&emp, sizeof(datos), 1, archi);
        }
        printf("Total a pagar por la empresa %s: %.2f\n", aux, acum1);
        printf("Total a pagar entre todas las empresas: %.2f\n", acum2);
    }
}

void nuevoArchi(FILE *archi, FILE *archi2, char ingresado[30]){
	datos emp;
	int read = fread(&emp,sizeof(datos),1,archi);
	while(read == 1){
		if(strcmp(emp.empresa,ingresado) != 0){
			fwrite(&emp,sizeof(datos),1,archi2);
		}
		read = fread(&emp,sizeof(datos),1,archi);
	}
}
