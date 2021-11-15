#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

#include "doctest.h"
#include "Rectangle.h"

inline void Rectangle_egaux (const Rectangle& Rect ,const Point& P1 , const Point& P4)
{
    FAST_CHECK_EQ (Rect.Get_P1().Get_x() ,P1.Get_x());
    FAST_CHECK_EQ (Rect.Get_P1().Get_y() ,P1.Get_y());
    FAST_CHECK_EQ (Rect.Get_P4().Get_x() ,P4.Get_x());
    FAST_CHECK_EQ (Rect.Get_P4().Get_y() ,P4.Get_y());
}

inline void Rectangle_egaux (const Rectangle& Rect ,const Rectangle& Copy)
{
    FAST_CHECK_EQ (Rect.Get_P1().Get_x() ,Copy.Get_P1().Get_x());
    FAST_CHECK_EQ (Rect.Get_P1().Get_y() ,Copy.Get_P1().Get_y());
    FAST_CHECK_EQ (Rect.Get_P4().Get_x() ,Copy.Get_P4().Get_x());
    FAST_CHECK_EQ (Rect.Get_P4().Get_y() ,Copy.Get_P4().Get_y());
}

inline void Rectangle_egaux (const Rectangle& Rect ,int x1 ,int y1 ,int x4 ,int y4)
{
    FAST_CHECK_EQ (Rect.Get_P1().Get_x() ,x1);
    FAST_CHECK_EQ (Rect.Get_P1().Get_y() ,y1);
    FAST_CHECK_EQ (Rect.Get_P4().Get_x() ,x4);
    FAST_CHECK_EQ (Rect.Get_P4().Get_y() ,y4);
}

inline void Rectangle_egaux (const Rectangle& Rect ,const Point& P1 ,int longueur , int hauteur)
{
    FAST_CHECK_EQ (Rect.Get_P1().Get_x() ,P1.Get_x());
    FAST_CHECK_EQ (Rect.Get_P1().Get_y() ,P1.Get_y());
    FAST_CHECK_EQ (Rect.Get_P4().Get_x() ,P1.Get_x()+longueur);
    FAST_CHECK_EQ (Rect.Get_P4().Get_y() ,P1.Get_y()-hauteur);
}

inline void Point_egaux (const Point &P ,int x ,int y)
{
    FAST_CHECK_EQ (P.Get_x(), x);
    FAST_CHECK_EQ (P.Get_y(), y);
}

/////////Constructeurs/////////
TEST_CASE ("Rectangle construit")
{
    int x1=12 ,x4=13 ,y1=15 ,y4=14;
    SUBCASE ("Rectangle cree par recopie")
    {
        Rectangle Alpha (x1,y1,x4,y4);
        Rectangle Copy_Alpha (Alpha);
        Rectangle_egaux(Copy_Alpha ,Alpha);
    }

    SUBCASE ("Rectangle cree par points")
    {
        Point P1 {x1,y1}, P4 {x4,y4};
        Rectangle_egaux(Rectangle {P1 ,P4} ,P1 ,P4 );
    }

    SUBCASE ("Rectangle cree par entiers")
    {
        Rectangle_egaux(Rectangle {12,15,13,14} ,x1 ,y1 ,x4 ,y4);
    }

    SUBCASE ("Rectangle cree par un point")
    {
        Point P1 {12,15};
        int longueur = 3 , hauteur = 4;
        Rectangle_egaux(Rectangle {P1, longueur, hauteur} ,P1 ,longueur ,hauteur);
    }
}

/////////Accesseurs/////////
TEST_CASE ("Get points")
{
    Rectangle Alpha (12, 15, 13, 14);
    SUBCASE ("Point P2")
    {
        Point_egaux(Alpha.Get_P2() ,13 ,15);
    }
    SUBCASE ("Point P3")
    {
        Point_egaux(Alpha.Get_P3() ,12 ,14);
    }
}

/////////Mutateurs/////////

/////////Operateurs/////////
