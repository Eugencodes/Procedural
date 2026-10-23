#include <stdio.h>
#include <string.h>
#include <ctype.h>

void copy(char frase[60]){
	char proc[10];
	strncpy(proc,&frase[13],10);
	proc[10] = '\0';
	puts(proc);
	return;
}

void auditoria(char frase[60]){
	int i, cont;
	cont = 0;
	i=0;
	while(frase[i] != '\0'){
		if((frase[i] == 'a') || (frase[i] == 'A') || (frase[i] == 'e') || (frase[i] == 'E') || (frase[i] == 'i') || (frase[i] == 'I') || (frase[i] == 'o') || (frase[i] == 'O') || (frase[i] == 'u') || (frase[i] == 'U')){
			cont = cont+1;
		}
		i++;
	}
	printf("la frase tiene %d vocales\n",cont);
	return;
}

void mayusculas(char frase[60]){
	int i = 0;
	while(frase[i] != '\0'){
		frase[i]=toupper(frase[i]);
		i++;
	}
	return;
}

void generarOpuesto(char frase[60]){
	int inicio = 0;
	int fin = strlen(frase) - 1;
	while (inicio < fin) {
   	 	char aux = frase[inicio];
    	frase[inicio] = frase[fin];
   		frase[fin] = aux;
   		inicio++;
   		fin--;
	}
	puts(frase);
	return;
}


int main(){
	char frase[60], proc[10];
	fgets(frase,60,stdin);
	// fgets() limita la cantidad de caracteres que puede leer al tamaño
    // indicado, evitando que se escriban datos fuera del límite del arreglo
    // y previniendo así un Buffer Overflow.
	frase[27] = '6';
	puts(frase);
	copy(frase);
	auditoria(frase);
	mayusculas(frase);
	generarOpuesto(frase);
}
