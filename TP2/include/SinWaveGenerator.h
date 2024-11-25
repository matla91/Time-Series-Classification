#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

#include <vector>
#include <cmath> // Pour std::sin
#include "TimeSeriesGenerator.h"

class SinWaveGenerator : public TimeSeriesGenerator {
public:

    SinWaveGenerator(int s, double A, double w, double phi)
        : TimeSeriesGenerator(s), amplitude(A), frequency(w), phase(phi) {}
    virtual ~SinWaveGenerator() {}


    std::vector<double> generateTimeSeries(int sizeSerie) override {
        std::vector<double> series;

        for (int x = 0; x < sizeSerie; ++x) {

            double f = amplitude * std::sin(frequency * x + phase);
            series.push_back(f);
        }

        return series;
    }

private:
    double amplitude;
    double frequency;
    double phase;
};

#endif // SINWAVEGENERATOR_H
