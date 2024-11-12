#include "Trigonometry.h"

namespace Qm
{
    double cos(double x)
    {
        double Rangex = std::fmod(std::abs(x), (2 * PI));
        int signe = 1;
        if (Rangex > (PI / 2))
        {
            signe = -1;
            Rangex = (PI - Rangex);
        }
        return ((double)signe * (1
            - (pow(Rangex, 2) / 2)
            + (pow(Rangex, 4) / (4 * 3 * 2))
            - (pow(Rangex, 6) / (6 * 5 * 4 * 3 * 2))
            + (pow(Rangex, 8) / (8 * 7 * 6 * 5 * 4 * 3 * 2))
            - (pow(Rangex, 10) / (10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2))
            + (pow(Rangex, 12) / (12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2))
            ));
    }

    double sin(double x)
    {
        return cos(x - PI / 2);
    }
}