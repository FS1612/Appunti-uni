#include <stdio.h>
#include <stdlib.h>
int quadrupleTrepari(int seq[],int l);
int main(){
	printf("ciao sono un programma che calcola quante quadruple consecutive aventi 3 pari  ci sono in un array\n ");
	int lunghezza;
	printf("quanti interi desideri nel tuo array?\t");
	scanf("%d",&lunghezza);
	int interi[lunghezza];
	for(int i =0; i<lunghezza;i++){
		printf("inserisci in numero in posizione %d\t",i);
		scanf("%d",&interi[i]);
	}
	printf("il tuo array contiene %d quadruple che soddisfano la richiesta\n",quadrupleTrepari(interi,lunghezza));
}
int quadrupleTrepari(int seq[],int l){
	int totale;
	if(l<=3)
		totale=0;
		else
			totale=((seq[0]%2==0&&seq[1]%2==0&&seq[2]%2==0&&seq[3]%2!=0)||(seq[0]%2==0&&seq[1]%2==0&&seq[3]%2==0&&seq[2]%2!=0)||(seq[0]%2==0&&seq[2]%2==0&&seq[3]%2==0&&seq[1]%2!=0)||(seq[3]%2==0&&seq[1]%2==0&&seq[2]%2==0&&seq[0]%2!=0))+quadrupleTrepari(seq+1,l-1);
			return totale;
}