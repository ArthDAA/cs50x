#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Nombre maximal de candidats
#define MAX 9

// Les candidats ont un nom et un nombre de votes
typedef struct
{
    string name;
    int votes;
} candidate;

// Tableau de candidats
candidate candidates[MAX];

// Nombre de candidats
int candidate_count;

// Prototypes des fonctions
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Vérification de l'utilisation incorrecte
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Remplissage du tableau des candidats
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Nombre maximal de candidats est %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Demander le nombre d'électeurs
    int voter_count = get_int("Nombre d'électeurs : ");

    // Boucle pour tous les électeurs
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote : ");

        // Vérification du vote invalide
        if (!vote(name))
        {
            printf("Vote invalide.\n");
        }
    }

    // Afficher le(s) gagnant(s) de l'élection
    print_winner();
}

// Mettre à jour les votes en fonction d'un nouveau vote
bool vote(string name)
{
    int i;
    i = 0;
    while(i < candidate_count)
    {
        if(strcmp(name, candidate[i].name))
        {
            return(1);
        }
    }
    return false;
}

// Afficher le(s) gagnant(s) de l'élection
void print_winner(void)
{
    // TODO : Ajouter la logique pour déterminer et afficher le gagnant
    return;
}
