#ifndef SURFACE_H
#define SURFACE_H

class balle;

class surface
{
public :
    virtual ~surface();
    //effets de la surface sur la balle
    virtual void effetsSurLaBalle(balle &b, bool cote) const=0;
};

#endif // SURFACE_H
