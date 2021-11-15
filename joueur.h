#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>

//score augmentée de cette constante lorsque le joueur touche une brique, peut être modifiée facilement
const int SCORE_TOUCHEBRIQUE=100;

//score augmentée de cette constante lorsque le joueur détruit une brique, peut être modifiée facilement
const int SCORE_DETRUITBRIQUE=200;


using std::string;

class joueur
{
public:
    //constructeurs
    joueur (const string &nom);
    joueur (const string &nom, int nbVie);

    //accesseurs
    string getNom() const;
    int getNbVie() const;
    int getScore() const;
    bool getPerdu() const;

    //mutateurs
    void setNom(string nom);
    void setNbVie(int nbVie);
    void setScore (int score);
    void setPerdu (bool perdu);

    //score augmenté lorsque le joueur touche une brique
    void toucheUneBrique();

    //score augmenté lorsque le joueur détruit une brique
    void detruitUneBrique();

    //lorsque le joueur perd une vie
    void perdUneVie();

    //affiche un joueur
    void afficheJoueur(std::ostream &ost) const;

private :
    //nom du joueur
    string d_nom;
    //nombre de vies du joueur
    int d_nbVie;
    //score du joueur
    int d_score;
    //booléen qui indique si il a perdu
    bool d_perdu;
};



#endif // JOUEUR_H
