#ifndef RAQUETTE_H
#define RAQUETTE_H

#include "Rectangle.h"
#include "Point.h"

const int DECALAGE = 1;

class Raquette : public Rectangle {

    public:
        /////////Conctructeur/////////
        Raquette(const Rectangle &r);

        /////////Accesseurs/////////
        int getDirection () const ;


        void setDirection (int direction) ;


        void deplaceRaquetteGauche() ;
        void deplaceRaquetteDroit() ;



    private:
        int d_direction=0;

};






#endif
