#ifndef GCW_VIEWOBSERVER_H_
#define GCW_VIEWOBSERVER_H_

class ViewObserver
{
public:
    virtual void renderFrame() = 0;
    virtual void rotateCamera(double deltaT, double deltaP) = 0;

protected:

private:

    friend class View;
};

#endif // GCW_VIEWOBSERVER_H_

