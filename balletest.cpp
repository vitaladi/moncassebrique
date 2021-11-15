#include "balle.h"
#include "doctest.h"

void laBalleABienPourValeur(balle &balleATester, double x, double y, double vx, double vy, double rayon, double vitesse)
{
    REQUIRE(balleATester.x() == x);
    REQUIRE(balleATester.y() == y);
    REQUIRE(balleATester.vx() == vx);
    REQUIRE(balleATester.vy() == vy);
    REQUIRE(balleATester.rayon() == rayon);
    REQUIRE(balleATester.vitesse() == vitesse);
}

void laPositionEstBien(balle &balleATester, double x, double y)
{
    REQUIRE(balleATester.x() == x);
    REQUIRE(balleATester.y() == y);
}

void leVecteurDeplaEstBien(balle &balleATester, double vx, double vy)
{
    REQUIRE(balleATester.vx() == vx);
    REQUIRE(balleATester.vy() == vy);
}

TEST_SUITE("Constructeurs (et Getters)"){
    TEST_CASE("Constructeur par défaut")
    {
        balle balleTest1;
        laBalleABienPourValeur(balleTest1, 0,0,0,0,1.0,1.0);
    }
    TEST_CASE("Constructeur principal")
    {
        double rayon = 20.4;
        double vitesse = 30.9;
        balle balleTest2(rayon, vitesse);
        laBalleABienPourValeur(balleTest2, 0,0,0,0,rayon,vitesse);
    }
    TEST_CASE("Constructeur secondaire")
    {
        double x = 3.2;
        double y = 7.9;
        double vx = 9.2;
        double vy = 9.0;
        double rayon = 20.4;
        double vitesse = 30.9;
        balle balleTest3(x, y, vx, vy, rayon, vitesse);
        laBalleABienPourValeur(balleTest3, x,y,vx,vy,rayon,vitesse);
    }
}

TEST_SUITE("Setters"){


    TEST_CASE("Position")
    {
        SUBCASE("Modifier")
        {
            balle balleTest4(100,200,0,0,0,0);
            double x = 3;
            double y = 5;
            balleTest4.modifierPosition(x, y);
            laPositionEstBien(balleTest4, x, y);
        }
        SUBCASE("Translater")
        {
            balle balleTest5(10,10,0,0,0,0);
            double x = 1;
            double y = 2;
            balleTest5.translaterPosition(x, y);
            laPositionEstBien(balleTest5, 11, 12);
        }
    }

    TEST_CASE("Vecteur déplacement")
    {
        SUBCASE("Modifier")
        {
            balle balleTest6(0,0,30,20,0,0);
            double vx = 111;
            double vy = 666;
            balleTest6.modifierVecteur(vx, vy);
            leVecteurDeplaEstBien(balleTest6, vx, vy);
        }
        SUBCASE("Ajouter")
        {
            balle balleTest7(0,0,1,1,0,0);
            double vx = 1;
            double vy = 2;
            balleTest7.ajouterAuVecteur(vx, vy);
            leVecteurDeplaEstBien(balleTest7, 2, 3);
        }
    }

    TEST_CASE("Vitesse")
    {
        balle balleTest8(0,0,0,0,0,5);


        SUBCASE("Augmentation")
        {
            balleTest8.changerVitesse(3);
            REQUIRE(balleTest8.vitesse() == 15);
        }
        SUBCASE("Diminution")
        {
            balleTest8.changerVitesse(0.5);
            REQUIRE(balleTest8.vitesse() == 2.5);
        }

    }
}

TEST_SUITE("Deplacement et collisions")
{
    TEST_CASE("deplace")
    {
        balle balleTest9(0,0,12,6,1,1);
        balleTest9.deplacement();

        REQUIRE(balleTest9.x() == 0.2);
        REQUIRE(balleTest9.y() == 0.1);
    }

    TEST_CASE("Collision")
    {
        SUBCASE("horizontale")
        {
            balle balleTest10(0,0,5,-3,1,1);
            balleTest10.collision(true);

            SUBCASE("Test du vecteur x")
            {
                REQUIRE(balleTest10.vx() == 5 );
            }

            SUBCASE("Test du vecteur y")
            {
                REQUIRE(balleTest10.vy() == 3 );
            }
        }

        SUBCASE("verticale")
        {
            balle balleTest11(0,0,5,-3,1,1);
            balleTest11.collision(false);

            SUBCASE("Test du vecteur x")
            {
                REQUIRE(balleTest11.vx() == -5 );
            }

            SUBCASE("Test du vecteur y")
            {
                REQUIRE(balleTest11.vy() == -3 );
            }
        }
    }
}

TEST_SUITE("Comportement de la balle (déplacement/collision)")  // A valeur documentaire pour l'utilisation, et pour bien tester le comportement de la balle
{
    TEST_CASE("Déplacement uniquement vertical")
    {
        balle balleTest12(0,0,0,21,1,1);
        balleTest12.deplacement();

        laPositionEstBien(balleTest12, 0, 0.35);


    }

    TEST_CASE("Déplacement uniquement horizontal")
    {
        balle balleTest13(0,0,3,0,1,1);
        balleTest13.deplacement();

        laPositionEstBien(balleTest13, 0.05, 0);
    }

    TEST_CASE("Accélération de balle")
    {
        balle balleTest14(0,0,120,120,1,1);


        SUBCASE("déplacement normal")
        {
            balleTest14.deplacement();
            laPositionEstBien(balleTest14, 2,2);
        }

        SUBCASE("déplacement accéléré")
        {
            balleTest14.changerVitesse(10);
            balleTest14.deplacement();
            laPositionEstBien(balleTest14, 20,20);
        }
        SUBCASE("déplacement ralenti")
        {
            balleTest14.changerVitesse(0.1);
            balleTest14.deplacement();
            laPositionEstBien(balleTest14, 0.2,0.2);
        }
    }


    TEST_CASE("Collision lors d'un déplacement")
    {
        balle balleTest15(0,0,30,30,1,1);
        balleTest15.deplacement();

        SUBCASE("Collision verticale")
        {
            balleTest15.collision(false);
            balleTest15.deplacement();

            laPositionEstBien(balleTest15, 0, 1);
        }

        SUBCASE("Collision horizontale")
        {
            balleTest15.collision(true);
            balleTest15.deplacement();

            laPositionEstBien(balleTest15, 1, 0);
        }
    }
}


