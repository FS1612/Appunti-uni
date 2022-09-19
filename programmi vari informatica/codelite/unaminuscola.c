#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int verificaStringa(char*stringa);
int main(int argc, char **argv) {
	char stringa[20];
    printf("sono un programma che verifica ricorsivamente se esiste 1 minuscola in una stringa\n");
	printf("inserisci una bella stringa\n");
	fgets(stringa,20,stdin);
	stringa[strlen(stringa)-1]='\0';
	if(verificaStringa(stringa))
		printf("nella stringa esiste almeno un acarattere minuscolo\n");
		else
			printf("istanza non verificata\n");
}
int verificaStringa(char*stringa){
	int verificato;
	if(strlen(stringa)==0)
		verificato=0;
		else
			verificato=(stringa[0]>'a'&&stringa[0]<'z')||(verificaStringa(stringa+1));
			return verificato;
}