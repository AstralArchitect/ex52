// fichiers d'en-tête
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// fonction pour determiner si x est un multiple de 16
bool estMultipleDeA(short x, short a)
{
    if (x % a == 0)
    {
        return true;
    }
    else{
        return false;
    }
}

// fonction pour tester si une liste contient x
int listContain(short list[], short lSize, short x)
{
    for (short i = 0; i < lSize; i++)
    {
        if (list[i] == x)
        {
            return i;
        }
    }
    return 0;
}

// fonction principale
int main()
{
    // déclaration des listes qui contiendront les multiples (je met 800 par ce que j'ai la flemme de chercher il faut combien)
    short multiples16[800];
    short multiples45[800];
    short multiples60[800];

    short nbTrouvees = 0;

    // initialisation des listes à 0
    memset(multiples16, 0, sizeof(multiples16));
    memset(multiples45, 0, sizeof(multiples45));
    memset(multiples60, 0, sizeof(multiples60));
    // boucle de recherche pour 16
    for (short i = 16; i < 800; i++)
    {
        // tester si le nombre est un multiple de 16
        if (estMultipleDeA(i, 16))
        {
            // si oui alors l'enregistrer dans la liste
            multiples16[nbTrouvees] = i;
            nbTrouvees++;
        }
    }
    
    // boucle de recherche pour 45
    // reinitialisation du nombre de multiples trouvés
    nbTrouvees = 0;
    for (short i = 45; i < 800; i++)
    {
        // tester si le nombre est un multiple de 16
        if (estMultipleDeA(i, 45))
        {
            // si oui alors l'enregistrer dans la liste
            multiples45[nbTrouvees] = i;
            nbTrouvees++;
        }
    }

    // boucle de recherche pour 60
    // reinitialisation du nombre de multiples trouvés
    nbTrouvees = 0;
    for (short i = 60; i < 800; i++)
    {
        // tester si le nombre est un multiple de 16
        if (estMultipleDeA(i, 60))
        {
            // si oui alors l'enregistrer dans la liste
            multiples60[nbTrouvees] = i;
            nbTrouvees++;
        }
    }

    // afficher les multiples
    printf("Multiples de 16:\n");
    for (short i = 0; i < 800; i++)
    {
        if (multiples16[i] != 0)
        {
            printf("%i, ", multiples16[i]);
        }
        else{
            break;
        }
    }
    printf("\nMultiples de 45:\n");
    for (short i = 0; i < 800; i++)
    {
        if (multiples45[i] != 0)
        {
            printf("%i, ", multiples45[i]);
        }
        else
        {
            break;
        }
    }
    printf("\nMultiples de 60:\n");
    for (short i = 0; i < 800; i++)
    {
        if (multiples60[i] != 0)
        {
            printf("%i, ", multiples60[i]);
        }
        else
        {
            break;
        }
    }
    printf("\n");

    // afficher les multiples commun
    printf("Multiples commun de 16 et 45\n");
    for (short i = 0; i < 800; i++)
    {
        if (listContain(multiples16, 800, multiples45[i]) && multiples45[i] != 0)
        {
            printf("%i, ", multiples45[i]);
        }
    }
    printf("\nMultiples commun de 16 et 60\n");
    for (short i = 0; i < 800; i++)
    {
        if (listContain(multiples16, 800, multiples60[i]) && multiples60[i] != 0)
        {
            printf("%i, ", multiples60[i]);
        }
    }
    printf("\nMultiples commun de 16, 45 et 60\n");
    for (short i = 0; i < 800; i++)
    {
        if (listContain(multiples16, 800, multiples60[i]) && listContain(multiples45, 800, multiples60[i]) && multiples60[i] != 0)
        {
            printf("%i", multiples60[i]);
        }
    }
    printf("\n");
}