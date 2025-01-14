#include <stdio.h>
#include <string.h>
#include "location.h"
void ajouterVoiture() {
    Voiture v;
    printf("Entrez les informations de la voiture :\n");
    printf("ID : ");
    scanf("%d", &v.id);
    printf("Marque : ");
    scanf("%s", v.marque);
    printf("Nom d'utilisateur : ");
    scanf("%s", v.nom);
    printf("Modele : ");
    scanf("%s", v.modele);
    printf("Type de carburant : ");
    scanf("%s", v.carburant);
    printf("Nombre de places : ");
    scanf("%d", &v.nbp);
    printf("Transmission (automatique/manuelle) : ");
    scanf("%s", v.transmission);
    printf("Prix par jour : ");
    scanf("%f", &v.prix);
    printf("Disponible (1 = Oui, 0 = Non) : ");
    scanf("%d", &v.dispo);

    FILE *fichier = fopen("voitures.csv", "a");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier !\n");
        return;
    }

    fprintf(fichier, "%d,%s,%s,%s,%s,%d,%s,%f,%d\n",
            v.id, v.marque, v.nom, v.modele, v.carburant,
            v.nbp, v.transmission, v.prix, v.dispo);
    fclose(fichier);

    printf("Voiture ajoutee avec succes !\n");
}


void afficherVoitures() {
    FILE *fichier = fopen("voitures.csv", "r");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier !\n");
        return;
    }

    Voiture v;
    printf("Liste des voitures disponibles :\n");
    printf("ID | Marque | Modele | Carburant | Places | Transmission | Prix/jour | Disponibilite\n");
    while (fscanf(fichier, "%d,%s[^,],%s[^,],%s[^,],%s[^,],%d,%s[^,],%f,%d\n",
                  &v.id, v.marque, v.nom, v.modele, v.carburant,
                  &v.nbp, v.transmission, &v.prix, &v.dispo) != EOF) {
        printf("%d | %s | %s | %s | %d | %s | %.2f | %s\n",
               v.id, v.marque, v.modele, v.carburant, v.nbp,
               v.transmission, v.prix, v.dispo ? "Disponible" : "Non disponible");
    }
    fclose(fichier);
}
void modifierVoiture(Voiture v[], int nb_voitures) {
    int id;
    printf("Entrez l'ID de la voiture à modifier: ");
    scanf("%d", &id);
    for (int i = 0; i < nb_voitures; i++) {
        if (v[i].id == id) {
            printf("Entrez la nouvelle marque: ");
            scanf("%s", v[i].marque);
            printf("Entrez le nouveau modèle: ");
            scanf("%s", v[i].modele);
            printf("Entrez le nouveau type de carburant: ");
            scanf("%s", v[i].carburant);
            printf("Entrez le nouveau nombre de places: ");
            scanf("%d", &v[i].nbp);
            printf("Entrez la nouvelle transmission: ");
            scanf("%s", v[i].transmission);
            printf("Entrez le nouveau prix de location par jour: ");
            scanf("%f", &v[i].prix);
            afficherVoitures(v);
            printf("Voiture modifiée avec succès.\n");
            return;
        }
    }
   printf("voiture non trouvee.\n");
}
void supprimerVoiture(Voiture voitures[], int nb_voitures) {
    int id2;
    printf("Entrez l'ID de la voiture a supprimer: ");
    scanf("%d", &id2);
    for (int i = 0; i <nb_voitures; i++) {
        if (voitures[i].id == id2) {
            for (int j = i; j < nb_voitures - 1; j++) {
                voitures[j] = voitures[j + 1];
            }
            (nb_voitures)--;
            afficherVoitures(voitures, nb_voitures);
            printf("Voiture supprimée avec succès.\n");
            return;
        }
    }
    printf("Voiture non trouvée.\n");
}
void rechercherVoiture(Voiture v[], int nbVoitures, char marque[]) {
    for (int i = 0; i < nbVoitures; i++) {
        if (strcmp(v[i].marque, marque) == 0)
            printf("ID: %d, Modèle: %s, Prix: %f", v[i].id, v[i].modele, v[i].prix);
}
}
void trierVoitures(Voiture v[], int nbVoitures) {
    for (int i = 0; i < nbVoitures - 1; i++) {
        for (int j = i + 1; j < nbVoitures; j++) {
            if (v[i].prix > v[j].prix) {
                Voiture temp = v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
 }
}

