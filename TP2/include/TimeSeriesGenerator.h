#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include <vector>
#include <iostream>

class TimeSeriesGenerator
{
    public:
        TimeSeriesGenerator():seed(0);
        TimeSeriesGenerator(int s):seed(s);
        virtual ~TimeSeriesGenerator();

        virtual std::vector<double> generateTimeSeries(int sizeSerie) = 0;

        static void printTimeSeries(const std::vector<double>& series) {
            for (double value : series) {
                std::cout << value << " ";
            }
        std::cout << std::endl;
        }

    protected:
        int seed;

    private:

};

#endif // TIMESERIESGENERATOR_H
