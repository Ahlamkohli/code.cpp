#include <iostream>

// Définition de la structure point
struct Point {
    float abscisse;
    float ordonnee;
};

// Fonction pour créer et remplir un tableau dynamique A[N][N] de type Point
Point** creerEtRemplirTableau(int N) {
    // Allouer dynamiquement la mémoire pour le tableau de pointeurs
    Point** tableau = new Point*[N];
    for (int i = 0; i < N; ++i) {
        tableau[i] = new Point[N];
    }

    // Remplir le tableau avec les coordonnées des points
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << "Entrez l'abscisse du point A[" << i << "][" << j << "]: ";
            std::cin >> tableau[i][j].abscisse;
            std::cout << "Entrez l'ordonnee du point A[" << i << "][" << j << "]: ";
            std::cin >> tableau[i][j].ordonnee;
        }
    }

    return tableau;
}

// Fonction pour libérer la mémoire allouée dynamiquement pour le tableau
void libererTableau(Point** tableau, int N) {
    
    for (int i = 0; i < N; ++i) {
        delete[] tableau[i];
    }
    delete[] tableau;
}

int main() {
    int N;

    // Demander à l'utilisateur la taille du tableau
    std::cout << "Entrez la taille du tableau A[N][N] : ";
    std::cin >> N;

    // Appeler la fonction pour créer et remplir le tableau
    Point** tableauA = creerEtRemplirTableau(N);

    // Afficher les coordonnées des points dans le tableau
    std::cout << "Tableau A[N][N] :" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << "(" << tableauA[i][j].abscisse << ", " << tableauA[i][j].ordonnee << ") ";
        }
        std::cout << std::endl;
    }

    // Appeler la fonction pour libérer la mémoire allouée dynamiquement
    libererTableau(tableauA, N);

    return 0;
}
