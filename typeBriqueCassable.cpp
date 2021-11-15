#include "typeBriqueCassable.h"

//constructeur
typeBriqueCassable::typeBriqueCassable(int nbCollisionsNecessaires) :
    d_nbCollisionsNecessaires{nbCollisionsNecessaires}
{}

//accesseur nbCollisionsNecessaires
int typeBriqueCassable::nbCollisionsNecessaires() const
{
    return d_nbCollisionsNecessaires;
}

//effets sur la brique
void typeBriqueCassable::effetsSurLaBrique(brique &b)
{
     d_nbCollisionsNecessaires--;
   if (d_nbCollisionsNecessaires<=0)
        b.setEstDetruite(true);
}
