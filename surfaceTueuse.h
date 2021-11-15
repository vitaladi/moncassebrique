#ifndef SURFACETUEUSE_H
#define SURFACETUEUSE_H
#include "surface.h"

class surfaceTueuse : public surface
{
public :
    //effets de la surface sur la balle
    virtual void effetsSurLaBalle(balle &b, bool cote) const override;
};

#endif // SURFACETUEUSE_H
