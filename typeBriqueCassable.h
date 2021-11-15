#ifndef TYPEBRIQUECASSABLE_H
#define TYPEBRIQUECASSABLE_H
#include "typeBrique.h"
#include "brique.h"

class typeBriqueCassable : public typeBrique
{
public :
    //constructeur
    typeBriqueCassable (int nbCollisionsNecessaires);

    //accesseur nbCollisionsNecessaires
    int nbCollisionsNecessaires() const;

     //effets sur la brique
    virtual void effetsSurLaBrique(brique &b) override;
private:
    //nombre de collisions necessaires pour casser une brique
    int d_nbCollisionsNecessaires;
};

#endif // TYPEBRIQUECASSABLE_H
