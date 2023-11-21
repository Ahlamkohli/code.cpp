#include <iostream>

// Fonction pour allouer dynamiquement une matrice carrée
int** allouerMatrice(int n) {
    int** matrice = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrice[i] = new int[n];
    }
    return matrice;
}

// Fonction pour libérer la mémoire allouée dynamiquement pour la matrice
void libererMatrice(int** matrice, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matrice[i];
    }
    delete[] matrice;
}

// Fonction pour initialiser la matrice A par la lecture
void initialiserMatrice(int** matrice, int n) {
    std::cout << "Veuillez entrer les elements de la matrice :" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "A[" << i << "][" << j << "]: ";
            std::cin >> matrice[i][j];
        }
    }
}

// Fonction pour calculer la somme de chaque ligne de A
int* sommeLignes(int** matrice, int n) {
    int* sommes = new int[n];
    for (int i = 0; i < n; ++i) {
        sommes[i] = 0;
        for (int j = 0; j < n; ++j) {
            sommes[i] += matrice[i][j];
        }
    }
    return sommes;
}

// Fonction pour calculer la somme de chaque colonne de A
int* sommeColonnes(int** matrice, int n) {
    int* sommes = new int[n];
    for (int j = 0; j < n; ++j) {
        sommes[j] = 0;
        for (int i = 0; i < n; ++i) {
            sommes[j] += matrice[i][j];
        }
    }
    return sommes;
}

// Fonction pour calculer la somme de la première diagonale de A
int sommePremiereDiagonale(int** matrice, int n) {
    int somme = 0;
    for (int i = 0; i < n; ++i) {
        somme += matrice[i][i];
    }
    return somme;
}

// Fonction pour calculer la somme de la deuxième diagonale de A
int sommeDeuxiemeDiagonale(int** matrice, int n) {
    int somme = 0;
    for (int i = 0; i < n; ++i) {
        somme += matrice[i][n - 1 - i];
    }
    return somme;
}

// Fonction pour vérifier si la matrice est un carré magique
bool estCarreMagique(int** matrice, int n) {
    int sommeRef = sommePremiereDiagonale(matrice, n);  // Utiliser la première diagonale comme référence
    int* sommesLignes = sommeLignes(matrice, n);
    int* sommesColonnes = sommeColonnes(matrice, n);

    // Vérifier la somme des lignes
    for (int i = 0; i < n; ++i) {
        if (sommesLignes[i] != sommeRef) {
            delete[] sommesLignes;
            delete[] sommesColonnes;
            return false;
        }
    }

    // Vérifier la somme des colonnes
    for (int j = 0; j < n; ++j) {
        if (sommesColonnes[j] != sommeRef) {
            delete[] sommesLignes;
            delete[] sommesColonnes;
            return false;
        }
    }

    delete[] sommesLignes;
    delete[] sommesColonnes;

    // Vérifier la somme de la deuxième diagonale
    return sommeDeuxiemeDiagonale(matrice, n) == sommeRef;
}

int main() {
    int n;

    // Demander à l'utilisateur la taille de la matrice
    std::cout << "Entrez la taille de la matrice carree : ";
    std::cin >> n;

    // Allouer dynamiquement la matrice
    int** matriceA = allouerMatrice(n);

    // Initialiser la matrice
    initialiserMatrice(matriceA, n);

    // Afficher la matrice
    std::cout << "Matrice A :" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matriceA[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Calculer et afficher la somme de chaque ligne
    int* sommesLignesA = sommeLignes(matriceA, n);
    std::cout << "Somme de chaque ligne de la matrice A :" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Ligne " << i + 1 << ": " << sommesLignesA[i] << std::endl;
    }
    delete[] sommesLignesA;

    // Calculer et afficher la somme de chaque colonne
    int* sommesColonnesA = sommeColonnes(matriceA, n);
    std::cout << "Somme de chaque colonne de la matrice A :" << std::endl;
    for (int j = 0; j < n; ++j) {
        std::cout << "Colonne " << j + 1 << ": " << sommesColonnesA[j] << std::endl;
    }
    delete[] sommesColonnesA;

    // Calculer et afficher la somme de la première diagonale
    int sommeDiagonale1 = sommePremiereDiagonale(matriceA, n);
    std::cout << "Somme de la premiere diagonale de la matrice A : " << sommeDiagonale1 << std::endl;

    // Calculer et afficher la somme de la deuxième diagonale
    int sommeDiagonale2 = sommeDeuxiemeDiagonale(matriceA, n);
    std::cout << "Somme de la deuxieme diagonale de la matrice A : " << sommeDiagonale2 << std::endl;

    // Vérifier si la matrice est un carré magique
    if (estCarreMagique(matriceA, n)) {
        std::cout << "La matrice A est un carre magique." << std::endl;
    } else {
        std::cout << "La matrice A n'est pas un carre magique." << std::endl;
    }

    // Libérer la mémoire allouée dynamiquement
    libererMatrice(matriceA, n);

    return 0;
}
