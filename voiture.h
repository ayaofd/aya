#include <stdio.h>
#include <string.h>
#include "voiture.h"

typedef struct{
    int id;
    char marque[30];
    char nom[30];
    char modele[30];
    char carburant[20];
    int nbp;
    int prix;
    char transmission[30];
    bool dispo;
}Voiture;
void ajouterVoiture(fichier,Voiture v);
void afficherVoitures();
void modifierVoiture();
void rechercherVoiture();
void trierVoitures();
