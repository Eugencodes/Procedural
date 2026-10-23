#include <stdio.h>
#include <string.h>
#define N 20

char *pal(char *p);
void palindromo(char *p, char *c);

int main(){
	char cadena[N], *c;
	char *p = cadena;
	fgets(cadena,N,stdin);
	cadena[strcspn(cadena, "\n")] = '\0';
	c = pal(p);
	palindromo(p,c);
}

char *pal(char *p){
	if(*p =='\0'){
		return p-1;
	}
	return pal(p+1);
}

void palindromo(char *p, char *c){
	if(p >= c){
		printf("es palindromo\n");
		return;
	}
	if(*p!=*c){
		printf("no es palindromo\n");
		return;
	}
	palindromo(p+1,c-1);
}
