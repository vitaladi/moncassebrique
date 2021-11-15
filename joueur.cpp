#include "joueur.h"


//constructeurs
joueur::joueur (const string &nom) :
    d_nom{nom}, d_nbVie{3}, d_score{0}, d_perdu{false}
{}

joueur::joueur(const string &nom, int nbVie) :
    d_nom{nom}, d_nbVie{nbVie}, d_score{0}, d_perdu{false}
{}

//accesseurs
string joueur::getNom() const
{
    return d_nom;
}

int joueur::getNbVie() const
{
    return d_nbVie;
}

int joueur::getScore() const
{
    return d_score;
}

bool joueur::getPerdu() const
{
    return d_perdu;
}

//mutateurs
void joueur::setNom(string nom)
{
    d_nom=nom;
}

void joueur::setNbVie(int nbVie)
{
    d_nbVie=nbVie;
}

void joueur::setScore (int score)
{
    d_score=score;
}

void joueur::setPerdu (bool perdu)
{
    d_perdu=perdu;
}

//lorsque le joueur touche une brique
void joueur::toucheUneBrique()
{
    d_score+=SCORE_TOUCHEBRIQUE;
}

//lorsque le joueur détruit une brique
void joueur::detruitUneBrique()
{
    d_score+=SCORE_DETRUITBRIQUE;
}

//lorsque le joueur perd une vie
void joueur::perdUneVie()
{
    d_nbVie--;
    if(d_nbVie<=0)
            d_perdu=true;
}

//affiche un joueur
void joueur::afficheJoueur(std::ostream &ost) const
{
    ost<<d_nom<<" ; Score : "<<d_score<<std::endl;
}
