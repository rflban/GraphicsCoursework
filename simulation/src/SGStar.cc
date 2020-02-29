#include "SGStar.h"

#include "SGObjectHandler.h"

void SGStar::accept(SGObjectHandler &handler)
{
    handler(*this);
}

