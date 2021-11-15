#include "surfaceTueuse.h"
#include "balle.h"

//effets de la surface sur la balle
void surfaceTueuse::effetsSurLaBalle(balle &b, bool cote) const
{
    b.~balle();
}
