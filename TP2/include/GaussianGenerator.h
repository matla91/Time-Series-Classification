#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include <vector>
#include <cmath> // Pour log, sqrt, cos, sin
#include <random> // Pour générer des nombres aléatoires uniformes
#include "TimeSeriesGenerator.h"

class GaussianGenerator:public TimeSeriesGenerator
{
    public:
        GaussianGenerator(int s, double mean, double stddev):TimeSeriesGenerator(s), mean(mean), stddev(stddev){}
        virtual ~GaussianGenerator();

        std::vector<double> generateTimeSeries(int sizeSerie){
            std::vector<double> series;
            std::default_random_engine generator(seed); // Générateur aléatoire basé sur seed
            std::uniform_real_distribution<double> distribution(0.0, 1.0); // Distribution uniforme

            for(int i = 0, i < sizeSerie, i+=2){
                double u1 = distribution(generator);
                double u2 = distribution(generator);

                double Z0 = std::sqrt(-2.0 * std::log(U1)) * std::cos(2.0 * M_PI * U2);
                double Z1 = std::sqrt(-2.0 * std::log(U1)) * std::sin(2.0 * M_PI * U2);

                double x0 = mean + stddev * z0;
                double x1 = mean + stddev * z1;

                series.push_back(x0);
                if(series < sizeSerie){
                    series.push_back(x1)
                }
            }
            return series;
        }

    protected:
        double mean;
        double stddev;

    private:
};

#endif // GAUSSIANGENERATOR_H
