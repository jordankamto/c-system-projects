#include <stdio.h>

void printSpaces(int numSpaces) {
    for (int i = 0; i < numSpaces; i++) {
        printf(" ");
    }
}

void printStars(int numStars) {
    for (int i = 0; i < numStars; i++) {
        printf("*");
    }
}

int main() {
    int treeHeight;
    
    printf("Entrez la hauteur de l'arbre de Noël : ");
    scanf("%d", &treeHeight);
    
    if (treeHeight < 1) {
        printf("La hauteur de l'arbre doit être d'au moins 1.\n");
        return 1;
    }
    
    for (int i = 1; i <= treeHeight; i++) {
        // Affiche les espaces à gauche pour centrer l'arbre
        printSpaces(treeHeight - i);
        
        // Affiche les étoiles pour la rangée actuelle
        printStars(2 * i - 1);
        
        // Passe à la ligne suivante
        printf("\n");
    }
    
    // Affiche le tronc de l'arbre
    printSpaces(treeHeight - 1);
    printStars(1);
    printf("\n");
    
    return 0;
}
