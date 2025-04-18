#include <stdio.h>
#include <string.h>

// Structure pour les unités d'enseignement (UE)
struct ue {
    char nom[50];
    char libelle[50];
    char description[100];
    int coef;
    float note;
};

// Structure pour les étudiants
struct etudiant {
    char matricule[10];
    char nom[50];
    char prenom[50];
    char lieu_naissance[100];
    struct ue matieres[4];
    int nb_matieres;
};

// Procédure pour saisir les informations d'une UE
void saisir_info_ue(struct ue *unite) {
    printf("\nNom de l'unité d'enseignement : ");
    scanf("%s", unite->nom);
    printf("Libellé de l'unité d'enseignement : ");
    scanf("%s", unite->libelle);
    printf("Description de l'unité d'enseignement : ");
    scanf("%s", unite->description);
    printf("Coefficient de l'unité d'enseignement : ");
    scanf("%d", &unite->coef);
    unite->note = 0.0;
}

// Procédure pour saisir les informations d'un étudiant
void saisir_info_etudiant(struct etudiant *e) {
    printf("\nNom de l'étudiant : ");
    scanf("%s", e->nom);
    printf("Prénom de l'étudiant : ");
    scanf("%s", e->prenom);
    printf("Lieu de naissance de l'étudiant : ");
    scanf("%s", e->lieu_naissance);
    printf("Matricule de l'étudiant : ");
    scanf("%s", e->matricule);
    e->nb_matieres = 4;

    // Saisie des informations pour chaque UE de l'étudiant
    for (int i = 0; i < e->nb_matieres; i++) {
        printf("\nSaisie des informations pour l'unité d'enseignement %d de l'étudiant %s:\n", i + 1, e->nom);
        saisir_info_ue(&e->matieres[i]);
    }
}

// Procédure pour saisir les notes d'un étudiant
void saisir_notes(struct etudiant *etudiant) {
    for (int i = 0; i < etudiant->nb_matieres; i++) {
        printf("\nSaisir la note de l'étudiant %s pour l'unité d'enseignement %s: ",
               etudiant->nom, etudiant->matieres[i].nom);
        scanf("%f", &etudiant->matieres[i].note);
    }
}

// Fonction pour calculer la moyenne d'un étudiant
float calculer_moyenne_etudiant(struct etudiant *etudiant) {
    float somme_notes = 0.0;
    for (int i = 0; i < etudiant->nb_matieres; i++) {
        somme_notes += etudiant->matieres[i].note;
    }
    return somme_notes / etudiant->nb_matieres;
}

// Fonction pour obtenir la moyenne et le nom du premier étudiant
void obtenir_moyenne_et_nom_premier(struct etudiant *etudiants, int nombre_etudiants, float *moyenne, char *nom) {
    if (nombre_etudiants <= 0) {
        *moyenne = 0.0;
        strcpy(nom, "Aucun étudiant");
        return;
    }

    *moyenne = calculer_moyenne_etudiant(&etudiants[0]);
    strcpy(nom, etudiants[0].nom);

    for (int i = 1; i < nombre_etudiants; i++) {
        float moyenne_etudiant = calculer_moyenne_etudiant(&etudiants[i]);
        if (moyenne_etudiant > *moyenne) {
            *moyenne = moyenne_etudiant;
            strcpy(nom, etudiants[i].nom);
        }
    }
}

// Fonction pour vérifier si un étudiant avec un matricule donné existe
int etudiant_existe(struct etudiant etudiants[], int nombre_etudiants, const char *matricule_recherche) {
    for (int i = 0; i < nombre_etudiants; i++) {
        if (strcmp(etudiants[i].matricule, matricule_recherche) == 0) {
            return 1; // L'étudiant avec le matricule donné a été trouvé
        }
    }
    return 0; // Aucun étudiant avec le matricule donné n'a été trouvé
}

// Fonction pour trier les étudiants en fonction de leur moyenne (tri par sélection)
void trier_etudiants_par_moyenne(struct etudiant *etudiants, int nombre_etudiants) {
    for (int i = 0; i < nombre_etudiants - 1; i++) {
        for (int j = i + 1; j < nombre_etudiants; j++) {
            if (calculer_moyenne_etudiant(&etudiants[j]) > calculer_moyenne_etudiant(&etudiants[i])) {
                // Échangez les étudiants
                struct etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
}

// Fonction pour calculer la moyenne d'un étudiant en fonction de son matricule
float calculer_moyenne_etudiant_par_matricule(struct etudiant *etudiants, int nombre_etudiants, const char *matricule) {
    for (int i = 0; i < nombre_etudiants; i++) {
        if (strcmp(etudiants[i].matricule, matricule) == 0) {
            return calculer_moyenne_etudiant(&etudiants[i]);
        }
    }
    // Retourner une valeur négative pour indiquer que l'étudiant n'a pas été trouvé
    return -1.0;
}

int main(void) {
    int nombre_etudiants;
    printf("Entrer le nombre maximum d'étudiants : ");
    scanf("%d", &nombre_etudiants);

    struct etudiant etudiants[nombre_etudiants];
    struct ue unites[4];

    int choix;
    char matricule_recherche[20];
    float moyenne_premier;
    char nom_premier;

    do {
        printf("\nMenu:\n");
        printf("1. Saisir les informations des unités d'enseignement\n");
        printf("2. Saisir les informations des étudiants\n");
        printf("3. Saisir les notes des étudiants\n");
        printf("4. Calculer la moyenne de tous les étudiants\n");
        printf("5. Obtenir la moyenne et le nom du premier étudiant\n");
        printf("6. Vérifier si un étudiant avec un matricule existe\n");
        printf("7. Trier et afficher le classement des étudiants\n");
        printf("8. Calculer la moyenne d'un étudiant par matricule\n");
        printf("9. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                for (int i = 0; i < 4; i++) {
                    printf("Saisie des informations pour l'unité d'enseignement %d:\n", i + 1);
                    saisir_info_ue(&unites[i]);
                }
                break;
            case 2:
                for (int i = 0; i < nombre_etudiants; i++) {
                    printf("\nSaisir les informations de l'étudiant %d\n", i + 1);
                    saisir_info_etudiant(&etudiants[i]);
                    for (int j = 0; j < etudiants[i].nb_matieres; j++) {
                        printf("UE %d : %s (Libellé : %s, Description : %s, Coefficient : %d, Note : %.2f)\n", j + 1,
                               etudiants[i].matieres[j].nom, etudiants[i].matieres[j].libelle,
                               etudiants[i].matieres[j].description, etudiants[i].matieres[j].coef,
                               etudiants[i].matieres[j].note);
                    }
                }
                break;
            case 3:
                for (int i = 0; i < nombre_etudiants; i++) {
                    saisir_notes(&etudiants[i]);
                }
                break;
            case 4:
                // Calculer et afficher les moyennes des étudiants
                for (int i = 0; i < nombre_etudiants; i++) {
                    float moyenne = calculer_moyenne_etudiant(&etudiants[i]);
                    printf("Moyenne de l'étudiant %s : %.2f\n", etudiants[i].nom, moyenne);
                }
                break;
            case 5:
                obtenir_moyenne_et_nom_premier(etudiants, nombre_etudiants, &moyenne_premier, &nom_premier);
                printf("Moyenne du premier étudiant (%c): %.2f\n", nom_premier, moyenne_premier);
                break;
            case 6:
                printf("Entrez le matricule de l'étudiant à rechercher: ");
                scanf("%s", matricule_recherche);
                if (etudiant_existe(etudiants, nombre_etudiants, matricule_recherche)) {
                    printf("L'étudiant avec le matricule %s existe.\n", matricule_recherche);
                } else {
                    printf("Aucun étudiant avec le matricule %s n'a été trouvé.\n", matricule_recherche);
                }
                break;
            case 7:
                // Trier les étudiants par moyenne
                trier_etudiants_par_moyenne(etudiants, nombre_etudiants);
                // Afficher le classement
                printf("Classement des étudiants par moyenne :\n");
                for (int i = 0; i < nombre_etudiants; i++) {
                    printf("%d. %s, Moyenne : %.2f\n", i + 1, etudiants[i].nom, calculer_moyenne_etudiant(&etudiants[i]));
                }
                break;
            case 8:
                printf("Entrez le matricule de l'étudiant pour lequel vous souhaitez calculer la moyenne : ");
                scanf("%s", matricule_recherche);
                float moyenne_etudiant = calculer_moyenne_etudiant_par_matricule(etudiants, nombre_etudiants, matricule_recherche);
                if (moyenne_etudiant >= 0) {
                    printf("Moyenne de l'étudiant avec le matricule %s : %.2f\n", matricule_recherche, moyenne_etudiant);
                } else {
                    printf("Aucun étudiant avec le matricule %s n'a été trouvé.\n", matricule_recherche);
                }
                break;
            case 9:
                printf("Programme terminé.\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un numéro de choix valide.\n");
        }
    } while (choix != 9);

    return 0;
}