#include "stp.h"
#include <random>

// Constructeur par défaut : initialise la graine avec une valeur aléatoire.
StepGenerator::StepGenerator() : TimeSeriesGenerator() {}

// Constructeur paramétré : initialise la graine avec une valeur donnée (pour des résultats reproductibles).
StepGenerator::StepGenerator(int seedVal) : TimeSeriesGenerator(seedVal) {}

// Génère une série temporelle avec un comportement de saut
std::vector<double> StepGenerator::generateTimeSeries(int length) {
    // Générateur de nombres aléatoires basé sur la graine.
    std::mt19937 gen(seed);

    // Distribution pour les valeurs entières dans l'intervalle [0, 100].
    std::uniform_int_distribution<int> dist_val(0, 100);

    // Distribution pour générer une probabilité entre 0.0 et 1.0.
    std::uniform_real_distribution<double> dist_prob(0.0, 1.0);

    // Vecteur pour stocker la série temporelle, initialisée avec des zéros.
    std::vector<double> series(length, 0.0);
    series[0] = 0.0; // La première valeur est toujours 0.

    // Remplit le vecteur avec des valeurs générées.
    for (int i = 1; i < length; i++) {
        double p = dist_prob(gen); // Génère une probabilité aléatoire.
        if (p < 0.5) {
            // Avec 50% de chance, choisit une nouvelle valeur entre 0 et 100.
            series[i] = dist_val(gen);
        } else {
            // Sinon, conserve la valeur précédente.
            series[i] = series[i - 1];
        }
    }

    // Retourne la série générée.
    return series;
}
