#ifndef GCW_SGOBJECT_H_
#define GCW_SGOBJECT_H_

class SGObjectHandler;

class SGObject
{
public:
    virtual inline void accept(SGObjectHandler &handler) = 0;

};

#endif // GCW_SGOBJECT_H_

