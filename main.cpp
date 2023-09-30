#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialisation du générateur de nombres aléatoires avec une graine basée sur l'heure
    srand(time(NULL));

    // Génération d'un nombre aléatoire entre 1 et 100
    int nombreAleatoire = rand() % 100 + 1;

    int tentative;
    int vies = 5;
    int gagne = 0; // Cette variable indique si l'utilisateur a deviné le nombre

    printf("Devinez le nombre entre 1 et 100. Vous avez 5 vies (représentées par des '❤️').\n");

    for (int i = 0; i < 5; i++) {
        printf("Vies : ");
        for (int j = 0; j < vies; j++) {
            printf("❤️ "); // Utilisation de '❤️' pour représenter les vies
        }
        printf("\n");

        printf("Tentative %d : ", i + 1);
        if (scanf("%d", &tentative) != 1) {
            printf("Saisie invalide. Veuillez entrer un nombre.\n");
            while (getchar() != '\n'); // Nettoie le buffer d'entrée
            i--; // Réduit le compteur pour ne pas utiliser la tentative invalide
            continue;
        }

        if (tentative == nombreAleatoire) {
            printf("Félicitations ! Vous avez deviné le nombre (%d).\n", nombreAleatoire);
            gagne = 1;
            break;
        } else if (tentative < nombreAleatoire) {
            printf("Le nombre est plus grand.\n");
        } else {
            printf("Le nombre est plus petit.\n");
        }

        vies--; // Décrémente le nombre de vies restantes
    }

    if (!gagne) {
        printf("Désolé, vous avez épuisé vos vies. Le nombre était : %d\n", nombreAleatoire);
    }

    return 0;
}
