#ifndef BRIQUE_H
#define BRIQUE_H
#include <memory>
#include "Rectangle.h"
#include "surface.h"
#include "typeBrique.h"

using std::unique_ptr;

class brique : public Rectangle
{
public:
    //constructeur
    brique (const Rectangle &r, unique_ptr <surface>& s, unique_ptr <typeBrique>& tb);

    //accesseurs
    surface* getSurface() const;
    typeBrique* getTypeBrique() const;
    bool getEstDetruite() const;

    //mutateurs
    void setSurface(unique_ptr <surface>& s);
    void setTypeBrique(unique_ptr <typeBrique>& tb);
    void setEstDetruite( bool estDetruite);

    //lorsqu'une brique est touchée
    void briqueTouchee( typeBrique* tb);

private :
    //pointeur sur le type de surface
    unique_ptr<surface> d_surface;
    //pointeur sur le type de brique
    unique_ptr<typeBrique> d_typeBrique;
    //indique si la brique est detruite ou non
    bool d_estDetruite=false;
};

#endif // BRIQUE_H
