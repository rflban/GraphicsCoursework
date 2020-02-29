#include <cstdio>
#include <random>
#include <ctime>
#include <cmath>

#include "Pixmap.h"
#include "Painter.h"
#include "PPMGenerator.h"

#include "Geometry.h"

#include "SGStar.h"
#include "SpiralGalaxy.h"
#include "GalaxyProperties.h"
#include "SGOrbitCalculator.h"

#include "SGObjectHandler.h"
#include "SGDiskRadiusDistributor.h"

void drawOrbit(Painter &painter, double a, double b, double angleOffset, const Perturbation &pert, size_t x0, size_t y0);

int main()
{
    FILE *fd;
    ImageGenerator *generator = new PPMGenerator;

    Pixmap p(900, 900);
    Painter painter(&p);

    SpiralGalaxy galaxy({ 0, 0, 0 }, 3000, 20000, 0.45, 0.46, 25000, {4, 40});
    double scale_ratio = 400.0 / 60000;

    painter.setColor({255, 255, 255});
    painter.fillRect(0, 0, 900, 900, {0, 0, 0});

    for (auto celestial: galaxy)
    {
        auto s = *(SGStar *)celestial();

        auto pos = SGOrbitCalculator::calculate(s.getA(), s.getB(), s.getRotationAngle(), {4, 40}, s.getAzimuth());

        painter.fillPixel(450 + (size_t)round(pos.x * scale_ratio), 450 + (size_t)round(pos.y * scale_ratio));
    }

    fd = fopen("stars.ppm", "w");
    generator->generate(fd, p);
    fclose(fd);

    painter.fillRect(0, 0, 900, 900, {0, 0, 0});

    for (auto celestial: galaxy)
    {
        auto s = *(SGStar *)celestial();

        auto pos = SGOrbitCalculator::calculate(s.getA(), s.getB(), s.getRotationAngle(), {4, 40}, s.getAzimuth());

        painter.fillPixel(450 + (size_t)round(pos.x * scale_ratio), 450 + (size_t)round(s.getC() * scale_ratio));
    }

    fd = fopen("xz.ppm", "w");
    generator->generate(fd, p);
    fclose(fd);

    delete generator;
}

//int main()
//{
    //srand(time(0));

    //Pixmap p(900, 900);
    //Painter painter(&p);

    //Pixmap p1(900, 900);
    //Painter painter1(&p1);

    //SpiralGalaxy galaxy({0, 0, 0}, 3000, 20000, 0.45, 0.46, 25000);
    //double scale_ratio = 400.0 / 60000;

    //painter.fillRect(0, 0, 900, 900, {0, 0, 0});

    //painter.setColor({255, 0, 0});
    //painter.drawEllipse(450, 450, (size_t)(scale_ratio * galaxy.getRaiusCore()), (size_t)(scale_ratio * galaxy.getRaiusCore()));
    //painter.setColor({0, 255, 0});
    //painter.drawEllipse(450, 450, (size_t)(scale_ratio * galaxy.getRadiusDisk()), (size_t)(scale_ratio * galaxy.getRadiusDisk()));

    //painter.setColor({255, 255, 255});
    //painter1.setColor({255, 255, 255});

    //double dr = 750;
    //double dteta = M_PI / 48;
    //for (double r = 1.0 / 5 * galaxy.getRaiusCore(), teta = 0; r < galaxy.getRadiusDisk() + 20000; r += dr, teta += dteta)
    //{
        //double a = r;
        //double b = sqrt(a * a - pow(galaxy.getEccentricity(r), 2) * a * a);

        ////painter.drawEllipse(450, 450, (size_t)(scale_ratio * a), (size_t)(scale_ratio * b), -galaxy.getAngularOffset(r));
        ////painter.drawEllipse(450, 450, (size_t)(scale_ratio * a), (size_t)(scale_ratio * b), M_PI/4);
        //drawOrbit(painter, scale_ratio * a, scale_ratio * b, galaxy.getAngularOffset(r), {4, 40}, 450, 450);
    //}

    //ImageGenerator *generator = new PPMGenerator;
    //FILE *fd = fopen("orbits.ppm", "w");

    //generator->generate(fd, p);

    //fclose(fd);

    //painter.fillRect(0, 0, 900, 900, {0, 0, 0});

    //Vector2D pos;
    //SGStarDescriptor s;
    //for (size_t idx = 0; idx < galaxy.getStarsQty(); idx++)
    //{
        //s = galaxy.getStars()[idx];
        //pos = SGOrbitCalculator::calculate(s.a, s.b, s.angularOffset, {4, 40}, s.azimuth);
        //pos = SGOrbitCalculator::calculate(scale_ratio * s.a, scale_ratio * s.b, s.angularOffset, {4, 40}, s.azimuth);

        ////printf("%lf\n", s.a);

        //ubyte c = (ubyte)(round(255 * s.brightness));

        //painter.fillPixel(450 + (size_t)round(pos.x), 450 + (size_t)round(pos.y),
                          //{ c, c, c });
    //}

    //fd = fopen("stars.ppm", "w");
    //generator->generate(fd, p);
    //fclose(fd);

    //std::mt19937 gen(time(NULL));
    ////std::normal_distribution<> nd(0, 0.001 * galaxy.getRaiusCore()*1e-3);
    //std::normal_distribution<> nd(0, pow(asin(galaxy.getRaiusCore() / galaxy.getRadiusDisk()), 1) / 3);
    //std::normal_distribution<> nd1(0, M_PI / 12);

    //std::normal_distribution<> nd2;

    //painter.fillRect(0, 0, 900, 900, {0, 0, 0});
    //painter1.fillRect(0, 0, 900, 900, {0, 0, 0});

    //for (size_t idx = 0; idx < galaxy.getStarsQty(); idx++)
    //{
        //s = galaxy.getStars()[idx];
        //auto pos0 = SGOrbitCalculator::calculate(s.a, s.b, s.angularOffset, {4, 40}, s.azimuth);
        //pos = SGOrbitCalculator::calculate(scale_ratio * s.a, scale_ratio * s.b, s.angularOffset, {4, 40}, s.azimuth);

        ////printf("%lf\n", s.a);

        //ubyte c = (ubyte)(round(255 * s.brightness));

        //double r = sqrt(pos0.x*pos0.x + pos0.y*pos0.y);
        //double theta;
        ////theta = 2*M_PI * nd(gen);
        //theta = nd(gen);

        //ubyte _r = c, _g = c, _b = c;

        ////if (fabs(sqrt(r*r*r*r*sin(theta)*sin(theta))) <= galaxy.getRaiusCore())
        //if (fabs(r / cos(theta)) <= galaxy.getRaiusCore())
        //{
            ////theta = 2*M_PI * ((double)gen() / gen.max());
            ////theta = nd1(gen);

            ////_r = 0;
            ////_g = 255;
            ////_b = 0;
        //}

        ////double z = r * sin(theta) * scale_ratio;
        //double z = r * tan(theta) * scale_ratio;

        //if (fabs(z) > galaxy.getRaiusCore() * 0.8 * scale_ratio)
        //{
            ////z *= 0.4 + 0.9 * ((double)gen() / gen.max());

            ////_r = 0;
            ////_g = 255;
            ////_b = 0;
        //}

        //// x**2 / (1.2 * radCore) + y**2 / radCore = 1
        //// y**2 = radCore * (1 - x**2 / (1.2 * radCore))

        //// x**2 / radDisk + y**4 / (radCore / 4) = 1
        //// y**4 / (radCore / 4) = 1 - x**2 / radDisk
        //// y**4 = (radCore / 4)* (radDisk - x**2) / radDisk

        ////double y1 = pow(fabs(galaxy.getRaiusCore() * (1 - r*r / (0.8 * galaxy.getRaiusCore()))), 1.0 / 2);
        //double y1 = pow(fabs(galaxy.getRaiusCore()*galaxy.getRaiusCore() - r*r), 1.0 / 2);
        //double y2 = pow(fabs((galaxy.getRaiusCore() / 0.0000001) * (galaxy.getRadiusDisk() - r*r) / galaxy.getRadiusDisk()), 1.0 / 4);

        //printf("%lf %lf\n", y1, y2);

        //if (fabs(r) <= galaxy.getRaiusCore())
        //{
            ////nd2.param(std::normal_distribution<>::param_type( 0, galaxy.getRaiusCore() / 1.5 / 3));
            //nd2.param(std::normal_distribution<>::param_type( 0, y1 / 3));
        //}
        //else
        //{
            ////nd2.param(std::normal_distribution<>::param_type( 0, galaxy.getRaiusCore() / 4 / 3));
            //nd2.param(std::normal_distribution<>::param_type( 0, y2 / 3 * 0.5 + 1.0 * ((double)gen() / gen.max())));
        //}

        //z = nd2(gen) * scale_ratio;
        ////double ones[2] = { -1, 1 };
        ////z += r / 400.0 * tan(theta) * ((double)gen() / gen.max()) * ones[gen() % 2];

        //double alpha = M_PI / 6;
        //double ax = pos.x;
        //double ay = pos.y * cos(alpha) - z * sin(alpha);
        //double az = pos.y * sin(alpha) + z * cos(alpha);

        //painter.fillPixel(450 + (size_t)round(pos.x), 450 + (size_t)round(z),
                          //{ _r, _g, _b });

        //painter1.fillPixel(450 + (size_t)round(ax), 450 + (size_t)round(az),
                          //{ _r, _g, _b });

        //painter.setColor({255, 0, 0});
        ////painter.drawEllipse(450, 450, (size_t)(scale_ratio * galaxy.getRaiusCore()), (size_t)(scale_ratio * galaxy.getRaiusCore()));

        //painter.setColor({255, 255, 255});
    //}

    //fd = fopen("XZ.ppm", "w");
    //generator->generate(fd, p);
    //fclose(fd);

    //fd = fopen("projection.ppm", "w");
    //generator->generate(fd, p1);
    //fclose(fd);

    //delete generator;
    //return 0;
//}

void drawOrbit(Painter &painter, double a, double b, double angleOffset, const Perturbation &pert, size_t x0, size_t y0)
{
    double h = 1 / std::fmax(a, b);
    double pi_m_2 = 2 * M_PI;

    //SGOrbitCalculator calculator(a, b, angleOffset, pert);

    for (double t = 0; t < pi_m_2; t += h)
    {
        //Vector2D pos = calculator.calculate(t);
        Vector2D pos = SGOrbitCalculator::calculate(a, b, angleOffset, pert, t);

        painter.fillPixel(x0 + (size_t)round(pos.x), y0 + (size_t)round(pos.y));
    }
}

