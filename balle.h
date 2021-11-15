#ifndef BALLE_H
#define BALLE_H
#include "surface.h"

class balle
{
    public:
        ~balle();

        //constructeur
        balle();
        balle(double rayon, double vitesse); //le principal (position sur la raquette, balle immobile seul rayon à préciser)
        balle(double x, double y, double vx, double vy, double rayon, double vitesse); //celui qui permet de tout changer

        //getters
        const double x();
        const double y();
        const double vx();
        const double vy();
        const double rayon();
        const double vitesse();

        //setters
        void changerVitesse(double facteur);


        //fonctions
        void deplacement();
        void collision(bool cote);

        void modifierPosition(double x, double y);
        void translaterPosition(double x, double y);
        void modifierVecteur(double vx, double vy);
        void ajouterAuVecteur(double vx, double vy);
        void surfaceTouchee(surface* s, bool cote);


    private:
        double d_x, d_y;
        double d_vx, d_vy; //vecteurs de déplacement
        double d_rayon; //rayon de la balle
        double d_vitesse; //1.0 vitesse normale


        //pas de setter pour rayon (pas de raison de le modifier)
};



#endif // BALLE_H
