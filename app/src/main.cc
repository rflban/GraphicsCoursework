#include "Pixmap.h"
#include "Painter.h"
#include "PPMGenerator.h"

#include <cstdio>
#include <cmath>

#include <iostream>
#include <random>
#include <map>

int main()
{
    Pixmap p(900, 900);
    Painter painter(&p);

    std::mt19937 gen(time(NULL));
    std::normal_distribution<> nd(0, 0.010);
    std::normal_distribution<> nd1(0, 1);

    double scale_ratio = 100;
    double radius = 3.5;
    double radius_core = 0.25;

    painter.fillRect(0, 0, 900, 900, { 0, 0, 0 });
    painter.setColor({ 255, 255, 255 });

    double ones[2] = { -1, 1 };

    double basemean = 1.5;
    double stddev;

    for (int idx = 0; idx < 1000; idx++)
    {
        double theta = M_PI * nd(gen);
        double r = radius * ((double)gen() / gen.max()) * ones[gen() % 2];

        if (fabs(r) <= radius_core)
        {
            theta = M_PI * nd1(gen);
        }

        //double mean = basemean * ((fabs(r) / radius));
        //double mean = basemean * (1 - exp((-(radius - fabs(r)) * (radius - fabs(r))) / 1));
        double mean = basemean * (2 / (fabs(r) / radius - 2) + 2);
        //double mean = basemean;
        stddev = mean * 0.5;

        std::normal_distribution<> nd2(mean, stddev / 3);
        std::cout << mean << ' ' << stddev << ' ' << nd2(gen) << '\n';

        double k = 1;

        if (fabs(r) > radius_core)
        {
            k += nd2(gen);
        }

        int x = round(r * cos(theta) * scale_ratio);
        //int y = round(r * sin(theta) * scale_ratio * 0.7);
        //int y = round(r * sin(theta) * scale_ratio * 1 + r * sin(theta * 4) * scale_ratio / 1 * (1 - fabs(r) / radius));
        //int y = round(r * sin(theta) * scale_ratio * 1 + r * sin(theta * 4) * scale_ratio / 1 * (2 / (fabs(r) / radius - 2) + 2));
        int y = round(r * sin(theta) * scale_ratio * k);
        //std::cout << mean << ' ' << stddev << ' ' << nd2(gen) << '\n';

        if (fabs(x) < radius_core * 4 * scale_ratio)
        {
            y *= k;
        }

        painter.fillPixel(450 + x, 450 + y);
    }

    ImageGenerator *generator = new PPMGenerator;
    FILE *fd = fopen("test.ppm", "w");

    generator->generate(fd, p);

    delete generator;
    fclose(fd);

    return 0;
}

