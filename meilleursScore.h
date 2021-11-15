#ifndef MEILLEURSSCORE_H
#define MEILLEURSSCORE_H
#include "joueur.h"
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
using std::vector;

//constante pour d�terminer le nombre de meilleurs score � conserver
const int NB_MEILLEURSSCORE=5;

class meilleursScore
{
public :
    //constructeur
    meilleursScore();

    //capacit�
    int capacite () const;

    //taille
    int taille() const;

    //recupere le joueur en i
    joueur* joueurEn(int i);

    //ajoute un joueur aux meilleurs score
    void ajouteJoueurAuxMeilleursScore(std::unique_ptr <joueur> j);

    //tri � bulles
    void triMeilleursScore();

    //reduit la liste des meilleurs score pour ne garder que les NB_MEILLEURSSCORE meilleurs score
    void reduitListeMeilleursScore();

    //r�cup�re les meilleurs score dans le fichier texte nomFichierIN pour les restocker dans le tableau des meilleurs score
    void recupereMeilleursScore(const string &nomFichierIN);

    //affiche les meilleurs score dans le fichier texte nomFichierOUT
    void afficheMeilleursScore(const string &nomFichierOUT) const;

    //mise � jour des meilleurs score
    void miseAJourMeilleursScore(const string &nomFichier, std::unique_ptr <joueur> j);

private:
    vector<std::unique_ptr<joueur>> d_meilleursScore;
};


#endif // MEILLEURSSCORE_H
