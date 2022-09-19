#include <stdio.h>
#include <stdlib.h>
int tuttiAlternati(int seq[],int l);
int main(){
	printf("ciao sono un programma che verifica ricorsivamente se in un array tutti i numeri sono uno pari e uno positivo\n");
	int l;
	printf("lunghezza array\n");
	scanf("%d",&l);
	int interi[l];
	for(int i=0;i<l;i++){
		printf("inserisci numero\n");
		scanf("%d",&interi[i]);
	}
	if(tuttiAlternati(interi,l))
		printf("istanza positiva\n");
		else
			printf("istanza negativa, riprova\n");
}
int tuttiAlternati(int seq[],int l){
	int verificato;
	if(l<2)
		verificato=1;
		else
			verificato=((seq[0]>0&&seq[1]<0)||(seq[1]>0&&seq[0]<0))&&tuttiAlternati(seq+1,l-1);
			return verificato;
}