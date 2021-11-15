#ifndef TYPEBRIQUE_H
#define TYPEBRIQUE_H

class brique;

class typeBrique
{
public :
    virtual ~typeBrique();

    //effets sur la brique
    virtual void effetsSurLaBrique(brique &b)=0;
};


#endif // TYPEBRIQUE_H
