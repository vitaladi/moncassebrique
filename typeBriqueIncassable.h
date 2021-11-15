#ifndef TYPEBRIQUEINCASSABLE_H
#define TYPEBRIQUEINCASSABLE_H
#include "typeBrique.h"
#include "brique.h"

class typeBriqueIncassable : public typeBrique
{
public :
    //effets sur la brique
    virtual void effetsSurLaBrique(brique &b) override;
};


#endif // TYPEBRIQUEINCASSABLE_H
