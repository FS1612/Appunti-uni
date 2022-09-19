#include<stdio.h>
#include<stdlib.h>
int quadrupletrepari(int seq[],int lunghezza);
int main(){
	printf("sono un programma che conta ricorsivamente quante triple di interi contengono almeno 3 pari\n\n");
	int l;
	printf("quanti interi deve contenere il tuo array:\t");
	scanf("%d",&l);
	printf("\n");
	int interi[l];
	for(int i=0;i<l;i++){
		printf("inserisci numeri\t");
		scanf("%d",&interi[i]);
		printf("\n");
	}
	printf("la sequenza contiene %d triple che verificano la condizione\n",quadrupletrepari(interi,l));
}
int quadrupletrepari(int seq[],int lunghezza){
	int vero;
	vero=0;
	if((((seq[0]%2==0)&&(seq[1]%2==0)&&(seq[2]%2==0)))||
			((seq[0]%2==0)&&(seq[1]%2==0)&&(seq[3]%2==0))||
			((seq[1]%2==0)&&(seq[2]%2==0)&&(seq[3]%2==0))||
			((seq[0]%2==0)&&(seq[1]%2==0)&&(seq[3]%2==0))||
			((seq[0]%2==0)&&(seq[2]%2==0)&&(seq[3]%2==0)))
		vero=1;
	else
				vero = 1+ quadrupletrepari( seq+1, lunghezza-1);
			return vero;
}