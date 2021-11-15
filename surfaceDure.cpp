#include "surfaceDure.h"
#include "balle.h"

//constructeur
surfaceDure::surfaceDure(double pourcentage): d_pourcentage{pourcentage}
{}

//accesseur pourcentage
double surfaceDure::pourcentage () const
{
    return d_pourcentage;
}

 //vitesse balle augmentée de d_pourcentage
void surfaceDure::augmenteVitesseBalle (balle &b) const
{
    double facteur=1.0+d_pourcentage;
    b.changerVitesse(facteur);
}

//effets de la surface sur la balle
void surfaceDure::effetsSurLaBalle(balle &b, bool cote) const
{
    b.collision(cote);
    augmenteVitesseBalle(b);
}


