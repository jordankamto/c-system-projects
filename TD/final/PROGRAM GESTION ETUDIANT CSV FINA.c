#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> //pour le type de retour true or false

void menu();

//1 Définition des structures

//structure unité d'enseignement
struct unite {
int c; //c est le dimunitif de Code
char l[50]; //l est le dimunitif de Libelle
int cf; //cf est le dimunitif de CoeFficient
float n; //n est le dimunitif de Note
};
typedef struct unite UNITE;

//structure liste des unités
struct listeUnite {
int lib; //libre est le dimunitif de libre
UNITE tu[10]; //tu est le dimunitif de Tableau des Unités S
};
typedef struct listeUnite LUNITE;

//structure date
struct date{
int j; //j est le dimunitif de Jour
int m; //m est le dimunitif de Mois
int a; //a est le dimunitif de Année
};
typedef struct date DATE;

//structure etudiant
struct etudiant {
int mat; //mat est le dimunitif de MATricule
char nom[30];
char prenom[30];
DATE dn; //dn est le dimunitif de Date de Naissance
LUNITE sn; //sn est le dimunitif de Sa Note
};
typedef struct etudiant ETUDIANT;

//structure liste étudiant
struct listeEtudiant {
int sv; //sv est le dimunitif de suivant
ETUDIANT te[21]; //te est le dimunitif de Tableau des Etudiants
};
typedef struct listeEtudiant LETUDIANT;



LUNITE lu= { .lib = 0 } ; //lu est le dimunitif de Liste des Unités
LETUDIANT le = { .sv =0}; //le est le dimunitif de Liste des Etudiants

void sauvegarderNotes() {
    FILE *file = fopen("notes.csv", "w");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    // En-tête du fichier CSV
    fprintf(file, "Matricule");
    for (int i = 0; i < lu.lib; i++) {
        fprintf(file, ",%s", lu.tu[i].l);
    }
    fprintf(file, "\n");

    for (int i = 0; i < le.sv; i++) {
        fprintf(file, "%d", le.te[i].mat);

        // Ajouter les notes pour chaque unité d'enseignement
        for (int j = 0; j < lu.lib; j++) {
            fprintf(file, ",%.1f", le.te[i].sn.tu[j].n);
        }

        fprintf(file, "\n");
    }

    fclose(file);
}

// Fonction pour charger les notes des étudiants à partir d'un fichier CSV
void chargerNotes() {
    FILE *file = fopen("notes.csv", "r");
    if (file == NULL) {
        printf("Aucun fichier de données trouvé.\n");
        return;
    }

    char header[512];
    fscanf(file, "%[^\n]\n", header);

    int mat;
    while (fscanf(file, "%d", &mat) != EOF) {
        int idx = mat - 1;
        for (int j = 0; j < lu.lib; j++) {
            fscanf(file, ",%f", &le.te[idx].sn.tu[j].n);
        }
    }

    fclose(file);
}

// Les fonctions `sauvegarderEtudiantsEtNotes` et `chargerEtudiantsEtNotes` sont modifiées pour exclure les notes

void sauvegarderEtudiants() {
    FILE *file = fopen("etudiants.csv", "w");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    // En-tête du fichier CSV
    fprintf(file, "Matricule,Nom,Prenom,date_de_Naissance\n");

    for (int i = 0; i < le.sv; i++) {
        fprintf(file, "%d,%s,%s,%d/%d/%d\n", le.te[i].mat, le.te[i].nom, le.te[i].prenom, le.te[i].dn.j, le.te[i].dn.m, le.te[i].dn.a);
    }

    fclose(file);
}

void chargerEtudiants() {
    FILE *file = fopen("etudiants.csv", "r");
    if (file == NULL) {
        printf("Aucun fichier de données trouvé.\n");
        return;
    }

    char header[512];
    fscanf(file, "%[^\n]\n", header);

    while (fscanf(file, "%d,%[^,],%[^,],%d/%d/%d", &le.te[le.sv].mat, le.te[le.sv].nom, le.te[le.sv].prenom, &le.te[le.sv].dn.j, &le.te[le.sv].dn.m, &le.te[le.sv].dn.a) != EOF) {
        le.sv++;
    }

    fclose(file);
}

// Fonction pour charger les informations des étudiants et leurs notes à partir d'un fichier CSV
void chargerEtudiantsEtNotes() {
    FILE *file = fopen("etudiants.csv", "r");
    if (file == NULL) {
        printf("Aucun fichier de données trouvé.\n");
        return;
    }

    char header[512]; // Pour stocker la première ligne de l'en-tête
    fscanf(file, "%[^\n]\n", header); // Lire l'en-tête sans l'enregistrer

    while (fscanf(file, "%d,%[^,],%[^,],%d/%d/%d", &le.te[le.sv].mat, le.te[le.sv].nom, le.te[le.sv].prenom, &le.te[le.sv].dn.j, &le.te[le.sv].dn.m, &le.te[le.sv].dn.a) != EOF) {
        // Charger les notes pour chaque unité d'enseignement
        for (int j = 0; j < lu.lib; j++) {
            fscanf(file, ",%f", &le.te[le.sv].sn.tu[j].n);
        }

        le.sv++; // Incrémenter le nombre d'étudiants
    }

    fclose(file);
}

// Fonction pour sauvegarder les informations des unités d'enseignement dans un fichier CSV
void sauvegarderUnitesEnseignement() {
    FILE *files = fopen("unites_enseignement.csv", "w");
    if (files == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    // En-tête du fichier CSV
    fprintf(files, "Code,Libelle,Coeficient\n");

    for (int i = 0; i < lu.lib; i++) {
        fprintf(files, "%d,%s,%d\n", lu.tu[i].c, lu.tu[i].l, lu.tu[i].cf);
    }

    fclose(files);
}

// Fonction pour charger les informations des unités d'enseignement à partir d'un fichier CSV
void chargerUnitesEnseignement() {
    FILE *files = fopen("unites_enseignement.csv", "r");
    if (files == NULL) {
        printf("Aucun fichier de données trouvé.\n");
        return;
    }

    char header[512]; // Pour stocker la première ligne de l'en-tête
    fscanf(files, "%[^\n]\n", header); // Lire l'en-tête sans l'enregistrer

    while (fscanf(files, "%d,%[^,],%d", &lu.tu[lu.lib].c, lu.tu[lu.lib].l, &lu.tu[lu.lib].cf) != EOF) {
        lu.lib++; // Incrémenter le nombre d'unités d'enseignement
    }

    fclose(files);
}

//Renseignement des UE
void ajouter_ue(){
int choix;
	while(1){
		printf("1-Ajouter\n2-Retour\n");
		scanf("%d", &choix);
		if (choix==1){
			lu.tu[lu.lib].c=lu.lib+1;
			printf("Entrer le libelle\n");
			scanf(" %s",&(lu.tu[lu.lib].l));
			printf("Entrer le coefficient\n");
			scanf("%d",&(lu.tu[lu.lib].cf));
			//manipulation pour ajouter la nouvelle matière à tous les étudiants
			for(int z=0;z<le.sv;z++){
                le.te[z].sn.tu[lu.lib].c=lu.tu[lu.lib].c;
                le.te[z].sn.tu[lu.lib].cf=lu.tu[lu.lib].cf;
                strcpy(le.te[z].sn.tu[lu.lib].l,lu.tu[lu.lib].l);
			}
			//libre de liste étudiant est incrémenté
			lu.lib +=1;
		}
		else if (choix==2){
			break;
		}
		else{
			printf("Choix invalide. Veuillez entrer un nombre valide\n");
		}
	}
	if(choix==2){
        menu();
    }
}


//2.Renseignement des étudiants
void ajouter_et(){
int choix;
	while(1){
		printf("1-Ajouter\n2-Retour\n");
		scanf("%d",&choix);
		if (choix==1){
            le.te[le.sv].mat=le.sv + 1;
			printf("Entrer le nom\n");
			scanf(" %s",&(le.te[le.sv].nom));
			printf("Entrer le prenom\n");
			scanf(" %s",&(le.te[le.sv].prenom));
			printf("Entrer le jour, le mois et l'année de naissance\n");
			scanf("%d %d %d", &(le.te[le.sv].dn.j), &(le.te[le.sv].dn.m),&(le.te[le.sv].dn.a));
			//ajout automatique des matières existante à cet étudiant ajouté;
			le.te[le.sv].sn=lu;
			//le libre de liste étudiant(sv) est incrémenté.
			le.sv +=1;
			
		}
		else if (choix==2){
			break;
		}
		else{
			printf("Choix Invalide\n");
		}
	}
	if(choix==2){
        menu();
    }
}


//Recherche d'un etudiant dont le matricule est passé en paramètre
bool cherchere(int m){
    int cpt=0;
    if(le.sv==0){return false;}
    else{
        for(int t=0;t<le.sv;t++){
            if(le.te[t].mat==m){cpt+=1;}
        }
        if(cpt>0){return true;}
        else{return false;}
    }
}


// calcul de la moyenne
float moyenne(int ma) {

	int i0, sc=0, s=0;
	float moy;
	if (!cherchere(ma)){
		printf("etudiant inexistant \n");
	}
	else {
		ma -=1;
		for(i0=0; i0<le.te[ma].sn.lib; i0++) {
			int p=(le.te[ma].sn.tu[i0].n)*(le.te[ma].sn.tu[i0].cf);
			s+=p;
			sc+=le.te[ma].sn.tu[i0].cf;
		}
		moy = (float)s/sc;
		ma+=1;

	}
return moy;
}


// moyenne du premier
float moyennepre(){

	float tmoyenne[le.sv];
	int i, j;
	for(i=1; i<=le.sv; i++) {
		tmoyenne[i-1] = moyenne(i);
	}
	float max = tmoyenne[0];
	for (j=0; j<le.sv; j++) {
		if(tmoyenne[j]>max){
			max = tmoyenne[j];
		}
	}
	return max;

}


//rang de tous les etudiants
void rangdetous(){
   float min, tm, tmy[le.sv];
	int minm, i, j, tim, mt[le.sv], cl;
	
	for(i=1; i<=le.sv; i++) {
        mt[i-1]=i;
	tmy[i-1] = moyenne(i);
	}
	
	for(int k=0; k<le.sv; k++){ 
		for(j=k+1; j<le.sv; j++) {
		   if(tmy[k]>tmy[j]){
		        tm=tmy[j];
		        tmy[j]=tmy[k];
		        tmy[k]=tm;

		        tim=mt[j];
		        mt[j]=mt[k];
		        mt[k]=tim;
		   }
		}
    }
    
	cl=le.sv;
	printf("RESULTAT CLASSÉ PAR ORDRE DE MERIE\n\nNOM\tMATRICULE\tRANG\tMOYENNE\n");
	
	for(int t=0; t<le.sv; t++) {
        printf("%s\t\t%d\t%d\t%f\n",le.te[(mt[t])-1].nom,mt[t],cl,tmy[t]);
        cl-=1;
	}
}


//rechercher une UE dont le code est passé en paramètre
bool chercheru(int cu){
    int cp=0;
    if(lu.lib==0){return false;}
    else{
        for(int t=0;t<lu.lib;t++){
            if(lu.tu[t].c==cu){cp+=1;}
        }
        if(cp>0){return true;}
        else{return false;}
    }
}

void modifier_etudiant() {
    int matricule, i;
    printf("Entrez le matricule de l'etudiant à modifier: ");
    scanf("%d", &matricule);

    for(i = 0; i < le.sv; i++) {
        if(le.te[i].mat == matricule) {
            printf("Etudiant actuel:\n");
            printf("Nom: %s\n", le.te[i].nom);
            printf("Prenom: %s\n", le.te[i].prenom);
            printf("Matricule: %d\n", le.te[i].mat);
            printf("Entrez les nouvelles informations:\n");
            
            printf("Nom: ");
            scanf("%s", le.te[i].nom);
            printf("Prenom: ");
            scanf("%s", le.te[i].prenom);
            
            printf("Informations mises à jour avec succès.\n");
            return;
        }
    }
    printf("Aucun étudiant trouvé avec le matricule %d.\n", matricule);
}


//afficher la liste des étudiants
void aletu(){ //aletu est le dimunitif de Afficher la Liste des ETUdiant
    for(int i=0;i<le.sv;i++){
        printf("%s est né le %d/%d/%d a pour matricule %d\n",le.te[i].nom,le.te[i].dn.j,le.te[i].dn.m,le.te[i].dn.a,le.te[i].mat);
    }
}

//afficher la liste des unités
void aluni(){ //aletu est le dimunitif de Afficher la Liste des ETUdiant
    printf("CODE\tLIBELLE\tCOEFFICIENT\n");	
    for(int i=0;i<lu.lib;i++){
        printf("%d\t%s\t%d\n",lu.tu[i].c,lu.tu[i].l,lu.tu[i].cf);
    }
}

//Afficher la note d'un étudiant
void anetu(){ //anetu est le dimunitif de Afficher la note d'un étudiant
    int matri,choi;
    while(1){
        printf("1-Afficher\n2-Retour\n");
        scanf("%d",&choi);
        if(choi==1){
            printf("entrer le matricule de l\'étudiant\n");
            scanf("%d",&matri);
            if(cherchere(matri)){
                printf("voici les notes de %s de matricule %d\n\t",le.te[matri-1].nom,matri);
                for(int o=0;o<le.te[matri-1].sn.lib;o++){
                    printf("%s %f\n\t",le.te[matri-1].sn.tu[o].l,le.te[matri-1].sn.tu[o].n);
                }
                break;
            }
            else{
                printf("le matricule entré n'esxiste\n");
                break;
            }
        }
        else if(choi==2){
            break;
        }
    else{printf("entré invalide");}
    }
    if(choi==2){
        menu();
    }
}

void supprimer_etudiant() {
    int matricule, i, j;
    printf("Entrez le matricule de l'etudiant à supprimer: ");
    scanf("%d", &matricule);

    for(i = 0; i < le.sv; i++) {
        if(le.te[i].mat == matricule) {
            printf("Etudiant %s %s (Matricule: %d) a été supprimé.\n", le.te[i].nom, le.te[i].prenom, le.te[i].mat);
            
            // Décalage des étudiants pour écraser celui à supprimer
            for(j = i; j < le.sv - 1; j++) {
                le.te[j] = le.te[j + 1];
            }
            
            // Réduction du nombre total d'étudiants
            le.sv--;

            // Réaffectation des matricules pour éviter les trous
            for(j = i; j < le.sv; j++) {
                le.te[j].mat = j + 1;
            }

            return;
        }
    }
    printf("Aucun étudiant trouvé avec le matricule %d.\n", matricule);
}


//afficher les notes de tous les étudiants
void antetu(){
    for(int h=0;h<le.sv;h++){
        printf("voici les notes de %s de matricule %d\n\t",le.te[h].nom,le.te[h].mat);
        for(int o=0;o<le.te[h].sn.lib;o++){
            printf("%s %f\n\t",le.te[h].sn.tu[o].l,le.te[h].sn.tu[o].n);
        }
        printf("\n");
    }
}


//inserer la note d'un étudiant
void insererno(){
    int chx,mte,cm;
    float nt;
    while(1){
        printf("1-Ajouter\n2-Menu\n");
        scanf("%d",&chx);
        if(chx==2){
            break;
        }
        else if(chx==1){
            printf("entrer le matricule\n");
            scanf("%d",&mte);
            if(cherchere(mte)){
                printf("entrer le code de la matière\n");
                scanf("%d",&cm);
                if(chercheru(cm)){
                    printf("entrer la note de l\'etudiant %s en %s\n", &(le.te[mte-1].nom), le.te[mte-1].sn.tu[cm-1].l);
                    scanf("%f",&nt);
                    le.te[mte-1].sn.tu[cm-1].n=nt;
                }
                else{printf("Cette matière n'existe pas dans la liste des matières des étudiants. Il faut au préable l\'ajouter(voir cette option dans menu) si la liste des matières est Imcomplète dans la dite liste.\nNote non insérée\n");}
            }
            else{printf("Matricule Inexistant. Note non insérée\n");}
        }
        else{printf("entré invalide");}
    }
    if(chx==2){
        menu();
    }
}


bool levide(){
    if(le.sv==0)
        return true;
    else
        return false;
}


//
void menu(){
    int menuc;
    while(1){
        printf("\t\t\t*****MENU*****\n");
        printf("\t\t\t\t0-QUITTER\n\t\t\t\t1-Ajouter une UE\n\t\t\t\t2-Ajouter un etudiant\n\t\t\t\t3-Saisir la note\n\t\t\t\t4-Rechercher un etudiant\n\t\t\t\t5-Afficher la liste des etudiants\n\t\t\t\t6-Afficher la liste des unites\n\t\t\t\t7-Afficher les notes d'un étudiant\n\t\t\t\t8-Afficher les notes de tous les etudiants\n\t\t\t\t9-Connaitre la moyenne d'un etudiant\n\t\t\t\t10-Connaitre la moyenne du premier\n\t\t\t\t11-Rang de tous les etudiants\n\t\t\t\t12-Supprimer un etudiant\n\t\t\t\t13-Modifier les infos d'un etudiant\n");
        printf("\nChoisir le numero d'une action:  ");
        scanf("%d",&menuc);
        if(menuc==0){
             break;
        }
        else if(menuc==1){
            ajouter_ue();
        }
        else if(menuc==2){
            ajouter_et();
        }
        else if(menuc==3){
            insererno();
        }
        else if(menuc==4){
            int e;
            printf("entrer le matricule a rechercher\n");
            scanf("%d",&e);
            bool r=cherchere(e);
            if(r==true){
            	printf("l\'etudiant cherché existe il s\'appelle %s il est né le %d/%d/%d a pour matricule %d\n",le.te[e-1].nom,le.te[e-1].dn.j,le.te[e-1].dn.m,le.te[e-1].dn.a,le.te[e-1].mat);
            }
            else{
            	printf("l\'etudiant cherché n\'existe pas");
            }
        }
        else if(menuc==5){
            aletu();
        }
         else if(menuc==6){
             aluni();
        }
        else if(menuc==7){
            anetu();
        }
        else if(menuc==8){
            antetu();
        }
        else if(menuc==9){
            int e;
            printf("entrer le matricule de l\'etudiant\n");
            scanf("%d",&e);
            printf("%f\n",moyenne(e));
        }
        else if(menuc==10){
             printf("%f\n",moyennepre());
        }
        else if(menuc==11){
             rangdetous();
        }
        
        else if(menuc==12){
             supprimer_etudiant();
        }
         else if(menuc==13){
             modifier_etudiant();
        }
        else{printf("choix invalide\n");}

    }

}


//fonction principale
int main(){
 // Charger les données des étudiants et de leurs notes au démarrage de l'application
    
    chargerUnitesEnseignement();
    chargerNotes();
    chargerEtudiants();
   
printf("**********BIENVENU SUR NOTRE APPLICATION DE GESTION D\'ETUDIANT***********\n\n");
menu();
 // Sauvegarder les données des étudiants et de leurs notes avant de quitter
    sauvegarderUnitesEnseignement();
    sauvegarderEtudiants();
    sauvegarderNotes();
    
return 0;
}

