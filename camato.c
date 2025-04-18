#include <stdio.h>

int main() {
    int hauteur;
    
    printf("Entrez la hauteur de l'arbre de Noël : ");
    scanf("%d", &hauteur);

    if (hauteur <= 0) {
        printf("La hauteur doit être un entier positif.\n");
    } else {
        // Boucle pour chaque niveau de l'arbre
        for (int niveau = 1; niveau <= hauteur; niveau++) {
            // Afficher des espaces pour l'alignement
            for (int espace = 0; espace < hauteur - niveau; espace++) {
                printf(" ");
            }
            
            // Afficher des étoiles pour représenter les branches
            for (int etoile = 0; etoile < 2 * niveau - 1; etoile++) {
                printf("*");
            }
            
            // Aller à la ligne pour le prochain niveau
            printf("\n");
        }
        
        // Afficher le tronc de l'arbre avec la même hauteur que l'arbre
        for (int i = 0; i < hauteur - 1; i++) {
            for (int j = 0; j < hauteur - 1; j++) {
                printf(" ");
            }
            printf("||\n");
        }
    }
    
    return 0;
}
