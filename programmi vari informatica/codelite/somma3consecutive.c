#include <stdlib.h>
#include <stdio.h>
int verificaSequenza(int s[],int l);
int main(int argc, char **argv) {
	int lunghezza;
    printf("sono un programma che verifica ricorsivamente se esiste 1 minuscola in una stringa\n");
	printf("lunghezza array?\n");
	scanf("%d",&lunghezza);
	int interi[lunghezza];
	for(int i=0;i<lunghezza;i++){
		printf("inserisci numero\t");
		scanf("%d",&interi[i]);
	}
	if(verificaSequenza(interi,lunghezza))
		printf("istanza verificata\n");
		else
			printf("istanza non verificata\n");
}
int verificaSequenza(int s[],int l){
	int verificato;
	if(l<3)
		verificato=1;
		else
			verificato=((s[0]==s[1]+s[2])||(s[1]==s[0]+s[2])||(s[2]==s[0]+s[1]))&&(verificaSequenza(s+1,l-1));
			return verificato;
}