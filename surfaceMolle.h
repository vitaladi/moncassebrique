#ifndef SURFACEMOLLE_H
#define SURFACEMOLLE_H
#include "surface.h"

class surfaceMolle : public surface
{
public:
    //constructeur
    surfaceMolle(double pourcentage);

    //accesseur pourcentage
    double pourcentage () const;

    //vitesse balle diminuée de d_pourcentage
    void diminueVitesseBalle (balle &b) const;

    //effets de la surface sur la balle
    virtual void effetsSurLaBalle(balle &b, bool cote) const override;

private:
    double d_pourcentage;   //pourcentage sous la forme 0.3 par exemple ou 30/100
};

#endif // SURFACEMOLLE_H

