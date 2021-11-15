#include "Point.h"

/////////Constructeurs/////////

Point::Point():
    d_x{0},
    d_y{0}
{}

Point::Point (const Point &p):
    d_x{p.d_x},
    d_y{p.d_y}
{}

Point::Point(double x ,double y):
    d_x{x},
    d_y{y}
{}

/////////Accesseurs/////////
double Point::Get_x () const
{
    return d_x;
}

double Point::Get_y () const
{
    return d_y;
}

/////////Mutateurs/////////
void Point::DeplacementDe (double X, double Y)
{
    d_x+=X;
    d_y+=Y;
}

void Point::DeplacementA (double X, double Y)
{
    d_x=X;
    d_y=Y;
}

/////////Operateurs/////////
