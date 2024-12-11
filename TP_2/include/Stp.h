#ifndef STP_H
#define STP_H

#include "timeseriesgenerator.h"

// Classe pour générer des séries temporelles avec une fonction de saut
class StepGenerator : public TimeSeriesGenerator {
public:
    // Constructeur par défaut : initialise une graine aléatoire.
    StepGenerator();

    // Constructeur paramétré : permet de définir une graine spécifique pour des résultats reproductibles.
    StepGenerator(int seedVal);

    // Génère une série temporelle de taille donnée selon une logique de saut :
    // - À chaque instant, une nouvelle valeur aléatoire entre 0 et 100 est choisie (50% de chance).
    // - Sinon, la valeur précédente est conservée.
    virtual std::vector<double> generateTimeSeries(int length) override;
};

#endif
