#include "timeseriesgenerator.h"

// Constructeur par défaut : initialise la graine de manière aléatoire.
TimeSeriesGenerator::TimeSeriesGenerator() : seed(std::random_device{}()) {}

// Constructeur paramétré : utilise une graine donnée par l'utilisateur pour générer des résultats reproductibles.
TimeSeriesGenerator::TimeSeriesGenerator(int seedVal) : seed(seedVal) {}

// Fonction statique : affiche les valeurs d'une série temporelle.
void TimeSeriesGenerator::printTimeSeries(const std::vector<double> &ts) {
    for (auto &val : ts) {
        std::cout << val << " "; // Affiche chaque valeur séparée par un espace.
    }
    std::cout << std::endl;
}
