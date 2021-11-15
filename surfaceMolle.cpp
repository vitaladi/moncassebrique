#include "surfaceMolle.h"
#include "balle.h"

//constructeur
surfaceMolle::surfaceMolle(double pourcentage): d_pourcentage{pourcentage}
{}

//accesseur pourcentage
double surfaceMolle::pourcentage () const
{
    return d_pourcentage;
}

 //vitesse balle diminuée de d_pourcentage
void surfaceMolle::diminueVitesseBalle (balle &b) const
{
       double facteur=1.0-d_pourcentage;
        b.changerVitesse(facteur);
}

//effets de la surface sur la balle
void surfaceMolle::effetsSurLaBalle(balle &b, bool cote) const
{
    b.collision(cote);
    diminueVitesseBalle(b);
}

