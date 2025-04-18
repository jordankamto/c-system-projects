#include <stdio.h>

int main() {
    // Ouvrir le fichier CSV en mode écriture ("w")
    FILE *fichier = fopen("etudiants.csv", "w");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    // Données à enregistrer dans le fichier
    char noms[3][30] = {"Doe", "Smith", "Johnson"};
    char prenoms[3][30] = {"John", "Jane", "Michael"};
    int matricules[3] = {12345, 67890, 54321};

    // Enregistrement des données dans le fichier CSV à l'aide d'une boucle for
    fprintf(fichier, "Nom, Prénom, Matricule\n");
    for (int i = 0; i < 3; i++) {
        fprintf(fichier, "%s, %s, %d\n", noms[i], prenoms[i], matricules[i]);
    }

    // Fermer le fichier
    fclose(fichier);

    // Ouvrir le fichier CSV en mode lecture ("r")
    fichier = fopen("etudiants.csv", "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    char nom[30], prenom[30];
    int matricule;

    // Ignorer la première ligne d'en-têtes
    fscanf(fichier, "%*s %*s %*s\n");

    // Afficher les données sous forme de tableau
    printf("|    Nom    |   Prénom   | Matricule |\n");
    while (fscanf(fichier, "%s, %s, %d\n", nom, prenom, &matricule) == 3) {
        printf("| %10s | %10s | %9d |\n", nom, prenom, matricule);
    }

    // Fermer le fichier
    fclose(fichier);

    return 0;
}
