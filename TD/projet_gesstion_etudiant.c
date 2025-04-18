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
    fprintf(fichierCSV, "%d,%s,%d/%d/%d\n", le.te[le.sv - 1].mat, le.te[le.sv - 1].nom,
            le.te[le.sv - 1].dn.j, le.te[le.sv - 1].dn.m, le.te[le.sv - 1].dn.a);
    
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
