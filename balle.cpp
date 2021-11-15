#include "balle.h"

balle::~balle()
{

}


//constructeurs

balle::balle(): d_x{0}, d_y{0}, d_vx{0}, d_vy{0}, d_rayon{1}, d_vitesse{1.0}
{

}

balle::balle(double rayon, double vitesse): d_x{0}, d_y{0}, d_vx{0}, d_vy{0}, d_rayon{rayon}, d_vitesse{vitesse}
{

}

balle::balle(double x, double y, double vx, double vy, double rayon, double vitesse):d_x{x}, d_y{y}, d_vx{vx}, d_vy{vy}, d_rayon{rayon}, d_vitesse{vitesse}
{

}


//getters

const double balle::x()
{
    return d_x;
}

const double balle::y()
{
    return d_y;
}

const double balle::vx()
{
    return d_vx;
}

const double balle::vy()
{
    return d_vy;
}

const double balle::rayon()
{
    return d_rayon;
}

const double balle::vitesse()
{
    return d_vitesse;
}


//setters

void balle::modifierPosition(double x, double y)
{
    d_x = x;
    d_y = y;
}

void balle::translaterPosition(double x, double y)
{
    d_x += x;
    d_y += y;
}

void balle::modifierVecteur(double vx, double vy)
{
    d_vx = vx;
    d_vy = vy;
}

void balle::ajouterAuVecteur(double vx, double vy)
{
    d_vx += vx;
    d_vy += vy;
}

void balle::changerVitesse(double facteur)
{
    d_vitesse = d_vitesse *facteur;
}

void balle::surfaceTouchee(surface* s, bool cote)
{
    s->effetsSurLaBalle(*this,cote);
}


//fonctions

void balle::deplacement()
{
    d_x += (d_vx/60) * d_vitesse;
    d_y += (d_vy/60) * d_vitesse;
}

void balle::collision(bool cote) //haut/ bas (horizontale) = true , gauche/droite(verticale) = false
{
    if(cote == true)
    {
        d_vy = -d_vy;
    }
    else
    {
        d_vx = -d_vx;
    }
}
