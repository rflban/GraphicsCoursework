#include "Scene.h"

#include "InputBuffer.h"

#include "SpiralGalaxy.h"
#include "SGOrbitCalculator.h"

#include <cmath>

Scene::Scene() :
    galaxy(new SpiralGalaxy({ 0, 0, 0 }, 3000, 20000,
                            0.45, 0.46, 25000, {4, 40})),

    //viewer(Vector3d(0, 0, 55000)),
    viewer(Vector3d(0, 0, 55000), Vector3d(0, 0, 0)),
    perspective(M_PI / 3, 1, 0, 25000)
{
}

Scene::~Scene()
{
    delete galaxy;
}

void Scene::render(InputBuffer &buffer)
{
    buffer.reset();

    for (auto celestial: *galaxy)
    {
        auto s = *(SGStar *)celestial();

        auto pos = SGOrbitCalculator::calculate(
            s.getA(), s.getB(), s.getRotationAngle(), {4, 40}, s.getAzimuth()
        );

        Vector4d point(pos.x, pos.y, s.getC());

        point = point * viewer();
        point = point * perspective();

        if (!(fabs(point.x) > fabs(point.w)) &&
            !(fabs(point.y) > fabs(point.w)) &&
            !(fabs(point.z) > fabs(point.w)))
        {
            int x = (point.x / point.w + 1 / 2.0) * buffer.width();
            int y = (point.y / point.w + 1 / 2.0) * buffer.height();

            buffer.setPixel(x, y, 255, 255, 255);
        }
    }
}

void Scene::rotateCamera(double deltaTheta, double delatPhi)
{
    viewer.rotateArroundCenter(deltaTheta, delatPhi);
}

