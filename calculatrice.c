#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//Cette mini calculatrice est propos�e par M. DJIONANG Berlin
//Nous commencons par construire un meunu et puis nous effectuons les operations relatives � chaque menu

int main()
{
int a,b,c,d,r,o;
double d1,d2;

//Nous constituons ici notre menu

printf("***************BIENVENUE DANS NOTRE MINI CALCULATRICE*********************\n")	;
printf("***************FAITES UN CHOIX AU NIVEAU DU MENU     *********************\n")	;

//Ici, nous faisons une boucle infinie afin de repeter le menu au besoin
while(1){	
printf("Quelle operation souhaitez vous realiser?\n")	;
printf("0: Quitter\n");
printf("\n");
printf("1: Addition\n");
printf("\n");
printf("2: Soustraction\n");
printf("\n");
printf("3: Multiplication\n");
printf("\n");
printf("4: Division\n");
printf("\n");
printf("5: Modulo\n");
printf("\n");
printf("6: Puissance\n");
printf("\n");
printf("7: Racine\n");
printf("\n");
printf("8: Carre\n");
printf("\n");
printf("9: Pgcd\n");
printf("\n");
printf("10: Ppcm\n");
//Nous recuperons ici l'operation qu'il souhaite developper
scanf("%d",&o);
printf("\n");


//Ici, nous executons une op�ration en fonction du choix de l'utilisateur
switch(o){
 case 1: do{
		printf("Entrer vos deux entiers positifs:");
		scanf("%d %d",&a,&b);
		}while((a<=0)||(b<=0));
		 
		 printf("%d + %d = %d\n", a, b, a+b); break;
 
 case 2: do{
		printf("Entrer vos deux entiers positifs:");
		scanf("%d %d",&a,&b);
		}while((a<=0)||(b<=0));
		 
		 printf("%d - %d = %d\n", a, b, a-b)	; break;
 
 case 3: do{
		printf("Entrer vos deux entiers positifs:");
		scanf("%d %d",&a,&b);
		}while((a<=0)||(b<=0));
		 
		 printf("%d * %d = %d\n", a, b, a*b)	; break;
 
 case 4: do{
		printf("Entrer vos deux entiers positifs:");
		scanf("%d %d",&a,&b);
		}while((a<=0)||(b<=0));
		 printf(" %d / %d = %d\n", a, b, a/b)	; break;
 
 case 5: do{
		printf("Entrer vos deux entiers positifs:");
		scanf("%d %d",&a,&b);
		}while((a<=0)||(b<=0));
		 
		 printf(" %d %d = %d\n", a, b, a%b)	; break;
 
 case 6: do{
		printf("Entrer vos deux entiers positifs:");
		scanf("%d %d",&a,&b);
		}while((a<=0)||(b<=0));
		 
		 printf("%d^%d = %f\n", a, b, pow(a,b))	; break;
 
 case 7: do{
		printf("Entrer un entier positifs:");
		scanf("%d",&a);
		}while(a<=0);
		 
		 printf("v %d = %lf\n", a, sqrt(a))	; break;
 
 case 8: do{
		printf("Entrer un entier positifs:");
		scanf("%d",&a);
		}while(a<=0);
		 
		 printf(" %d^2 = %d\n", a, a*a)	; break;
 
 case 9: do{
		printf("Entrer vos deux entiers positifs:");
		scanf("%d %d",&a,&b);
		}while((a<=0)||(b<=0));
		 
		 if (a > b)
			{ c = a;
			d = b;
			}
			else
			{ c=b;
			d=a;
			}
			r= c % d;
			while(r!=0)
			{ c = d;
			d = r;
			r = c % d;
			}
			printf("Le PGCD de %d et %d est %d.\n",a,b,d);	; break;
 
 case 10: do{
		printf("Entrer vos deux entiers positifs:");
		scanf("%d %d",&a,&b);
		}while((a<=0)||(b<=0));
		 
		 if (a > b)
			{ c = a;
			d = b;
			}
			else
			{ c=b;
			d=a;
			}
			r= c % d;
			while(r!=0)
			{ c = d;
			d = r;
			r = c % d;
			}
			d = (a*b) / d;
			printf("Le ppcm de %d et %d est %d.\n",a,b,d)	; break;
 
 case 0: exit(0); break;
 
 default: printf("Faites un bon choix dans le menu\n");
	
}
	
}


return 0;
}
