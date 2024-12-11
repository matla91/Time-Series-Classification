#ifndef TSDATA_H
#define TSDATA_H

#include <vector>
#include <cmath>
#include <stdexcept>

// Classe pour représenter un ensemble de séries temporelles (entraînement ou test)
class TimeSeriesDataset {
private:
    bool znormalize;                  // Indique si les séries doivent être normalisées (Z-normalization)
    bool isTrain;                     // Indique si cet ensemble est pour l'entraînement (true) ou le test (false)
    std::vector<double> data;         // Contient les séries temporelles stockées de manière séquentielle
    std::vector<int> labels;          // Contient les étiquettes des séries (uniquement pour l'entraînement)
    int maxLength;                    // Longueur maximale des séries
    int numberOfSamples;              // Nombre total de séries dans l'ensemble

public:
    // Constructeur : initialise le dataset avec les paramètres de normalisation et le type (entraînement/test)
    TimeSeriesDataset(bool znormalize, bool isTrain);

    // Ajoute une série temporelle avec un label (uniquement pour les données d'entraînement)
    void addTimeSeries(const std::vector<double> &series, int label);

    // Ajoute une série temporelle sans label (uniquement pour les données de test)
    void addTimeSeries(const std::vector<double> &series);

    // Retourne le nombre total de séries dans l'ensemble
    int getNumberOfSamples() const;

    // Retourne la longueur des séries (toutes les séries ont la même longueur)
    int getSeriesLength() const;

    // Retourne une série temporelle à partir de son index
    std::vector<double> getSeries(int index) const;

    // Retourne le label d'une série (uniquement pour l'entraînement)
    int getLabel(int index) const;

    // Indique si cet ensemble est destiné à l'entraînement
    bool isTrainingSet() const { return isTrain; }

private:
    // Effectue une Z-normalisation sur une série temporelle
    std::vector<double> zNormalizeSeries(const std::vector<double> &series) const;
};

#endif
