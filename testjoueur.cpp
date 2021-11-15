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
        //crée un nom nomJoueur
        string nomJoueur="Arnaud";
        //crée un joueur j avec le nom nomJoueur
        joueur j{nomJoueur};

        //vérifie que le nom de j est égal à nomJoueur
        nomEgaux(j,nomJoueur);
    }

    SUBCASE ("Un joueur construit avec un nom et un nombre de vies correspond au bon nom et au bon nombre de vies")
    {
        //crée un nom nomJoueur
        string nomJoueur="Arnaud";
        //crée un nombre de vies nbVie
        int nbVie=5;
        //crée un joueur j avec le nom nomJoueur et le nombre de vies nbVie
        joueur j{nomJoueur,nbVie};

        //vérifie que le nom de j est égal à nomJoueur et que le nombre de vies de j est égal à nbVie
        nomEgaux(j,nomJoueur);
        nbVieEgaux(j,nbVie);
    }
}

TEST_CASE("Tests données d'un joueur qui ne sont pas dans les constructeurs correctement initialisées")
{
        //crée un nom nomJoueur
        string nomJoueur="Arnaud";
        //crée un nombre de vies nbVie
        int nbVie=5;
        //crée un joueur j1 avec le nom nomJoueur
        joueur j1{nomJoueur};
        //crée un joueur j2 avec le nom nomJoueur et le nombre de vies nbVie
        joueur j2{nomJoueur,nbVie};

    SUBCASE("Quand un joueur est construit avec le constructeur de nom, son nombre de vies vaut 3")
    {
        nbVieEgaux(j1,3);
    }

    SUBCASE("Quand un joueur est construit avec n'importe quel constructeur, il a un score qui vaut 0")
    {
        //vérifie que les score de j1 et de j2 sont égaux à 0
        scoreVaut0(j1);
        scoreVaut0(j2);
    }

    SUBCASE("Quand un joueur est construit avec n'importe quel constructeur, son booléen qui indique s'il a perdu vaut faux")
    {
        //vérifie que les joueurs j1 et j2 n'ont pas perdu
        joueurPasPerdu(j1);
        joueurPasPerdu(j2);
    }
}

TEST_CASE("Tests mutateurs")
{
        //crée un nom quelconque nomJoueur
        string nomJoueur="Arnaud";
        //crée un nombre de vie quelconque nbVie
        int nbVie=5;

    SUBCASE("Test mutateur setNom")
    {
        //crée un joueur jN avec le nom nomJoueur
        joueur jN{nomJoueur};
        //crée un nom nomJoueurDiff différent de nomJoueur
        string nomJoueurDiff="Nathan";
        //modifie le joueur jN avec le nom nomJoueurDiff
        jN.setNom(nomJoueurDiff);

        //vérifie que le nom de jN est égal à nomJoueurDiff
        nomEgaux(jN,nomJoueurDiff);
    }

    SUBCASE("Test mutateur setNbVie")
    {
        //crée un joueur jV avec le nom nomJoueur et le nombre de vies nbVie
        joueur jV{nomJoueur,nbVie};
        //crée un nombre de vie nbVieDiff différent de nbVie
        int nbVieDiff=8;
        //modifie le joueur jV avec le nombre de vies nbVieDiff
        jV.setNbVie(nbVieDiff);

        //vérifie que le nombre de vies de jV est égal à nbVieDiff
        nbVieEgaux(jV,nbVieDiff);
    }

    SUBCASE("Test mutateur setScore")
    {
        //crée un joueur jS avec le nom nomJoueur
        joueur jS{nomJoueur};
        //crée un score scoreJoueur différent de 0
        int scoreJoueur=500;
        //modifie le joueur jS avec le score scoreJoueur
        jS.setScore(scoreJoueur);

        //vérifie que le score de jS est égal à scoreJoueur
        scoresEgaux(jS,scoreJoueur);
    }

    SUBCASE("Test mutateur setPerdu")
    {
        //crée un joueur jP avec le nom nomJoueur
        joueur jP{nomJoueur};
        //crée un booléen aPerdu qui vaut true
        bool aPerdu=true;
        //modifie le joueur jP avec le booléen aPerdu
        jP.setPerdu(aPerdu);

        //vérifie que le joueur jP a perdu
        joueurPerdu(jP);
    }
}

TEST_CASE("Tests mise à jour score")
{
    //crée un nom quelconque nomJoueur
    string nomJoueur="Arnaud";
    //crée un joueur j avec le nom nomJoueur
    joueur j{nomJoueur};

    SUBCASE("Lorsque un joueur touche une brique, son score est augmenté de la constante SCORE_TOUCHEBRIQUE")
    {
        //le joueur j touche une brique
        j.toucheUneBrique();

        //vérifie que le score de j est égal à SCORE_TOUCHEBRIQUE
        scoresEgaux(j,SCORE_TOUCHEBRIQUE);
    }

    SUBCASE ("Lorsqu'un joueur touche une brique n fois, son score est augmenté de n*SCORE_TOUCHEBRIQUE")
    {
        int n=10;
        //le joueur j touche une brique n fois
        for (int i=0;i<n;i++)
        {
             j.toucheUneBrique();
        }

        //vérifie que le score de j est égal à n*SCORE_TOUCHEBRIQUE
        scoresEgaux(j,n*SCORE_TOUCHEBRIQUE);
    }


    SUBCASE("Lorsqu'un joueur détruit une brique, son score est augmenté de la constante SCORE_DETRUITBRIQUE")
    {
        //le joueur j detruit une brique
        j.detruitUneBrique();

        //vérifie que le score de j est égal à SCORE_DETRUITBRIQUE
        scoresEgaux(j,SCORE_DETRUITBRIQUE);
    }
}


TEST_CASE("Tests mise à jour vies")
{
    //crée un nom quelconque nomJoueur
    string nomJoueur="Arnaud";
    //crée un nombre de vies quelconque nbVie
    int nbVie=2;
    //crée un joueur j avec le nom nomJoueur
    joueur j{nomJoueur,nbVie};

    SUBCASE("Lorsqu'un joueur perd une vie, son nombre de vies est décrémenté")
    {
        //le joueur j perd une vie
        j.perdUneVie();

        //vérifie que le nombre de vies de j a été décrémenté
        nbVieEgaux(j,nbVie-1);
    }

    SUBCASE("Lorsque un joueur n'a plus de vie, il a perdu")
    {
        //le joueur j perd 2 vies (il en a 2 au départ, il en aura donc 0)
        j.perdUneVie();
        j.perdUneVie();

        //vérifie que le joueur j a perdu car il n'a plus de vie
        joueurPerdu(j);
    }
}
