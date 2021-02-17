#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

//declaration des structures

struct DATE{
	int jour;
	int mois;
	int annee;
};

struct personne{
	int numero;
	char nom[20];
	char prenom[20];
	char adresse[20];
	int numtel;
	struct DATE DAT;
};

struct personne per[100];
int ko=0;
int b=0;

//fonctions et procedures secondaires
  
void ajouter_personne(){
    Color(11,0);
	per[ko].numero=b+1;
	printf("personne numero %d\n",per[ko].numero);
	printf("donner le nom de la personne:\n");
	scanf("%s",&per[ko].nom);
	printf("donner le prenom de la personne:\n");
	scanf("%s",&per[ko].prenom);
	printf("donner l'adresse de la personne:\n");
	scanf("%s",&per[ko].adresse);
	printf("donner le numero de telephone  de la personne:\n");
	scanf("%s",&per[ko].numtel);
	printf("donner la date de naissance  de la personne:\n");
	do {  printf("jour: ");
		scanf("%d",&per[ko].DAT.jour);
 } while(per[ko].DAT.jour<1||per[ko].DAT.jour>31);
 
do {    printf("mois: ");
	scanf("%d",&per[ko].DAT.mois);
} while(per[ko].DAT.mois<1||per[ko].DAT.mois>12);

   printf("annee: ");
	scanf("%d",&per[ko].DAT.annee);
	ko++;
	b++;
}


afficher(){
	
	int i;
	Color(11,0);
	if(!ko)
	printf("\nla liste est vide!!!!\n");
	Color(12,0);
	printf("|numero\t\t|nom\t\t|prenom\t\t|adresse\t\t|numero.tel\t\t|anniversaire\n");
	printf(".............................................................................................\n");
	for(i=0;i<ko;i++) {
		printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\t%d\t%d\n",per[i].numero,per[i].nom,per[i].prenom,per[i].adresse,per[i].numtel,per[i].DAT.jour,per[i].DAT.mois,per[i].DAT.annee);
	    printf("\n");
}
}

int rechercher(int num){
	
	Color(15,0);
	int pos,i;
	pos=-1;
	for(i=0;i<ko;i++) {
		if(num==per[i].numero)
		pos=i;
	} 	return pos;
}1

void supprimer(	int pos){
	
		Color(9,0);
	int i;
	for(i=pos;i<ko;i++) {
		per[i]=per[i+1];
} ko--;

}

void modifier(int pos){
	
	Color(11,0);
	int ch;
	do {
		printf("1.modifier l'adresse\n");
		printf("2.modifier le numero de telephone\n");
		printf("3.retour\n");
		
		printf("saisissez votre choix\n");
		scanf("%d",&ch);
		switch(ch) {
			case 1 : printf("donner la nouvelle adresse\n");
			          scanf("%s",&per[pos].adresse);
			          break;
			case 2 :  printf("donner le nouveau numero de telephone\n");
			          scanf("%d",&per[pos].numtel);
			          break;      
			case 3 :  printf("valeur enregistrer\n");  
	default: printf("partie terminee!!!\n");
	break;
}

} while(ch!=3);

}

void Color(int couleurDUTexte,int CouleurDeFond){
	
	HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H,CouleurDeFond*16+couleurDUTexte);
}

//fonction principale

int main(){
	
	int ko, num;
	int choix,x;
	int pos,ch;

	
	do {
		    do {
		    		Color(13,0);
	  	printf(".....................menu........................ \n\n");
	 	printf("1. ajouter une personne \n");
	 	printf("2. modifier les coordonnes  d'une personne \n");
	 	printf("3. supprimer une personne \n");
	 	printf("4. rechercher une personne \n");
	 	printf("5. afficher toute les entrees \n");
	 	printf("6. quitter le programme \n");
	 	
	 	printf("saisissez  votre choix: \n");
	 	scanf("%d",&choix);
	 	
          } while(choix<1||choix>6);

		switch(choix) {
			case 1 :
				printf("donner le nombre de personne a ajouter:\n");
				scanf("%d",&x);
				int i;
				for(i=0;i<x;i++) {
				ajouter_personne() ;	}
					break;
			case 2 :
				printf("donner le numero de la personne a modifier:\n");
				scanf("%d",&num);
				if(rechercher(num)==-1) {
				printf("la personne n'existe pas!!!!\n");}
				else
			 modifier(rechercher(num));
		  	break;
			case 3 : 
				printf("donner le numero de la personne a supprimer:\n");
				scanf("%d",&num);
				if(rechercher(num)==-1) {
				printf("la personne n'existe pas!!!!\n");}
				else
			 supprimer(rechercher(num));
		 	break;
			case 4 :
				printf("donner le numero de la personne a rechercher:\n");
				scanf("%d",&num);
				printf("\n");
				if(rechercher(num)==-1) {
				printf("la personne n'existe pas!!!!\n");}
				else{
				
			 printf("la personne rechercher est:\n\n");
	printf("numero:%d\n nom:%s\n prenom:%s\n adresse:%s\n numero.tel:%d\n anniversaire :%d\t %d\t %d\n",per[rechercher(num)].numero,per[rechercher(num)].nom,per[rechercher(num)].prenom,per[rechercher(num)].adresse,per[rechercher(num)].numtel,per[rechercher(num)].DAT.jour,per[rechercher(num)].DAT.mois,per[rechercher(num)].DAT.annee);
       printf("\n");
	}
		 	break;
			case 5 :
				afficher();
				printf("\n");
		 	break;
			case 6 :printf(" programme termine !");
		 	break;
	default:	printf(" faites un bon choix svp \n");
	break;
}
} while(choix!=6);

return 0;
}


