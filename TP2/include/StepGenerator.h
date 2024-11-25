#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include <vector>
#include <random> // Pour le générateur aléatoire moderne
#include "TimeSeriesGenerator.h"

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator(int s) : TimeSeriesGenerator(s) {}
    virtual ~StepGenerator() {}

    std::vector<double> generateTimeSeries(int sizeSerie) override {
        std::vector<double> series;
        std::default_random_engine generator(seed); // Générateur aléatoire basé sur seed
        std::uniform_int_distribution<int> valueDistribution(0, 100); // Pour les valeurs entre 0 et 100
        std::uniform_int_distribution<int> decisionDistribution(0, 1); // Pour décider de garder ou non

        int currentValue = 0;
        series.push_back(currentValue);

        for (int i = 1; i < sizeSerie; ++i) {

            if (decisionDistribution(generator) == 1) {
                currentValue = valueDistribution(generator);
            }

            series.push_back(currentValue);
        }

        return series;
    }
};

#endif // STEPGENERATOR_H
