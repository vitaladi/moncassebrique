#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
#include "doctest.h"
#include "joueur.h"

inline void nomEgaux (const joueur &j, string nomJoueur)
{
        FAST_REQUIRE_EQ(j.getNom(),nomJoueur);
}

inline void nbVieEgaux(const joueur &j, int nbVie)
{
        FAST_REQUIRE_EQ(j.getNbVie(),nbVie);
}

inline void scoreVaut0 (const joueur &j)
{
        FAST_REQUIRE_EQ(j.getScore(),0);
}

inline void joueurPasPerdu(const joueur &j)
{
        FAST_REQUIRE_EQ(j.getPerdu(),false);
}

inline void scoresEgaux(const joueur &j, int score)
{
        FAST_REQUIRE_EQ(j.getScore(),score);
}

inline void joueurPerdu (const joueur &j)
{
        FAST_REQUIRE_EQ(j.getPerdu(),true);
}

TEST_CASE ("Test constructeurs joueur")
{
    SUBCASE("Un joueur construit avec un nom correspond au bon nom")
    {
        //cr�e un nom nomJoueur
        string nomJoueur="Arnaud";
        //cr�e un joueur j avec le nom nomJoueur
        joueur j{nomJoueur};

        //v�rifie que le nom de j est �gal � nomJoueur
        nomEgaux(j,nomJoueur);
    }

    SUBCASE ("Un joueur construit avec un nom et un nombre de vies correspond au bon nom et au bon nombre de vies")
    {
        //cr�e un nom nomJoueur
        string nomJoueur="Arnaud";
        //cr�e un nombre de vies nbVie
        int nbVie=5;
        //cr�e un joueur j avec le nom nomJoueur et le nombre de vies nbVie
        joueur j{nomJoueur,nbVie};

        //v�rifie que le nom de j est �gal � nomJoueur et que le nombre de vies de j est �gal � nbVie
        nomEgaux(j,nomJoueur);
        nbVieEgaux(j,nbVie);
    }
}

TEST_CASE("Tests donn�es d'un joueur qui ne sont pas dans les constructeurs correctement initialis�es")
{
        //cr�e un nom nomJoueur
        string nomJoueur="Arnaud";
        //cr�e un nombre de vies nbVie
        int nbVie=5;
        //cr�e un joueur j1 avec le nom nomJoueur
        joueur j1{nomJoueur};
        //cr�e un joueur j2 avec le nom nomJoueur et le nombre de vies nbVie
        joueur j2{nomJoueur,nbVie};

    SUBCASE("Quand un joueur est construit avec le constructeur de nom, son nombre de vies vaut 3")
    {
        nbVieEgaux(j1,3);
    }

    SUBCASE("Quand un joueur est construit avec n'importe quel constructeur, il a un score qui vaut 0")
    {
        //v�rifie que les score de j1 et de j2 sont �gaux � 0
        scoreVaut0(j1);
        scoreVaut0(j2);
    }

    SUBCASE("Quand un joueur est construit avec n'importe quel constructeur, son bool�en qui indique s'il a perdu vaut faux")
    {
        //v�rifie que les joueurs j1 et j2 n'ont pas perdu
        joueurPasPerdu(j1);
        joueurPasPerdu(j2);
    }
}

TEST_CASE("Tests mutateurs")
{
        //cr�e un nom quelconque nomJoueur
        string nomJoueur="Arnaud";
        //cr�e un nombre de vie quelconque nbVie
        int nbVie=5;

    SUBCASE("Test mutateur setNom")
    {
        //cr�e un joueur jN avec le nom nomJoueur
        joueur jN{nomJoueur};
        //cr�e un nom nomJoueurDiff diff�rent de nomJoueur
        string nomJoueurDiff="Nathan";
        //modifie le joueur jN avec le nom nomJoueurDiff
        jN.setNom(nomJoueurDiff);

        //v�rifie que le nom de jN est �gal � nomJoueurDiff
        nomEgaux(jN,nomJoueurDiff);
    }

    SUBCASE("Test mutateur setNbVie")
    {
        //cr�e un joueur jV avec le nom nomJoueur et le nombre de vies nbVie
        joueur jV{nomJoueur,nbVie};
        //cr�e un nombre de vie nbVieDiff diff�rent de nbVie
        int nbVieDiff=8;
        //modifie le joueur jV avec le nombre de vies nbVieDiff
        jV.setNbVie(nbVieDiff);

        //v�rifie que le nombre de vies de jV est �gal � nbVieDiff
        nbVieEgaux(jV,nbVieDiff);
    }

    SUBCASE("Test mutateur setScore")
    {
        //cr�e un joueur jS avec le nom nomJoueur
        joueur jS{nomJoueur};
        //cr�e un score scoreJoueur diff�rent de 0
        int scoreJoueur=500;
        //modifie le joueur jS avec le score scoreJoueur
        jS.setScore(scoreJoueur);

        //v�rifie que le score de jS est �gal � scoreJoueur
        scoresEgaux(jS,scoreJoueur);
    }

    SUBCASE("Test mutateur setPerdu")
    {
        //cr�e un joueur jP avec le nom nomJoueur
        joueur jP{nomJoueur};
        //cr�e un bool�en aPerdu qui vaut true
        bool aPerdu=true;
        //modifie le joueur jP avec le bool�en aPerdu
        jP.setPerdu(aPerdu);

        //v�rifie que le joueur jP a perdu
        joueurPerdu(jP);
    }
}

TEST_CASE("Tests mise � jour score")
{
    //cr�e un nom quelconque nomJoueur
    string nomJoueur="Arnaud";
    //cr�e un joueur j avec le nom nomJoueur
    joueur j{nomJoueur};

    SUBCASE("Lorsque un joueur touche une brique, son score est augment� de la constante SCORE_TOUCHEBRIQUE")
    {
        //le joueur j touche une brique
        j.toucheUneBrique();

        //v�rifie que le score de j est �gal � SCORE_TOUCHEBRIQUE
        scoresEgaux(j,SCORE_TOUCHEBRIQUE);
    }

    SUBCASE ("Lorsqu'un joueur touche une brique n fois, son score est augment� de n*SCORE_TOUCHEBRIQUE")
    {
        int n=10;
        //le joueur j touche une brique n fois
        for (int i=0;i<n;i++)
        {
             j.toucheUneBrique();
        }

        //v�rifie que le score de j est �gal � n*SCORE_TOUCHEBRIQUE
        scoresEgaux(j,n*SCORE_TOUCHEBRIQUE);
    }


    SUBCASE("Lorsqu'un joueur d�truit une brique, son score est augment� de la constante SCORE_DETRUITBRIQUE")
    {
        //le joueur j detruit une brique
        j.detruitUneBrique();

        //v�rifie que le score de j est �gal � SCORE_DETRUITBRIQUE
        scoresEgaux(j,SCORE_DETRUITBRIQUE);
    }
}


TEST_CASE("Tests mise � jour vies")
{
    //cr�e un nom quelconque nomJoueur
    string nomJoueur="Arnaud";
    //cr�e un nombre de vies quelconque nbVie
    int nbVie=2;
    //cr�e un joueur j avec le nom nomJoueur
    joueur j{nomJoueur,nbVie};

    SUBCASE("Lorsqu'un joueur perd une vie, son nombre de vies est d�cr�ment�")
    {
        //le joueur j perd une vie
        j.perdUneVie();

        //v�rifie que le nombre de vies de j a �t� d�cr�ment�
        nbVieEgaux(j,nbVie-1);
    }

    SUBCASE("Lorsque un joueur n'a plus de vie, il a perdu")
    {
        //le joueur j perd 2 vies (il en a 2 au d�part, il en aura donc 0)
        j.perdUneVie();
        j.perdUneVie();

        //v�rifie que le joueur j a perdu car il n'a plus de vie
        joueurPerdu(j);
    }
}
