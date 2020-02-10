#include <cstdio>
#include <random>
#include <ctime>
#include <cmath>

#include "Pixmap.h"
#include "Painter.h"
#include "PPMGenerator.h"

#include "Geometry.h"
#include "SpiralGalaxy.h"
#include "GalaxyProperties.h"
#include "SGOrbitCalculator.h"
#include "SGStarDescriptor.h"

#include "SGRadiusDistributor.h"

void drawOrbit(Painter &painter, double a, double b, double angleOffset, const Perturbation &pert, size_t x0, size_t y0);

int main()
{
    srand(time(0));

    Pixmap p(900, 900);
    Painter painter(&p);

    SpiralGalaxy galaxy({0, 0, 0}, 3000, 20000, 0.45, 0.46, 25000);
    double scale_ratio = 400.0 / 60000;

    painter.fillRect(0, 0, 900, 900, {0, 0, 0});

    painter.setColor({255, 0, 0});
    painter.drawEllipse(450, 450, (size_t)(scale_ratio * galaxy.getRaiusCore()), (size_t)(scale_ratio * galaxy.getRaiusCore()));
    painter.setColor({0, 255, 0});
    painter.drawEllipse(450, 450, (size_t)(scale_ratio * galaxy.getRadiusDisk()), (size_t)(scale_ratio * galaxy.getRadiusDisk()));

    painter.setColor({255, 255, 255});

    double dr = 750;
    double dteta = M_PI / 48;
    for (double r = 1.0 / 5 * galaxy.getRaiusCore(), teta = 0; r < galaxy.getRadiusDisk() + 20000; r += dr, teta += dteta)
    {
        double a = r;
        double b = sqrt(a * a - pow(galaxy.getEccentricity(r), 2) * a * a);

        //painter.drawEllipse(450, 450, (size_t)(scale_ratio * a), (size_t)(scale_ratio * b), -galaxy.getAngularOffset(r));
        //painter.drawEllipse(450, 450, (size_t)(scale_ratio * a), (size_t)(scale_ratio * b), M_PI/4);
        drawOrbit(painter, scale_ratio * a, scale_ratio * b, galaxy.getAngularOffset(r), {4, 40}, 450, 450);
    }

    ImageGenerator *generator = new PPMGenerator;
    FILE *fd = fopen("orbits.ppm", "w");

    generator->generate(fd, p);

    fclose(fd);

    painter.fillRect(0, 0, 900, 900, {0, 0, 0});

    Vector2D pos;
    SGStarDescriptor s;
    for (size_t idx = 0; idx < galaxy.getStarsQty(); idx++)
    {
        s = galaxy.getStars()[idx];
        pos = SGOrbitCalculator::calculate(s.a, s.b, s.angularOffset, {4, 40}, s.angularPos);
        pos = SGOrbitCalculator::calculate(scale_ratio * s.a, scale_ratio * s.b, s.angularOffset, {4, 40}, s.angularPos);

        printf("%lf\n", s.a);

        ubyte c = (ubyte)(round(255 * s.brightness));

        painter.fillPixel(450 + (size_t)round(pos.x), 450 + (size_t)round(pos.y),
                          { c, c, c });
    }

    fd = fopen("stars.ppm", "w");
    generator->generate(fd, p);
    fclose(fd);

    std::mt19937 gen(time(NULL));
    std::normal_distribution<> nd(0, 0.005 * galaxy.getRaiusCore()*1e-3);
    std::normal_distribution<> nd1(0, 1);

    double ones[2] = { -1, 1 };

    painter.fillRect(0, 0, 900, 900, {0, 0, 0});

    for (size_t idx = 0; idx < galaxy.getStarsQty(); idx++)
    {
        s = galaxy.getStars()[idx];
        auto pos0 = SGOrbitCalculator::calculate(s.a, s.b, s.angularOffset, {4, 40}, s.angularPos);
        pos = SGOrbitCalculator::calculate(scale_ratio * s.a, scale_ratio * s.b, s.angularOffset, {4, 40}, s.angularPos);

        printf("%lf\n", s.a);

        ubyte c = (ubyte)(round(255 * s.brightness));

        double r = sqrt(pos0.x*pos0.x + pos0.y*pos0.y);
        double theta;
        theta = 2*M_PI * nd(gen);

        if (fabs(sqrt(r*r*r*r*sin(theta)*sin(theta))) <= galaxy.getRaiusCore())
        {
            //theta = 2*M_PI * ((double)gen() / gen.max());
            theta = 2*M_PI * nd1(gen);
        }

        double z = r * sin(theta) * scale_ratio;

        painter.fillPixel(450 + (size_t)round(r*scale_ratio * ones[gen() % 2]), 450 + (size_t)round(z),
                          { c, c, c });
        //painter.fillPixel(450 + (size_t)round(pos.x), 450 + (size_t)round(z),
                          //{ c, c, c });
    }

    fd = fopen("RZ.ppm", "w");
    generator->generate(fd, p);
    fclose(fd);

    painter.fillRect(0, 0, 900, 900, {0, 0, 0});

    for (size_t idx = 0; idx < galaxy.getStarsQty(); idx++)
    {
        s = galaxy.getStars()[idx];
        auto pos0 = SGOrbitCalculator::calculate(s.a, s.b, s.angularOffset, {4, 40}, s.angularPos);
        pos = SGOrbitCalculator::calculate(scale_ratio * s.a, scale_ratio * s.b, s.angularOffset, {4, 40}, s.angularPos);

        printf("%lf\n", s.a);

        ubyte c = (ubyte)(round(255 * s.brightness));

        double r = sqrt(pos0.x*pos0.x + pos0.y*pos0.y);
        double theta;
        theta = 2*M_PI * nd(gen);

        if (fabs(sqrt(r*r*r*r*sin(theta)*sin(theta))) <= galaxy.getRaiusCore())
        {
            //theta = 2*M_PI * ((double)gen() / gen.max());
            theta = 2*M_PI * nd1(gen);
        }

        double z = r * sin(theta) * scale_ratio;

        painter.fillPixel(450 + (size_t)round(pos.x), 450 + (size_t)round(z),
                          { c, c, c });
    }

    fd = fopen("XZ.ppm", "w");
    generator->generate(fd, p);
    fclose(fd);

    painter.fillRect(0, 0, 900, 900, {0, 0, 0});

    for (size_t idx = 0; idx < galaxy.getStarsQty(); idx++)
    {
        s = galaxy.getStars()[idx];
        auto pos0 = SGOrbitCalculator::calculate(s.a, s.b, s.angularOffset, {4, 40}, s.angularPos);
        pos = SGOrbitCalculator::calculate(scale_ratio * s.a, scale_ratio * s.b, s.angularOffset, {4, 40}, s.angularPos);

        printf("%lf\n", s.a);

        ubyte c = (ubyte)(round(255 * s.brightness));

        double r = sqrt(pos0.x*pos0.x + pos0.y*pos0.y);
        double theta;
        theta = 2*M_PI * nd(gen);

        if (fabs(sqrt(r*r*r*r*sin(theta)*sin(theta))) <= galaxy.getRaiusCore())
        {
            //theta = 2*M_PI * ((double)gen() / gen.max());
            theta = 2*M_PI * nd1(gen);
        }

        double z = r * sin(theta) * scale_ratio;

        painter.fillPixel(450 + (size_t)round(pos.y), 450 + (size_t)round(z),
                          { c, c, c });
    }

    fd = fopen("YZ.ppm", "w");
    generator->generate(fd, p);
    fclose(fd);

    painter.fillRect(0, 0, 900, 900, {0, 0, 0});

    for (size_t idx = 0; idx < galaxy.getStarsQty(); idx++)
    {
        s = galaxy.getStars()[idx];
        auto pos0 = SGOrbitCalculator::calculate(s.a, s.b, s.angularOffset, {4, 40}, s.angularPos);
        pos = SGOrbitCalculator::calculate(scale_ratio * s.a, scale_ratio * s.b, s.angularOffset, {4, 40}, s.angularPos);

        printf("%lf\n", s.a);

        ubyte c = (ubyte)(round(255 * s.brightness));

        double r = sqrt(pos0.x*pos0.x + pos0.y*pos0.y);
        double theta;
        theta = 2*M_PI * nd(gen);

        if (fabs(sqrt(r*r*r*r*sin(theta)*sin(theta))) <= galaxy.getRaiusCore())
        {
            //theta = 2*M_PI * ((double)gen() / gen.max());
            theta = 2*M_PI * nd1(gen);
        }

        double z = r * sin(theta) * scale_ratio;

        double cx = sqrt(3)*pos.x - sqrt(3)*z;
        double cy = pos.x + 2*pos.y + z;
        double cz = sqrt(2)*pos.x - sqrt(2)*pos.y + sqrt(2)*z;

        painter.fillPixel(450 + (size_t)round(cx), 450 + (size_t)round(cy),
                          { c, c, c });
    }

    fd = fopen("isometric.ppm", "w");
    generator->generate(fd, p);
    fclose(fd);

    painter.fillRect(0, 0, 900, 900, {0, 0, 0});

    for (size_t idx = 0; idx < galaxy.getStarsQty(); idx++)
    {
        s = galaxy.getStars()[idx];
        auto pos0 = SGOrbitCalculator::calculate(s.a, s.b, s.angularOffset, {4, 40}, s.angularPos);
        pos = SGOrbitCalculator::calculate(scale_ratio * s.a, scale_ratio * s.b, s.angularOffset, {4, 40}, s.angularPos);

        printf("%lf\n", s.a);

        ubyte c = (ubyte)(round(255 * s.brightness));

        double r = sqrt(pos0.x*pos0.x + pos0.y*pos0.y);
        double theta;
        theta = 2*M_PI * nd(gen);

        if (fabs(sqrt(r*r*r*r*sin(theta)*sin(theta))) <= galaxy.getRaiusCore())
        {
            //theta = 2*M_PI * ((double)gen() / gen.max());
            theta = 2*M_PI * nd1(gen);
        }

        double z = r * sin(theta) * scale_ratio;

        double alpha = M_PI / 6;
        //double cx = pos.x*cos(alpha) - pos.y*sin(alpha);
        //double cy = pos.x*sin(alpha) + cos(alpha);
        //double cz = z;
        double cx = pos.x;
        double cy = pos.y;
        double cz = z;

        double beta = M_PI / 2;
        double bx = cx;
        double by = cy*cos(beta) - cz*sin(beta);
        double bz = cy*sin(beta) + cz*cos(beta);

        painter.fillPixel(450 + (size_t)round(bx), 450 + (size_t)round(bz),
                          { c, c, c });
    }

    fd = fopen("projection.ppm", "w");
    generator->generate(fd, p);
    fclose(fd);

    delete generator;
    return 0;
}

void drawOrbit(Painter &painter, double a, double b, double angleOffset, const Perturbation &pert, size_t x0, size_t y0)
{
    double h = 1 / std::fmax(a, b);
    double pi_m_2 = 2 * M_PI;

    SGOrbitCalculator calculator(a, b, angleOffset, pert);

    for (double t = 0; t < pi_m_2; t += h)
    {
        Vector2D pos = calculator.calculate(t);

        painter.fillPixel(x0 + (size_t)round(pos.x), y0 + (size_t)round(pos.y));
    }
}

