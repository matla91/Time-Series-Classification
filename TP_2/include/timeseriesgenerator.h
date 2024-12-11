#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include <vector>
#include <iostream>
#include <random>

class TimeSeriesGenerator {
protected:
    int seed;
public:
    TimeSeriesGenerator();
    TimeSeriesGenerator(int seedVal);
    virtual ~TimeSeriesGenerator() {}

    // Génère une série temporelle de taille length
    virtual std::vector<double> generateTimeSeries(int length) = 0;

    // Affiche une série temporelle
    static void printTimeSeries(const std::vector<double> &ts);
};

#endif
