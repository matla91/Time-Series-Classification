#include <stdexcept>
#include "distance.h"
#include <algorithm>

double euclidean_distance(const std::vector<double> &x, const std::vector<double> &y) {
    if (x.size() != y.size()) {
        throw std::runtime_error("Euclidean distance: series must have same length");
    }
    double sum = 0.0;
    for (size_t i = 0; i < x.size(); i++) {
        double diff = x[i] - y[i];
        sum += diff*diff;
    }
    return std::sqrt(sum);
}

double dtw_distance(const std::vector<double> &x, const std::vector<double> &y) {
    if (x.size() != y.size()) {
        throw std::runtime_error("DTW: series must have same length");
    }
    int L = (int)x.size();
    std::vector<double> prev(L+1, std::numeric_limits<double>::infinity());
    std::vector<double> curr(L+1, std::numeric_limits<double>::infinity());

    prev[0] = 0.0;
    for (int i = 1; i <= L; i++) {
        curr[0] = std::numeric_limits<double>::infinity();
        for (int j = 1; j <= L; j++) {
            double cost = (x[i-1] - y[j-1])*(x[i-1] - y[j-1]);
            double val = std::min({prev[j],    // delete
                                   curr[j-1],  // insert
                                   prev[j-1]   // match
                                 }) + cost;
            curr[j] = val;
        }
        prev = curr;
    }

    return std::sqrt(prev[L]);
}

static bool match_edr(double a, double b, double epsilon) {
    return std::fabs(a-b) <= epsilon;
}

double edr_distance(const std::vector<double> &x, const std::vector<double> &y, double epsilon) {
    // EDR est similaire à une distance d'édition
    // On compte le nombre de mismatch, insertions, deletions.
    // Distance = edit distance entre x et y avec condition de match sur epsilon.
    int m = (int)x.size();
    int n = (int)y.size();

    std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1,0));
    for (int i=1; i<=m; i++) {
        dp[i][0] = i;
    }
    for (int j=1; j<=n; j++) {
        dp[0][j] = j;
    }

    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (match_edr(x[i-1], y[j-1], epsilon)) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }

    // On peut retourner dp[m][n] en tant que distance. EDR est souvent une mesure,
    // On normalise éventuellement par la taille. Mais ce n'est pas spécifié.
    return (double)dp[m][n];
}
