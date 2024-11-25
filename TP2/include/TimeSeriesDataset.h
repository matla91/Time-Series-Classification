#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>
#include <numeric> // Pour std::accumulate
#include <cmath>   // Pour std::sqrt
#include <stdexcept> // Pour std::invalid_argument

class TimeSeriesDataset
{
    public:
        TimeSeriesDataset(bool znormalize, bool isTrain, vector<double> data, vector<int> labels, int maxLength, int numberOfSamples)
            :znormalize(znormalize), isTrain(isTrain), data(data), labels(labels), maxLength(maxLength), numberOfSamples(numberOfSamples){
                if(znormalize){
                    applyZNormalization();
                }
            }
        virtual ~TimeSeriesDataset();

    protected:
        bool znormalize;        // Indique si les données doivent être normalisées
        bool isTrain;           // Indique s'il s'agit d'un ensemble d'entraînement
        std::vector<double> data;  // Données des séries temporelles
        std::vector<int> labels;   // Étiquettes des séries
        int maxLength;          // Longueur maximale d'une série
        int numberOfSamples;    // Nombre d'échantillons dans le dataset

    private:
        void applyZNormalization(int sizeSerie, double x){

            for(int i, i < sizeSerie, i++){
                x = series[i];
                x = (x - mean(data))/stddev(data);
                series.push_back(x)
            }
        }

};

#endif // TIMESERIESDATASET_H
