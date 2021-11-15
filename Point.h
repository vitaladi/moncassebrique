#ifndef POINT_H
#define POINT_H

//classe point , stocke un point avec 2 entiers x et y

class Point
{
    public:
        /////////Constructeurs/////////
        Point ();
        Point (const Point &p);
        Point(double x ,double y);

        /////////Accesseurs/////////
        double Get_x () const;
        double Get_y () const;

        /////////Mutateurs/////////
        void DeplacementDe (double X, double Y);
        void DeplacementA (double X, double Y);

        /////////Operateurs/////////


    private:
        double d_x, d_y;
};

#endif // POINT_H
