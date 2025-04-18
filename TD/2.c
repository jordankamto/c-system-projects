#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ... (Définition des structures, fonctions, et variables)

// Ajouter un étudiant
void ajouter_et() {
    // ... (Code pour ajouter un nouvel étudiant)

    // Ouvrir le fichier CSV en mode écriture (crée le fichier s'il n'existe pas)
    FILE *fichierCSV = fopen("etudiants.csv", "a");
    
    if (fichierCSV == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier CSV.\n");
        return;
    }

    // Écrire les données de l'étudiant dans le fichier CSV
    fprintf(fichierCSV, "E,%d,%s,%d/%d/%d,", le.te[le.sv - 1].mat, le.te[le.sv - 1].nom,
            le.te[le.sv - 1].dn.j, le.te[le.sv - 1].dn.m, le.te[le.sv - 1].dn.a);
    
    // Écrire les informations sur les unités d'enseignement de l'étudiant
    for (int i = 0; i < lu.lib; i++) {
        fprintf(fichierCSV, "U,%d,%s,%d,%f,", lu.tu[i].c, lu.tu[i].l, lu.tu[i].cf, le.te[le.sv - 1].sn.tu[i].n);
    }

    fprintf(fichierCSV, "\n"); // Fin de la ligne

    // Fermer le fichier
    fclose(fichierCSV);
    
    printf("Étudiant ajouté et enregistré dans le fichier CSV.\n");
}

// ...

int main() {
    // ...

    while (1) {
        // ...

        if (menuc == 2) {
            ajouter_et();
        }

        // ...
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition des structures

// Structure unité d'enseignement
struct unite {
    int c; // Code
    char l[50]; // Libellé
    int cf; // Coefficient
    float n; // Note
};

// ... (définition des autres structures)

// Charger les données à partir du fichier CSV
void chargerDonneesDepuisCSV() {
    FILE *fichierCSV = fopen("etudiants.csv", "r");
    
    if (fichierCSV == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier CSV.\n");
        return;
    }

    // Lire les données du fichier ligne par ligne
    char ligne[256]; // Ajustez la taille selon vos besoins

    while (fgets(ligne, sizeof(ligne), fichierCSV) != NULL) {
        // Ici, vous devez analyser la ligne pour extraire les données et les stocker
        // dans vos structures appropriées.
        // Utilisez la fonction strtok ou une autre méthode pour diviser la ligne en valeurs séparées par des virgules.
        // Ensuite, convertissez les chaînes de caractères en types appropriés (entiers, flottants, etc.)
        // et attribuez-les aux membres de vos structures.

        // Exemple (à personnaliser selon votre format de fichier) :
        int matricule;
        char nom[50];
        int jour, mois, annee;
        float note;

        sscanf(ligne, "%d,%s,%d/%d/%d,%f", &matricule, nom, &jour, &mois, &annee, &note);

        // Maintenant, vous pouvez créer une instance de votre structure et attribuer les valeurs lues
        // Ajoutez ces données aux listes appropriées, etc.
    }

    fclose(fichierCSV);
}

// ... (autres fonctions)

int main() {
    chargerDonneesDepuisCSV();
    
    // Appeler d'autres fonctions pour interagir avec les données chargées depuis le fichier CSV

    return 0;
}
