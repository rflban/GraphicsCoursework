#include "Scene.h"

#include "SpiralGalaxy.h"
#include <cmath>

Scene::Scene() :
    galaxy(new SpiralGalaxy({ 0, 0, 0 }, 3000, 20000,
                            0.45, 0.46, 25000, {4, 40})),

    viewer(Vector3d(0, 0, 2000)),
    perspective(M_PI / 3, 0, -4000, 4000)
{
}

Scene::~Scene()
{
    delete galaxy;
}

