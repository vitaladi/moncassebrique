#include "Rectangle.h"

/////////Constructeurs/////////

Rectangle::Rectangle (const Rectangle& Copy):
    d_P1{Copy.Get_P1()},
    d_P4{Copy.Get_P4()}
{}

Rectangle::Rectangle(const Point &P1, const Point &P4):
    d_P1{P1},
    d_P4{P4}
{}

Rectangle::Rectangle(double x1,double y1,double x4,double y4):
    d_P1{x1,y1},
    d_P4{x4,y4}
{}

Rectangle::Rectangle(const Point &P1, double longueur, double hauteur):
    d_P1{P1},
    d_P4{P1.Get_x()+longueur,P1.Get_y()-hauteur}
{}

/////////Accesseurs/////////
Point Rectangle::Get_P1() const
{
    return d_P1;
}

Point Rectangle::Get_P2() const
{
    return Point {Get_P4().Get_x(), Get_P1().Get_y()};
}

Point Rectangle::Get_P3() const
{
    return Point {Get_P1().Get_x(), Get_P4().Get_y()};
}

Point Rectangle::Get_P4() const
{
    return d_P4;
}

/////////Mutateurs/////////


void Rectangle::setP1(double X, double Y)
{
    d_P1= {X,Y};
}

void Rectangle::setP4(double X, double Y)
{
    d_P4= {X,Y};
}

/////////Operateurs/////////
