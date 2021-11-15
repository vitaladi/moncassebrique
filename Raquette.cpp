#include "Raquette.h"
#include "Rectangle.h"
#include "Point.h"



/* Déclaration du constructeur */
Raquette::Raquette(const Rectangle &r): Rectangle{r}
{}



int  Raquette::getDirection () const
{
    return d_direction;
}


void Raquette::setDirection (int direction)
{
    if(direction == -1 || direction == 1)
    {
        d_direction = direction;
    }
}



void Raquette::deplaceRaquetteGauche()
{
    this->setP1(Get_P1().Get_x()- DECALAGE, 0);
    this->setP4(Get_P4().Get_x()- DECALAGE, 0);
}

void Raquette::deplaceRaquetteDroit()
{
    this->setP1(Get_P1().Get_x()+ DECALAGE, 0);
    this->setP4(Get_P4().Get_x()+ DECALAGE, 0);
}
