#ifndef GAU_H
#define GAU_H

#include "timeseriesgenerator.h"

// Classe pour générer des séries temporelles selon une distribution gaussienne (normale)
class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;   // Moyenne de la distribution
    double stddev; // Écart type de la distribution
public:
    // Constructeur par défaut : initialise la graine aléatoire et utilise une moyenne de 0 et un écart type de 1.
    GaussianGenerator();

    // Constructeur paramétré : permet de définir la graine, la moyenne et l'écart type.
    GaussianGenerator(int seedVal, double meanVal, double stdVal);

    // Génère une série temporelle de taille donnée en utilisant la distribution gaussienne.
    virtual std::vector<double> generateTimeSeries(int length) override;
};

#endif
