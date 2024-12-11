#ifndef SIN_H
#define SIN_H

#include "timeseriesgenerator.h"

// Classe pour générer des séries temporelles basées sur une fonction sinusoïdale
class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double A;   // Amplitude de l'onde (hauteur maximale)
    double w;   // Fréquence angulaire de l'onde (contrôle le nombre de cycles)
    double phi; // Phase initiale (décalage horizontal)

public:
    // Constructeur par défaut : initialise une onde sinus avec des valeurs standard.
    SinWaveGenerator();

    // Constructeur paramétré : permet de définir une graine, l'amplitude, la fréquence et la phase.
    SinWaveGenerator(int seedVal, double amplitude, double freq, double phase);

    // Génère une série temporelle de taille donnée selon l'équation d'une onde sinusoïdale :
    // f(x) = A * sin(w * x + phi)
    virtual std::vector<double> generateTimeSeries(int length) override;
};

#endif
