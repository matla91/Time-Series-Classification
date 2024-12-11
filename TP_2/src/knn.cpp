#include "knn.h"
#include "distance.h"
#include <algorithm> // Pour std::sort et std::find_if
#include <cctype>    // Pour std::isspace
#include <locale>    // Pour la gestion des caractères

// Fonction utilitaire : supprime les espaces en début et fin de chaîne
static std::string trim(const std::string &s) {
    std::string result = s;
    // Supprime les espaces au début
    result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](unsigned char ch) { return !std::isspace(ch); }));
    // Supprime les espaces à la fin
    result.erase(std::find_if(result.rbegin(), result.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), result.end());
    return result;
}

// Constructeur : initialise le nombre de voisins et la mesure de similarité
KNN::KNN(int kVal, const std::string &similarity) : k(kVal), similarityMeasure(trim(similarity)) {}

// Évalue la précision du classifieur sur le dataset de test
double KNN::evaluate(const TimeSeriesDataset &trainData, const TimeSeriesDataset &testData, const std::vector<int> &ground_truth) {
    int correct = 0;                   // Compteur de séries correctement classées
    int total = testData.getNumberOfSamples(); // Nombre total de séries de test

    // Boucle sur chaque série de test
    for (int i = 0; i < total; i++) {
        std::vector<double> testSeries = testData.getSeries(i); // Récupère la série
        int pred = predict(trainData, testSeries);             // Prédit son label
        if (pred == ground_truth[i]) {                         // Compare au label réel
            correct++;
        }
    }
    return (double)correct / total; // Retourne la précision (proportion de bonnes prédictions)
}

// Prédit le label d'une série de test
int KNN::predict(const TimeSeriesDataset &trainData, const std::vector<double> &testSeries) {
    int n = trainData.getNumberOfSamples(); // Nombre de séries d'entraînement

    // Structure pour stocker la distance et le label de chaque voisin
    struct Neighbor {
        double dist;
        int label;
    };
    std::vector<Neighbor> neighbors; // Liste des voisins
    neighbors.reserve(n);            // Réserve l'espace pour optimiser la performance

    // Calcule la distance entre la série de test et chaque série d'entraînement
    for (int i = 0; i < n; i++) {
        std::vector<double> trainSeries = trainData.getSeries(i); // Série d'entraînement
        double d = 0.0;

        // Choisit la mesure de similarité
        if (similarityMeasure == "euclidean_distance") {
            d = euclidean_distance(testSeries, trainSeries);
        } else if (similarityMeasure == "dtw") {
            d = dtw_distance(testSeries, trainSeries);
        } else if (similarityMeasure == "edr") {
            d = edr_distance(testSeries, trainSeries);
        } else {
            // Par défaut, utilise la distance euclidienne
            d = euclidean_distance(testSeries, trainSeries);
        }

        // Ajoute la distance et le label à la liste des voisins
        neighbors.push_back({d, trainData.getLabel(i)});
    }

    // Trie les voisins par distance croissante
    std::sort(neighbors.begin(), neighbors.end(), [](const Neighbor &a, const Neighbor &b) {
        return a.dist < b.dist;
    });

    // Trouve les k plus proches voisins
    std::vector<int> counts; // Compte les occurrences des labels parmi les k voisins
    int maxLabel = -1;       // Recherche le label le plus élevé pour dimensionner le vecteur `counts`
    for (auto &nb : neighbors) {
        if (nb.label > maxLabel) maxLabel = nb.label;
    }
    counts.resize(maxLabel + 1, 0); // Initialise le compteur des labels

    // Compte les labels des k voisins les plus proches
    for (int idx = 0; idx < k; idx++) {
        counts[neighbors[idx].label]++;
    }

    // Trouve le label majoritaire parmi les voisins
    int predicted = 0;
    int maxCount = counts[0];
    for (int c = 1; c < (int)counts.size(); c++) {
        if (counts[c] > maxCount) {
            maxCount = counts[c];
            predicted = c;
        }
    }

    return predicted; // Retourne le label majoritaire
}
