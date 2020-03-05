#ifndef GCW_VIEWOBSERVER_H_
#define GCW_VIEWOBSERVER_H_

class ViewObserver
{
public:
    virtual void renderFrame() = 0;

    virtual void scaleCamera(double, double, double) = 0;
    virtual void rotateCamera(double, double, double) = 0;
    virtual void translateCamera(double, double, double) = 0;

    virtual void updateVelocity(double) = 0;
    virtual void updateParticle(int) = 0;

protected:

private:

    friend class View;
};

#endif // GCW_VIEWOBSERVER_H_

