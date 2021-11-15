#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

#include "doctest.h"
#include "Point.h"

inline void CoordonneeEgale (const Point &P ,int x ,int y)
{
    FAST_CHECK_EQ (P.Get_x(), x);
    FAST_CHECK_EQ (P.Get_y(), y);
}

/////////Constructeurs/////////
TEST_CASE("Creation points")
{
    SUBCASE ("Constructeur par defaut")
    {
        CoordonneeEgale(Point{},0,0);
    }

    SUBCASE ("Constructeur par recopie")
    {
        Point Alpha (12 ,17), CopieAlpha (Alpha);
        CoordonneeEgale (CopieAlpha ,Alpha.Get_x() ,Alpha.Get_y());
    }
    SUBCASE ("Constructeur X Y")
    {
        Point Alpha (15,14);
        CoordonneeEgale (Alpha ,15 ,14);
    }
}

/////////Accesseurs/////////

/////////Mutateurs/////////
TEST_CASE ("Deplacement points")
{
    Point Alpha (12,17);
    SUBCASE("Deplacement de")
    {
        Alpha.DeplacementDe(3,-2);
        CoordonneeEgale(Alpha ,15 ,15);
    }
    SUBCASE ("Deplacement à")
    {
        Alpha.DeplacementA(15,13);
        CoordonneeEgale(Alpha ,15 ,13);
    }
}

/////////Operateurs/////////

