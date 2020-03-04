#ifndef GCW_SCENE_H_
#define GCW_SCENE_H_

class InputBuffer;

class SpiralGalaxy;

class Scene
{
public:
    void render(InputBuffer &buffer);

private:
    SpiralGalaxy *galaxy;
};

#endif // GCW_SCENE_H_

