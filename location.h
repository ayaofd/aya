#ifndef LOCATION_H_INCLUDED
#define LOCATION_H_INCLUDED

typedef struct{
    int id;
    char marque[30];
    char nom[30];
    char modele[30];
    char carburant[20];
    int nbp;
    float prix;
    char transmission[30];
    int dispo;
}Voiture;
void ajouterVoiture();
void afficherVoitures();
void modifierVoiture();
void rechercherVoiture();
void trierVoitures();

#endif // LOCATION_H_INCLUDED
