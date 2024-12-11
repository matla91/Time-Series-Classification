#include "sin.h"
#include <cmath>

SinWaveGenerator::SinWaveGenerator() : TimeSeriesGenerator(), A(1.0), w(2.0*M_PI/10.0), phi(0.0) {}
SinWaveGenerator::SinWaveGenerator(int seedVal, double amplitude, double freq, double phase)
: TimeSeriesGenerator(seedVal), A(amplitude), w(freq), phi(phase) {}

std::vector<double> SinWaveGenerator::generateTimeSeries(int length) {
    std::vector<double> series(length,0.0);
    for (int i = 0; i < length; i++) {
        series[i] = A * std::sin(w * i + phi);
    }
    return series;
}
