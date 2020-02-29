#ifndef GCW_SGOBJECTHANDLER_H_
#define GCW_SGOBJECTHANDLER_H_

class SGStar;

class SGObjectHandler
{
public:
    virtual void operator()(SGStar &) = 0;

private:
};

#endif // GCW_SGOBJECTHANDLER_H_

