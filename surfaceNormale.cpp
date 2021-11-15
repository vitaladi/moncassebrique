#include "surfaceNormale.h"
#include "balle.h"

//effets de la surface sur la balle
void surfaceNormale::effetsSurLaBalle(balle &b, bool cote) const
{
    b.collision(cote);
}

