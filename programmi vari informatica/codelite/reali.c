#include <stdlib.h>
#include <stdio.h>
typedef struct Reale{
	int reale;
	int decimale;
}REALE;
typedef struct nodo{
	REALE r;
	struct nodo*next;
}NODO;
void ordina(NODO*head);
void scambia(NODO*nodo1,NODO*nodo2);
NODO* cancellazioneTesta(NODO* head) ;
NODO*eliminaCoda(NODO*head);
NODO*inserisciCoda(NODO*head);
NODO*inserisciTesta(NODO*head);
void visualizzaNodo(NODO*head);
void visualizzaReale(REALE*r);
void leggiReale(REALE*r);
int main(){
	NODO*head=malloc(sizeof(NODO)); //*inizializzo la lista con un nodo fittizio
	head->next=NULL;//* il campo next del nodo fittizio deve essere inizializzato a null
	int richiesta =-1; //*inizializzo richiesta a valore non significativo
	while(richiesta!=0){
		printf("ciao sono un programma che gestisce i numeri reali\n");
		printf("come posso aiutarti?\n");
		printf("1->inserisci numero in coda\n");
		printf("2->inserisci numero in testa\n");
		printf("3->visualizza lista numeri\n");
		printf("4->cancella primo\n");
		printf("5->cancella ultimo\n");
		printf("6->ordina\n");
		printf("0->esci dal programma\n");
		scanf("%d",&richiesta);
		if(richiesta ==1){
			head =inserisciCoda(head);
			}
			else if(richiesta==2){
				head=inserisciTesta(head);
				}
				 else if(richiesta ==3){
					visualizzaNodo(head);
					}
					else if(richiesta==5){
						head=eliminaCoda(head);
					}
						else if(richiesta==4){
							head=cancellazioneTesta(head);
						}
						else if(richiesta==6){
							ordina(head);
						}
							else  if(richiesta!=0){
							printf("riprova\n");
						}
						else{
							printf("bella per te\n");
						}
	}
}
void leggiReale(REALE*r){
	printf("inserisci parte reale e parte decimale del numero\n");
	printf("parte reale:\t");
	scanf("%d",&r->reale);
	printf("\n");
	printf("parte decimale:\t");
	scanf("%d",&r->decimale);
}
NODO*inserisciCoda(NODO*head){
NODO *nuovonodo=malloc(sizeof(NODO));
	nuovonodo->next=NULL;
	leggiReale(&(nuovonodo->r));
	if(head==NULL){
		head=nuovonodo;
		}
		else{
			NODO*nodo=head;
			while(nodo->next!=NULL){
				nodo=nodo->next;
			}
			nodo->next=nuovonodo;
		}
		return head;
		}
NODO*inserisciTesta(NODO*head){
	NODO * nuovonodo=malloc(sizeof(NODO));
 leggiReale(&(nuovonodo->r));
 nuovonodo->next=head->next;//*collegamento nodo tra la testa e il primo nodo
 head->next=nuovonodo;
 return head;
}
void visualizzaReale(REALE*r){
	printf("ecco il tuo numero %d , %d\n",r->reale,r->decimale );
}
void visualizzaNodo(NODO*head){
	NODO*nodo=malloc(sizeof(nodo));
	nodo=head->next;//*salta il primo nono perche è fittizio
	if(nodo==NULL)
		printf("la lista e' vuota\n");
		else{
			while(nodo!=NULL){
				visualizzaReale(&(nodo->r));
				nodo=nodo->next;
			}
		}
}
NODO* cancellazioneTesta(NODO* head) {
	NODO *temp;					// di appoggio
	
	/* se lista non è vuota devi cancellare */
	if(head->next!=NULL){
		temp = head->next; //devo ricordare l'indirizzo del nodo da cancellare per deallocarlo
		head->next=temp->next;
		free(temp);
		printf("Cancellazione effettuata!\n\n");
	}							
	else
		printf("Niente da cancellare!\n\n");
		return head;
}
NODO*eliminaCoda(NODO*head){
	NODO*primo;
	primo=head->next;
	if(primo==NULL)
		printf("lista vuota\n");
		else{
			if(primo->next==NULL){//* 1 nodo
				free(primo);
				primo=NULL;
				printf("lista vuota\n");
			}
			else{//* 2 nodi
				NODO*corrente;
				NODO*suc;
				corrente=primo;
				suc=primo->next;
				while(suc->next!=NULL){
					suc=suc->next;
					corrente=corrente->next;
				}
				free(suc);
				corrente->next=NULL;
			}
		}
		return head;
}
void scambia(NODO*nodo1,NODO*nodo2){
	REALE temp;
	temp=nodo1->r;
	nodo1->r=nodo2->r;
	nodo2->r=temp;
}
void ordina(NODO*head){
	NODO*primo;
	NODO*suc;
	primo =head->next;
	NODO*minimo;
	if(primo==NULL)
	printf("nulla da ordinare\n");
	else{
		while(primo->next!=NULL){
			minimo=primo;
			for(suc=primo->next;suc!=NULL; suc=suc->next)
				if((suc->r.reale)<(primo->r.reale)||(suc->r.decimale)<(primo->r.decimale))
					minimo=suc;
					scambia(minimo,primo);
				primo=primo->next;
		}
		printf("e ordinata sia\n");
		visualizzaNodo(head);
	}
}