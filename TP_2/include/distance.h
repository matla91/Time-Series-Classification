#ifndef DISTANCE_H
#define DISTANCE_H

#include <vector>
#include <cmath>
#include <limits>

double euclidean_distance(const std::vector<double> &x, const std::vector<double> &y);
double dtw_distance(const std::vector<double> &x, const std::vector<double> &y);

// Bonus : EDR (Edit Distance on Real Sequences) ou EDS
// On suppose un epsilon par défaut. C'est une distance d'édition similaire au DTW.
// On peut se limiter à un epsilon simple, p.ex. 0.1 ou un paramètre interne.
double edr_distance(const std::vector<double> &x, const std::vector<double> &y, double epsilon=0.1);

#endif
