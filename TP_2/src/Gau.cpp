#include "gau.h"
#include <cmath>
#include <random>

// Constructeurs par défaut
GaussianGenerator::GaussianGenerator() : TimeSeriesGenerator(), mean(0.0), stddev(1.0) {}

GaussianGenerator::GaussianGenerator(int seedVal, double meanVal, double stdVal)
: TimeSeriesGenerator(seedVal), mean(meanVal), stddev(stdVal) {}

std::vector<double> GaussianGenerator::generateTimeSeries(int length) {
    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    std::vector<double> series(length,0.0);

    // Méthode de Box-Muller
    for (int i = 0; i < length; i++) {
        double u1 = dist(gen);
        double u2 = dist(gen);
        double z = std::sqrt(-2.0 * std::log(u1)) * std::cos(2.0 * M_PI * u2);
        series[i] = mean + z * stddev;
    }

    return series;
}
