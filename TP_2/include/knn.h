#ifndef KNN_H
#define KNN_H

#include <string>
#include <vector>
#include "tsdata.h"

// Classe pour implémenter un classifieur K-Nearest Neighbors (KNN)
class KNN {
private:
    int k;                          // Nombre de voisins à considérer
    std::string similarityMeasure;  // Mesure de similarité ("dtw", "euclidean_distance", etc.)

public:
    // Constructeur : initialise le nombre de voisins et la mesure de similarité
    KNN(int k, const std::string &similarity);

    // Évalue les performances du KNN en calculant la précision sur le dataset de test
    // trainData : données d'entraînement avec labels
    // testData : données de test sans labels
    // ground_truth : labels réels des données de test
    double evaluate(const TimeSeriesDataset &trainData, const TimeSeriesDataset &testData, const std::vector<int> &ground_truth);

private:
    // Prédit le label d'une série de test en fonction des données d'entraînement
    // Retourne le label le plus probable basé sur les k voisins les plus proches
    int predict(const TimeSeriesDataset &trainData, const std::vector<double> &testSeries);
};

#endif
