#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void convheureminuteseconde(float *heure,float *minute, float *seconde);
void convheureminute(float *heure,float *minute);
void convheureseconde(float *heure, float *seconde);
void convminuteheureseconde(float *minute, float *heure, float *seconde);
void convminuteheure(float *minute, float *heure);
void convminuteseconde(float *minute,float*seconde);
void convsecondeheureminute(float *seconde,float *heure, float *minute);
void convsecondeheure(float *seconde, float *heure);
void convsecondeminute(float *seconde, float *minute);

float heure, minute,seconde;

int main(int argc,char *argv[]){
	
	system("color 5f");
    	int choix;
        int ko,A,B;
        time_t kone;
        struct tm instant;
        
         time(&kone);
         instant=*localtime(&kone);
         printf("..........bienvenue chez kone......\n");
         printf(" date du jour\n");
         printf("%d/%d/%d ; %d:%d:%d\n",instant.tm_mday,instant.tm_mon+1,instant.tm_year+1900, instant.tm_hour,instant.tm_min,instant.tm_sec);
         printf("---------------------------------------\n");
         
    do {
		
	printf("menu de convertion:\n");
	printf("1. si tu veux convertir des heures\n");
	printf("2. si tu veux convertir des  minutes\n");
	printf("3. si tu veux convertir des  secondes\n");
	printf("4. quitter le programme\n");
	printf("votre choix:\t");
    scanf("%d",&choix);
    
     } while(choix<1||choix>4);	
     
	switch(choix) {
		case 1: printf("donner le nombre d'heure a convertir\n");
		        scanf("%f",&heure);
				break;
				
		case 2: printf("donner le nombre de minutes a convertir\n");
		        scanf("%f",&minute);
				break;
				
	    case 3: printf("donner le nombre de seconde a convertir\n");
	            scanf("%f",&seconde);
				 break;
				 
	    case 4: printf("programme terminee!!\n");
		 break;
	default:
		printf("faites un  choix\n");
		 break;
	}

	if(choix==1) {
		do {
			
	printf("menu de convertion des heures:\n");
	printf("1. si tu veux convertir en minutes\n");
	printf("2. si tu veux convertir en secondes\n");
	printf("3. si tu veux convertir en minutes et en secondes\n");
	printf("4. quitter\n");
	printf("faites votre choix:\n");
	scanf("%d",&ko);
	switch(ko) {
		case 1: 
		convheureminute(&heure,&minute);
    	printf("%f heure font %f minute ",heure,minute);
	     break;
	     
		case 2: 
		convheureseconde(&heure,&seconde);
    	printf("%f heure font  %f seconde",heure,seconde);
    	 break;
    	 
		case 3: 
		convheureminuteseconde(&heure,&minute,&seconde);
     	printf("%f heure font %f minute ou %f seconde",heure,minute,seconde);
     	 break;
     	 
		case 4: 
     	printf("partie terminee!"); break;
     	
   	default: printf("faites un bon choix!!!\n");
	  break;
}
} while(ko<1||ko>4);

}

else if(choix==2){
	
		do {
			
	printf("menu de convertion des minutes:\n");
	printf("1. si tu veux convertir en heure\n");
	printf("2. si tu veux convertir en secondes\n");
	printf("3. si tu veux convertir en heure et en secondes\n");
	printf("4. quitter\n");
	printf("faites votre choix:\n");
	scanf("%d",&A);
	switch(A) {
		case 1: 
		convminuteheure(&minute,&heure);
       	printf("%f minute font %f heure ",minute,heure);
	     break; 
	     
		case 2: 
		convminuteseconde(&minute,&seconde);
     	printf("%f minute font  %f seconde",minute,seconde);
    	 break;
    	 
		case 3: 
		convminuteheureseconde(&minute,&heure,&seconde);
     	printf("%f minute font %f heure  ou %f seconde",minute,heure,seconde);
     	 break;
     	 
		case 4: 
     	printf("partie terminee!"); break;
   	default: printf("faites un bon choix!!!\n");
	  break;
}
} while(A<1||A>4);
}
else if (choix==3) {
	
		do {
			
	printf("menu de convertion des secondes:\n");
	printf("1. si tu veux convertir en heure\n");
	printf("2. si tu veux convertir en minute\n");
	printf("3. si tu veux convertir en heure et en minute\n");
	printf("4. quitter\n");
	printf("faites votre choix:\n");
	scanf("%d",&B);
	
	switch(B) {
		case 1: 
		convsecondeheure(&seconde,&heure);
       	printf("%f seconde font %f heure ",seconde,heure);
	     break; 
	     
		case 2: 
		convsecondeminute(&seconde,&minute);
     	printf("%f seconde font  %f minute",seconde,minute);
    	 break;
    	 
		case 3: 
		convsecondeheureminute(&seconde,&heure,&minute);
     	printf("%f seconde font %f heure  ou %f minute",seconde,heure,minute);
     	 break;
     	
		case 4: 
     	printf("partie terminee!"); break;
   	default: printf("faites un bon choix!!!\n");
	  break;
}
} while(B<1||B>4);
}

 return 0;
}

void convheureminuteseconde(float *heure,float *minute,float *seconde){
	*minute= *heure*60;
	*seconde= *heure*3600; 
}

void convminuteheureseconde(float *minute, float *heure, float *seconde){
	*heure= *minute/60;
	*seconde= *minute*60;
}

void convsecondeheureminute(float *seconde, float *heure, float *minute){
	*heure= *seconde/3600;
	*minute= *seconde/60;
}
	
void convheureminute(float *heure,float *minute){
	*minute= *heure*60;
}

void convheureseconde(float *heure, float *seconde){
	*seconde= *heure*3600; 
}

void convminuteheure(float *minute, float *heure){
	*heure= *minute/60;
}

void convminuteseconde(float *minute, float *seconde){
	*seconde= *minute*60;
}

void convsecondeheure(float *seconde, float *heure){
	*heure= *seconde/3600;
}

void convsecondeminute(float *seconde, float *minute){
	*minute= *seconde/60;
}

