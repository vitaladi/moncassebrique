#include "donnees.h"
#include <memory>

using namespace std;
using std::unique_ptr;

donnees::donnees(string nomFichier)
{
    d_fichier.open(nomFichier);

    if (d_fichier.is_open())
    {
        getline (d_fichier,testLectureInitiale);
    }
}

donnees::~donnees()
{
    d_fichier.close();
}

void donnees::lireDonnees()
{
    string ligne;


    while(getline(d_fichier, ligne))
    {
        enleverCommentaires(ligne);
        remplacerCaracSpec(ligne);

        regex regexBalle1{"balle *P *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *Q"};
        regex regexBalle2{"balle *P *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *Q"};
        regex regexBalle3{"balle *P *Q"};
        regex regexBalleTab{"balle *C *([[:digit:]]+) *D *P *(-*[[:digit:]]+\.*[[:digit:]]*) *A *(-*[[:digit:]]+\.*[[:digit:]]*)i *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *Q"};
        regex regexBalleTab2{"balle *C *([[:digit:]]+) *D *P *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *A *(-*[[:digit:]]+\.*[[:digit:]]*)i *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *Q"};
        regex regexBalleTableau2Dimensions{"balle *C *([[:digit:]]+) *D *C *([[:digit:]]+) *D *P *(-*[[:digit:]]+\.*[[:digit:]]*) *A *(-*[[:digit:]]+\.*[[:digit:]]*)i *V *(-*[[:digit:]]+\.*[[:digit:]]*) *A *(-*[[:digit:]]+\.*[[:digit:]]*)j *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *Q"};
        regex regexBrique{"brique *P *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *([[:alpha:]]*) *V *([[:alpha:]]*) *Q"};

        regex regexRaquette{"raquette *P *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *V *(-*[[:digit:]]+\.*[[:digit:]]*) *Q"};
        regex regexScore{"nbMeilleurScore *= *([[:digit:]]+)"};

        smatch resultat;

        if (regex_search(ligne, resultat, regexBalle1))
        {
            balle balleInter(stod(resultat[1]), stod(resultat[2]),stod(resultat[3]),stod(resultat[4]),stod(resultat[5]),stod(resultat[6]));
            balles.push_back(balleInter);
        }
        else if (regex_search(ligne, resultat, regexBalle2))
        {
            balle balleInter(stod(resultat[1]), stod(resultat[2]));
            balles.push_back(balleInter);
        }
        else if (regex_search(ligne, resultat, regexBalle3))
        {
            balle balleInter;
            balles.push_back(balleInter);
        }
        else if (regex_search(ligne, resultat, regexBalleTab))
        {
            for(int i = 0; i< stoi(resultat[1]); i++)
            {
                balle balleInter(stod(resultat[2]) + stod(resultat[3])*i,stod(resultat[4]),stod(resultat[5]),stod(resultat[6]),stod(resultat[7]),stod(resultat[8]));
                balles.push_back(balleInter);
            }
        }
        else if (regex_search(ligne, resultat, regexBalleTab2))
        {
            for(int i = 0; i< stoi(resultat[1]); i++)
            {
                balle balleInter(stod(resultat[2]),stod(resultat[3]) + stod(resultat[4])*i,stod(resultat[5]),stod(resultat[6]),stod(resultat[7]),stod(resultat[8]));
                balles.push_back(balleInter);
            }
        }
        else if (regex_search(ligne, resultat, regexBalleTableau2Dimensions))
        {
            int i;
            int j;



                for(i = 0; i<stoi(resultat[1]);i++)
                {
                    for(j = 0; j < 5;j++)
                    {
                        balle balleInter(stod(resultat[3]) + stod(resultat[4])*i, stod(resultat[5]) + stod(resultat[6])*j, stod(resultat[7]),stod(resultat[8]),stod(resultat[9]),stod(resultat[10]));
                        balles.push_back(balleInter);
                    }
                }

        }



        else if(regex_search(ligne, resultat, regexBrique))
        {


            Point pointInter(stod(resultat[1]),stod(resultat[2]));
            Rectangle r(pointInter, stod(resultat[3]),stod(resultat[4]));
            string interTb = resultat[5];
            string interS= resultat[6];

            unique_ptr<typeBrique> tb;


            //gestion du type en fonction de ce qui a été trouvé dans les string

            if(interTb == "incassable")
            {
                testType.push_back(1);
                tb=make_unique<typeBriqueIncassable>();
            }
            else if(interTb == "cassable")
            {
                testType.push_back(2);
                tb=make_unique<typeBriqueCassable>(1);
            }
            else
            {
                testType.push_back(2);  // par défaut une brique est cassable
                tb=make_unique<typeBriqueCassable>(1);
            }

            unique_ptr<surface> sN;

            if(interS == "dure")
            {
                testSurface.push_back(1);
                unique_ptr<surface> sN=make_unique<surfaceDure>(50);
            }
            else if(interS == "molle")
            {
                testSurface.push_back(2);
                unique_ptr<surface> sN=make_unique<surfaceMolle>(50);
            }
            else if(interS == "tueuse")
            {
                testSurface.push_back(3);
                unique_ptr<surface> sN=make_unique<surfaceTueuse>();
            }
            else if(interS == "normale")
            {
                testSurface.push_back(4);
                unique_ptr<surface> sN=make_unique<surfaceNormale>();
            }
            else
            {
                testSurface.push_back(4);
                sN=make_unique<surfaceNormale>();
            }


            brique b{r,sN,tb};

            briques.push_back(std::move(b));
        }








        else if (regex_search(ligne, resultat, regexRaquette))
        {
            Point pointInter(stod(resultat[1]),stod(resultat[2]));
            Rectangle rectangleInter(pointInter, stod(resultat[3]),stod(resultat[4]));
            Raquette raquetteInter(rectangleInter);
            raquettes.push_back(raquetteInter);
        }
        else if (regex_search(ligne, resultat, regexScore))
        {
            int inter = stoi(resultat[1]);
            meilleursScores.push_back(inter);
        }
    }


}











void donnees::enleverCommentaires(string &ligneCommentee)  // enlève tout ce qu'il y a après un "//"
{
    regex modele("//");
    smatch resultat;

    if (regex_search(ligneCommentee, resultat, modele))
    {
        ligneCommentee = resultat.prefix();
    }
}

void donnees::remplacerCaracSpec(string &ligneSpec)
{
     replace( ligneSpec.begin(), ligneSpec.end(), '(', 'P');
     replace( ligneSpec.begin(), ligneSpec.end(), ')', 'Q');
     replace( ligneSpec.begin(), ligneSpec.end(), ',', 'V');
     replace( ligneSpec.begin(), ligneSpec.end(), '[', 'C');
     replace( ligneSpec.begin(), ligneSpec.end(), ']', 'D');
     replace( ligneSpec.begin(), ligneSpec.end(), '+', 'A');
}
