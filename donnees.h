#ifndef DONNEES_H
#define DONNEES_H
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <stdlib.h>
#include "balle.h"
#include "brique.h"
#include "Rectangle.h"
#include "Point.h"
#include "surfaceNormale.h"
#include "surfaceDure.h"
#include "surfaceTueuse.h"
#include "surfaceMolle.h"
#include "surface.h"
#include "typeBriqueCassable.h"
#include "typeBriqueIncassable.h"
#include "Raquette.h"


using namespace std;


class donnees
{
    public:
        donnees(string nomFichier);
        ~donnees();
        string testLectureInitiale;

        void lireDonnees();
        void enleverCommentaires(string &ligneCommentee);
        void remplacerCaracSpec(string &ligneSpec);

        vector<int> testType; // ne constituent pas des tests d'objets en soi mais permet une vérification non négligeable sur la construction de l'objet
        vector<int> testSurface;

        vector<balle> balles;
        vector<brique> briques;
        vector<Raquette> raquettes;

        vector<int> meilleursScores;


    protected:

    private:
        ifstream d_fichier;
        string d_nomFichier;


};

#endif // DONNEES_H
