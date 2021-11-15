#ifndef SURFACENORMALE_H
#define SURFACENORMALE_H
#include "surface.h"

class surfaceNormale : public surface
{
public:
    //effets de la surface sur la balle
    virtual void effetsSurLaBalle(balle &b, bool cote) const override;
};


#endif // SURFACENORMALE_H
