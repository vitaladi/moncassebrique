#include "brique.h"

//constructeur
brique::brique (const Rectangle &r, unique_ptr <surface> &s, unique_ptr <typeBrique>& tb) :
    Rectangle{r}, d_surface{std::move(s)}, d_typeBrique{std::move(tb)}
{}

//accesseurs
surface* brique::getSurface() const
{
    return d_surface.get();
}

typeBrique* brique::getTypeBrique() const
{
    return d_typeBrique.get();
}

bool brique::getEstDetruite() const
{
    return d_estDetruite;
}


//mutateurs
 void brique::setSurface(unique_ptr <surface>& s)
 {
     d_surface=std::move(s);
 }

 void brique::setTypeBrique(unique_ptr <typeBrique>& tb)
 {
     d_typeBrique=std::move(tb);
 }

 void brique::setEstDetruite( bool estDetruite)
 {
     d_estDetruite=estDetruite;
 }

//lorsqu'une brique est touchée
void brique::briqueTouchee( typeBrique* tb)
{
    tb->effetsSurLaBrique(*this);
}
