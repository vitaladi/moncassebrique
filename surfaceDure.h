#ifndef SURFACEDURE_H
#define SURFACEDURE_H
#include "surface.h"

class surfaceDure : public surface
{
public:
    //constructeur
    surfaceDure(double pourcentage);

    //accesseur pourcentage
    double pourcentage () const;

     //vitesse balle augmentée de d_pourcentage
    void augmenteVitesseBalle (balle &b) const;

     //effets de la surface sur la balle
    virtual void effetsSurLaBalle(balle &b, bool cote) const override;

private:
    double d_pourcentage;   //pourcentage sous la forme 0.3 par exemple ou 30/100
};

#endif // SURFACEDURE_H
