#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

//classe rectangle , sers principallement a stocker les coordonnées d'un rectangle
//avec 2 points P1 et P4 representant respectivement le coin superieur gauche
//et le coin inférieur droit (on note les angles dans un sens de lecture (du haut vers le bas et de la gauche vers la droite))

class Rectangle
{
public:
    /////////Constructeurs/////////
    Rectangle () =delete;
    Rectangle (const Rectangle& Copy);
    Rectangle(const Point &P1, const Point &P4);
    Rectangle(double x1,double y1,double x4,double y4);
    Rectangle(const Point &P1, double longueur, double hauteur);

    /////////Accesseurs/////////
    Point Get_P1() const;
    Point Get_P2() const;
    Point Get_P3() const;
    Point Get_P4() const;

    /////////Mutateurs/////////

    void setP1 (double X, double Y);
    void setP4 (double X, double Y);

    /////////Operateurs/////////

private:
    Point d_P1, d_P4;
};

#endif // RECTANGLE_H
