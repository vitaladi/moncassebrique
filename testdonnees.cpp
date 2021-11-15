#include "donnees.h"
#include "doctest.h"

using namespace std;

void laBalleEstElleBienValorisee(balle &balleATester, double x, double y, double vx, double vy, double rayon, double vitesse)
{
    REQUIRE(balleATester.x() == x);
    REQUIRE(balleATester.y() == y);
    REQUIRE(balleATester.vx() == vx);
    REQUIRE(balleATester.vy() == vy);
    REQUIRE(balleATester.rayon() == rayon);
    REQUIRE(balleATester.vitesse() == vitesse);
}

void laRaquetteEstElleBienValorisee(Raquette &raquetteATester, double x, double y, double longueur, double hauteur)
{
    REQUIRE(raquetteATester.Get_P1().Get_x() == x);
    REQUIRE(raquetteATester.Get_P1().Get_y() == y);

    REQUIRE(raquetteATester.Get_P2().Get_x() == x+longueur);
    REQUIRE(raquetteATester.Get_P2().Get_y() == y);

    REQUIRE(raquetteATester.Get_P3().Get_x() == x );
    REQUIRE(raquetteATester.Get_P3().Get_y() == y - hauteur);

    REQUIRE(raquetteATester.Get_P4().Get_x() == x + longueur);
    REQUIRE(raquetteATester.Get_P4().Get_y() == y -hauteur);
}

void laBriqueEstElleBienValorisee(brique &briqueATester, double x, double y, double longueur, double hauteur, int typeReel, int typeVoulu, int surfaceReelle, int surfaceVoulue)
{
    REQUIRE(briqueATester.Get_P1().Get_x() == x);
    REQUIRE(briqueATester.Get_P1().Get_y() == y);

    REQUIRE(briqueATester.Get_P2().Get_x() == x+longueur);
    REQUIRE(briqueATester.Get_P2().Get_y() == y);

    REQUIRE(briqueATester.Get_P3().Get_x() == x );
    REQUIRE(briqueATester.Get_P3().Get_y() == y - hauteur);

    REQUIRE(briqueATester.Get_P4().Get_x() == x + longueur);
    REQUIRE(briqueATester.Get_P4().Get_y() == y -hauteur);

    REQUIRE(typeReel == typeVoulu);
    REQUIRE(surfaceReelle == surfaceVoulue);

}

TEST_CASE("brique")
{
    donnees monFichier("testUnitaire.txt");
    monFichier.lireDonnees();

    // on ne testera pas absolument tous les cas (càd pour chaque type de brique et de surface) pour éviter une complexité croissante, et au vu de l'indépendance de ces données entre elles

    SUBCASE("type de brique possible")
    {
        SUBCASE("brique cassable")
        {
            laBriqueEstElleBienValorisee(monFichier.briques[0], 0,0,0,0, monFichier.testType[0], 2, monFichier.testSurface[0], 4);
        }
        SUBCASE("brique incassable et surface normale")
        {
            laBriqueEstElleBienValorisee(monFichier.briques[1], 0,0,0,0, monFichier.testType[1], 1, monFichier.testSurface[1], 4);
        }
        SUBCASE("brique a surface dure")
        {
            laBriqueEstElleBienValorisee(monFichier.briques[2], 0,0,0,0, monFichier.testType[2], 2, monFichier.testSurface[2], 1);
        }
        SUBCASE("brique a surface tueuse")
        {
            laBriqueEstElleBienValorisee(monFichier.briques[3], 0,0,0,0, monFichier.testType[3], 2, monFichier.testSurface[3], 3);
        }
        SUBCASE("brique a surface molle")
        {
            laBriqueEstElleBienValorisee(monFichier.briques[4], 0,0,0,0, monFichier.testType[4], 2, monFichier.testSurface[4],2);
        }
    }

    SUBCASE("Données autres (flottants)")
    {

        SUBCASE("donnees par defaut")
        {
            laBriqueEstElleBienValorisee(monFichier.briques[5], 100,100,100,100, monFichier.testType[5], 2, monFichier.testSurface[5], 4);
        }
        SUBCASE("negatifs")
        {
            laBriqueEstElleBienValorisee(monFichier.briques[6], -100,-100,-100,-100, monFichier.testType[6], 2, monFichier.testSurface[6], 4);
        }
        SUBCASE("negatifs")
        {
            laBriqueEstElleBienValorisee(monFichier.briques[7], 1.1,2.2,3.3,4.4, monFichier.testType[7], 2, monFichier.testSurface[7], 4);
        }
        SUBCASE("decimaux")
        {
            laBriqueEstElleBienValorisee(monFichier.briques[8], 100,100,100,100, monFichier.testType[8], 2, monFichier.testSurface[8], 4);
        }

    }


}

TEST_CASE("constructeur fichier de données")
{
    donnees monFichier("testUnitaire.txt");

    REQUIRE(monFichier.testLectureInitiale == "fichier de test - ne pas modifier quoi que ce soit");


}

TEST_CASE("fonction enlèvement de commentaires")
{
    donnees monFichier("testUnitaire.txt");

    SUBCASE("commentaire simple")
    {
        string ligne{"variable  //commentaires"};
        monFichier.enleverCommentaires(ligne);
        REQUIRE(ligne == "variable  ");
    }

    SUBCASE("contre-exemple")
    {
        string ligne{"//commentaires variable  "};
        monFichier.enleverCommentaires(ligne);
        REQUIRE(ligne == "");
    }

    SUBCASE("pas de commentaire")
    {
        string ligne2{"variable"};
        monFichier.enleverCommentaires(ligne2);
        REQUIRE(ligne2 == "variable");
    }

    SUBCASE("deux commentaires")
    {
        string ligne3{"variable //commentaire //remise de commentaire"};
        monFichier.enleverCommentaires(ligne3);
        REQUIRE(ligne3 == "variable ");
    }

    SUBCASE("commentaire avec un seul /")
    {
        string ligne4{"variable /commentaire mal écrit"};
        monFichier.enleverCommentaires(ligne4);
        REQUIRE(ligne4 == "variable /commentaire mal écrit");
    }

    SUBCASE("commentaire avec ///")
    {
        string ligne4{"variable ///commentaire"};
        monFichier.enleverCommentaires(ligne4);
        REQUIRE(ligne4 == "variable ");
    }


}

TEST_CASE("test lecture d'une balle")
{
    donnees monFichier("testUnitaire.txt");
    monFichier.lireDonnees();


    SUBCASE("Constructeur normal")
    {
        SUBCASE("test normal")
        {
            laBalleEstElleBienValorisee(monFichier.balles[0], 1.1,2.2,3.3,4.4,5.5,7777);
        }
        SUBCASE("test avec des entiers")
        {
            laBalleEstElleBienValorisee(monFichier.balles[1], 1,2,3,4,5,6);
        }
        SUBCASE("test avec des negatifs")
        {
            laBalleEstElleBienValorisee(monFichier.balles[2], -1.1,-2.2,-3.3,-4.4,-5.5,-6.6);
        }
        SUBCASE("test avec des espaces")
        {
            laBalleEstElleBienValorisee(monFichier.balles[3], 1.1,2.2,3.3,4.4,5.5,6.6);
        }
    }

    SUBCASE("Constructeur reduit")
    {
        SUBCASE("test normal")
        {
            laBalleEstElleBienValorisee(monFichier.balles[4], 0,0,0,0, 1.1,7777);
        }
        SUBCASE("test avec des entiers")
        {
            laBalleEstElleBienValorisee(monFichier.balles[5], 0,0,0,0,1,2);
        }
        SUBCASE("test avec des negatifs")
        {
            laBalleEstElleBienValorisee(monFichier.balles[6], 0,0,0,0,-1.1,-2.2);
        }
        SUBCASE("test avec des espaces")
        {
            laBalleEstElleBienValorisee(monFichier.balles[7],0,0,0,0, 1.1,2.2);
        }
    }

    SUBCASE("Constructeur par défaut")
    {
        SUBCASE("test normal")
        {
            laBalleEstElleBienValorisee(monFichier.balles[8], 0,0,0,0, 1.0,1.0);
        }
        SUBCASE("test avec des espaces")
        {
            laBalleEstElleBienValorisee(monFichier.balles[9],0,0,0,0, 1.0,1.0);
        }
    }

    SUBCASE("Tableaux d'objets")
    {
        SUBCASE("x varie selon i")
        {
            SUBCASE("test normal")
            {
                for(int i = 0; i<10; i++)
                {
                    laBalleEstElleBienValorisee(monFichier.balles[i+10],1.1+ 2.2*i,3.3,4.4,5.5, 6.6,7777);
                }

            }
            SUBCASE("test avec des entiers")
            {
                for(int i = 0; i<10; i++)
                {
                    laBalleEstElleBienValorisee(monFichier.balles[i+20],1+ 2*i,2,3,4, 5,6);
                }
            }
            SUBCASE("test avec des negatifs")
            {
                for(int i = 0; i<10; i++)
                {
                    laBalleEstElleBienValorisee(monFichier.balles[i+30],-1-2*i,-1,-1,-1, -1,-1);
                }
            }
            SUBCASE("test avec des espaces")
            {
                for(int i = 0; i<10; i++)
                {
                    laBalleEstElleBienValorisee(monFichier.balles[i+40],1+ 2*i,1,1,1, 1,1);
                }
            }
            SUBCASE("test avec tableau a un element")
            {
                laBalleEstElleBienValorisee(monFichier.balles[50],1.1,3.3, 4.4,5.5, 6.6,7.7);
            }
        }
        SUBCASE("y varie selon i")
        {
            SUBCASE("test normal")
            {
                for(int i = 0; i<10; i++)
                {
                    laBalleEstElleBienValorisee(monFichier.balles[i+51],3.3,1.1+ 2.2*i,4.4,5.5, 6.6,7777);
                }
            }
            SUBCASE("test avec des entiers")
            {
                for(int i = 0; i<10; i++)
                {
                    laBalleEstElleBienValorisee(monFichier.balles[i+61],3,1+ 2*i,4,5, 6,7);
                }
            }
            SUBCASE("test avec des negatifs")
            {
                for(int i = 0; i<10; i++)
                {
                    laBalleEstElleBienValorisee(monFichier.balles[i+71],-3.3,-1.1+-2.2*i,-4.4,-5.5, -6.6,-7777);
                }
            }
            SUBCASE("test avec des espaces")
            {
                for(int i = 0; i<10; i++)
                {
                    laBalleEstElleBienValorisee(monFichier.balles[i+81],3.3,1.1+ 2.2*i,4.4,5.5, 6.6,7777);
                }
            }
            SUBCASE("test avec tableau a un element")
            {
                    laBalleEstElleBienValorisee(monFichier.balles[91],3.3,1.1,4.4,5.5, 6.6,7777);
            }
        }
    }


    SUBCASE("Tableau 2D d'objets")
    {
        SUBCASE("y varie selon i")
        {
            SUBCASE("test normal")
            {
                for(int i =0; i<5; i++)
                {
                    for(int j =0;j<5;j++)
                    {
                        laBalleEstElleBienValorisee(monFichier.balles[92+(i*5)+j],1.5+3.5*i,1.5+2.5*j,1.3,1.4,1.5,1.9);
                    }
                }
            }
            SUBCASE("test avec des entiers")
            {
                for(int i =0; i<5; i++)
                {
                    for(int j =0;j<5;j++)
                    {
                        laBalleEstElleBienValorisee(monFichier.balles[117+(i*5)+j],1+3*i,1+2*j,1,1,1,1);
                    }
                }
            }

            SUBCASE("test avec des negatifs")
            {
                for(int i =0; i<5; i++)
                {
                    for(int j =0;j<5;j++)
                    {
                        laBalleEstElleBienValorisee(monFichier.balles[142+(i*5)+j],-1.5-3.5*i,-1.5-2.5*j,-1.3,-1.4,-1.5,-1.9);
                    }
                }
            }

            SUBCASE("test avec des espaces")
            {
                for(int i =0; i<5; i++)
                {
                    for(int j =0;j<5;j++)
                    {
                        laBalleEstElleBienValorisee(monFichier.balles[167+(i*5)+j],1.5+3.5*i,1.5+2.5*j,1.3,1.4,1.5,1.9);
                    }
                }
            }

            SUBCASE("test avec tableau a un element")
            {
                laBalleEstElleBienValorisee(monFichier.balles[192],1.5,1.5,1.3,1.4,1.5,1.9);
            }
        }
    }
}


TEST_CASE("test lecture d'une raquette")
{
    donnees monFichier("testUnitaire.txt");
    monFichier.lireDonnees();

    SUBCASE("test normal")
    {
        laRaquetteEstElleBienValorisee(monFichier.raquettes[0],1.2,2.2,3.2,48.2);
    }
    SUBCASE("test avec des entiers")
    {
        laRaquetteEstElleBienValorisee(monFichier.raquettes[1],1,2,3,4);
    }
    SUBCASE("test avec des négatifs")
    {
        laRaquetteEstElleBienValorisee(monFichier.raquettes[2],-1,-2,-3.3,-4.4);
    }
    SUBCASE("test avec des espaces")
    {
        laRaquetteEstElleBienValorisee(monFichier.raquettes[3],-1,2,-3.3,4.4);
    }

}


TEST_CASE("test lecture du meilleur score")
{
    donnees monFichier("testUnitaire.txt");
    monFichier.lireDonnees();

    SUBCASE("test normal")
    {
        REQUIRE(monFichier.meilleursScores[0] == 11 );
    }
    SUBCASE("test avec des espaces")
    {
        REQUIRE(monFichier.meilleursScores[1] == 2 );
    }
}



TEST_CASE("remplacement de caractères spéciaux")
{
    string test = "(1,3)";
    donnees monFichier("testUnitaire.txt");
    monFichier.remplacerCaracSpec(test);
    REQUIRE(test == "P1V3Q");

    string test2 = "[0+20i]";
    monFichier.remplacerCaracSpec(test2);
    REQUIRE(test2 == "C0A20iD");
}



