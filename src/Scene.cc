#include "Scene.h"

#include "InputBuffer.h"

#include "SpiralGalaxy.h"
#include "SGOrbitCalculator.h"

#include "Affine.h"

#include <cmath>

Scene::Scene() :
    galaxy(nullptr),

    rotation({1, 0, 0, 0,
              0, 1, 0, 0,
              0, 0, 1, 0,
              0, 0, 0, 1}),

    //viewer(Vector3d(0, 0, 55000)),
    viewer(Vector3d(0, 0, 55000), Vector3d(0, 0, 0)),
    perspective(M_PI / 3, 1, 0, 25000),

    vel(22500),

    m_colNum(200),
    m_t0(1000),
    m_t1(16000),
    m_dt((m_t1-m_t0) /m_colNum)
{
    resetGalaxy(25000);

    double x, y, z;
    m_col = new Color[m_colNum];

    for (int i = 0; i < m_colNum; i++)
    {
        Color &col = m_col[i];
        colourSystem *cs = &SMPTEsystem;

        bbTemp = m_t0 + m_dt*i;
        spectrum_to_xyz(bb_spectrum, &x, &y, &z);
        xyz_to_rgb(cs, x, y, z, &col.r, &col.g, &col.b);
        norm_rgb(&col.r, &col.g, &col.b);
    }
}

Scene::~Scene()
{
    delete galaxy;
    delete[] m_col;
}

void Scene::render(InputBuffer &buffer)
{
    //double time = 400000 + (vel - 20000) * 300;
    double time = 160000 + (vel - 20000) * 120;
    galaxy->timeStep(time);

    buffer.reset();

    Color color;
    double r;

    for (auto celestial: *galaxy)
    {
        auto s = *(SGStar *)celestial();

        auto pos = SGOrbitCalculator::calculate(
            s.getA(), s.getB(), s.getRotationAngle(), {4, 40}, s.getAzimuth()
        );

        Vector4d point(pos.x, pos.y, s.getC());

        point = point * rotation;
        point = point * viewer();
        point = point * perspective();

        if (!(fabs(point.x) > fabs(point.w)) &&
            !(fabs(point.y) > fabs(point.w)) &&
            !(fabs(point.z) > fabs(point.w)))
        {
            int x = (point.x / point.w + 1 / 2.0) * buffer.width();
            int y = (point.y / point.w + 1 / 2.0) * buffer.height();

            color = ColorFromTemperature(s.getTemperature());
            r = s.getColorRatio() * 255;
            //r = 255 * 0.9;

            if (x >= 0 && y>= 0 && x < buffer.width() && y < buffer.height())
                //buffer.setPixel(x, y, color.r * r, color.g * r, color.b * r, s.getColorRatio());
                buffer.setPixel(x, y, color.r * r, color.g * r, color.b * r);
        }
    }
}

void Scene::scaleCamera(double rx, double ry, double rz)
{
    viewer.scale(rx, ry, rz);
}

void Scene::rotateCamera(double ax, double ay, double az)
{
    //viewer.rotate(ax, ay, az);
    rotateGalaxy(az, ay, ax);
}

void Scene::translateCamera(double dx, double dy, double dz)
{
    viewer.translate(dx, dy, dz);
}

Scene::Color Scene::ColorFromTemperature(double temp) const
{
  int idx = (temp - m_t0) / (m_t1 - m_t0) * m_colNum;

  idx = std::min(m_colNum-1, idx);
  idx = std::max(0, idx);

  return m_col[idx];
}

void Scene::rotateGalaxy(double ax, double ay, double az)
{
    rotation = rotation * rotationX(ax);
    rotation = rotation * rotationY(ay);
    rotation = rotation * rotationZ(az);
}

void Scene::resetGalaxy(int qty)
{
    if (galaxy)
    {
        delete galaxy;
    }

    galaxy = new SpiralGalaxy({ 0, 0, 0 }, 3000, 20000, 0.45, 0.46, qty, {4, 40});
}

