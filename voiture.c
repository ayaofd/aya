
// Fonction pour ajouter une voiture
void ajouterVoiture() {
    Voiture v;
    printf("Entrez les informations de la voiture :\n");
    printf("ID : ");
    scanf("%d", &v.id);
    printf("Marque : ");
    scanf("%s", v.marque);
    printf("Nom d'utilisateur : ");
    scanf("%s", v.nom);
    printf("Modèle : ");
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

    fprintf(fichier, "%d,%s,%s,%s,%s,%d,%s,%d,%d\n",
            v.id, v.marque, v.nom, v.modele, v.carburant,
            v.places, v.transmission, v.prix, v.dispo);
    fclose(fichier);

    printf("Voiture ajoutée avec succès !\n");
}


void afficherVoitures() {
    FILE *fichier = fopen("voitures.csv", "r");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier !\n");
        return;
    }

    Voiture v;
    printf("Liste des voitures disponibles :\n");
    printf("ID | Marque | Modèle | Carburant | Places | Transmission | Prix/jour | Disponibilité\n");
    while (fscanf(fichier, "%d,%s[^,],%s[^,],%s[^,],%s[^,],%d,%s[^,],%d,%d\n",
                  &v.id, v.marque, v.utilisateur, v.modele, v.carburant,
                  &v.places, v.transmission, &v.prixParJour, &v.disponible) != EOF) {
        printf("%d | %s | %s | %s | %d | %s | %.2f | %s\n",
               v.id, v.marque, v.modele, v.carburant, v.places,
               v.transmission, v.prixParJour, v.disponible ? "Disponible" : "Non disponible");
    }
    fclose(fichier);
}
