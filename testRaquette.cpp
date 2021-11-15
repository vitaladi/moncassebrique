#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
#include "doctest.h"
#include "raquette.h"
#include "Rectangle.h"
#include "Point.h"

inline void directionEgale (const Raquette &raq, int direction)
{
    FAST_REQUIRE_EQ(raq.getDirection(), direction);
}

inline void directionVaut0(const Raquette &raq)
{
    FAST_REQUIRE_EQ(raq.getDirection(),0);
}

//crée un rectangle quelconque r1 qui sera utilisé pour construire la raquette de base
Rectangle r1{{5,10},{15,10}};

TEST_CASE ("Test constructeur raquette")
{


    SUBCASE("Une raquette construite à partir d'un rectangle possède une direction égale à 0")
    {

        //creation d'une raquette r

        Raquette raq{r1};

        // verification que la direction est égale

        directionVaut0(raq);
    }

}



TEST_CASE("Test mutateurs")
{

    SUBCASE("Test mutateur setDirection")
    {
        //creation d'une raquette raQ (sa direction vaut 0)
        Raquette raQ{r1};

        // creation d'une nouvelle direction
        int maDirectionNouvelle = -1;

        // modifie la raquette raQ avec la nouvelle direction
        raQ.setDirection(maDirectionNouvelle);

        // vérifie que la direction de raQ est égale à celle de maDirectionNouvelle

        directionEgale(raQ, maDirectionNouvelle);
    }
}


TEST_CASE("Test deplace raquette Gauche")
{
    Rectangle rec {{10,12},{15,20}};

    Raquette raq {rec};



    SUBCASE("Test deplacement du point P1 (point bas gauche) de la raquette est correct  ")
    {
        // le point P1 a pour coordonnées (10,12)


        // initialisation d'une variable temporaire
        int x = rec.Get_P1().Get_x() - DECALAGE ;
        // Déplace la raquette à gauche
        raq.deplaceRaquetteGauche();

        // vérifie que le point P1 a pour coordonnées (10 - DECALAGE ,12 ) où DECALAGE est la constante de déplacement
        FAST_REQUIRE_EQ(raq.Get_P1().Get_x(), x);

    }

    SUBCASE("Test deplacement du point P4 (point haut droit) de la raquette est correct  ")
    {
        // le point P4 a pour coordonnées (15,20)

        // initialisation d'une variable temporaire
        int x = rec.Get_P4().Get_x() - DECALAGE ;
        // Déplace la raquette à gauche
        raq.deplaceRaquetteGauche();

        // vérifie que le point P4 a pour coordonnées (15 - DECALAGE ,20 ) où DECALAGE est la constante de déplacement
        FAST_REQUIRE_EQ(raq.Get_P4().Get_x(), x);
    }
}


TEST_CASE("Test deplace raquette Droit")
{

    Rectangle rec {{20,12},{30,40}};

    Raquette raq {rec};

    SUBCASE("Test deplacement du point P1 (point bas gauche) de la raquette est correct  ")
    {
        // le point P1 a pour coordonnées (20,12)


        // initialisation d'une variable temporaire
        int x = rec.Get_P1().Get_x() + DECALAGE ;
        // Déplace la raquette à droite
        raq.deplaceRaquetteDroit();

        // vérifie que le point P1 a pour coordonnées (20 + DECALAGE ,12 ) où DECALAGE est la constante de déplacement
        FAST_REQUIRE_EQ(raq.Get_P1().Get_x(), x);
    }

    SUBCASE("Test deplacement du point P4 (point haut droit) de la raquette est correct  ")
    {
        // le point P1 a pour coordonnées (30,40)

        // initialisation d'une variable temporaire
        int x = rec.Get_P4().Get_x() + DECALAGE ;
        // Déplace la raquette à droite
        raq.deplaceRaquetteDroit();

        // vérifie que le point P4 a pour coordonnées (30 + DECALAGE , 40 ) où DECALAGE est la constante de déplacement
        FAST_REQUIRE_EQ(raq.Get_P4().Get_x(), x);
    }
}
