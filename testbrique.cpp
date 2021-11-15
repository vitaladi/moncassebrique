#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
#include "doctest.h"
#include "brique.h"
#include "surfaceDure.h"
#include "surfaceNormale.h"
#include "surfaceMolle.h"
#include "surfaceTueuse.h"
#include "typeBriqueCassable.h"
#include "typeBriqueIncassable.h"


using std::make_unique;


inline void surfacesEgales (const brique &b, const surface* s)
{
        FAST_REQUIRE_EQ(b.getSurface(),s);
}

inline void typesBriqueEgaux (const brique &b, const typeBrique* tb)
{
        FAST_REQUIRE_EQ(b.getTypeBrique(),tb);
}

inline void briqueDetruite (const brique &b)
{
        FAST_REQUIRE_EQ(b.getEstDetruite(),true);
}

inline void briquePasDetruite (const brique &b)
{
        FAST_REQUIRE_EQ(b.getEstDetruite(),false);
}

//crée un rectangle quelconque r qui sera utilisé pour construire des briques
Rectangle r{{12,15},{25,30}};

TEST_CASE ("Test constructeur brique avec les bonnes surfaces")
{
    //crée un type de brique quelconque tb qui sera utilisé pour construire des briques
    unique_ptr<typeBrique> tb=make_unique<typeBriqueCassable>(3);

    SUBCASE("Une brique construite avec une surface normale correspond à la bonne surface")
    {
        //crée une surface normale sN
        unique_ptr<surface> sN=make_unique<surfaceNormale>();
        //crée un pointeur p qui recupère la surface normale sN
        surface* p=sN.get();
        //crée une brique b avec le rectangle r, la surface normale sN et le type de brique tb
        brique b{r,sN,tb};

        //vérifie que la surface de b est égale à p
        surfacesEgales(b,p);
    }

    SUBCASE("Une brique construite avec une surface dure correspond à la bonne surface")
    {
        //crée une surface dure sD
        unique_ptr<surface> sD=make_unique<surfaceDure>(0.3);
        //crée un pointeur p qui recupère la surface dure sD
        surface* p=sD.get();
        //crée une brique b avec le rectangle r, la surface dure sD et le type de brique tb
        brique b{r,sD,tb};

        //vérifie que la surface de b est égale à p
        surfacesEgales(b,p);
    }

    SUBCASE("Une brique construite avec une surface molle correspond à la bonne surface")
    {
        //crée une surface molle sM
        unique_ptr<surface> sM=make_unique<surfaceMolle>(0.4);
        //crée un pointeur p qui recupère la surface molle sM
        surface* p=sM.get();
        //crée une brique b avec le rectangle r, la surface molle sM et le type de brique tb
        brique b{r,sM,tb};

        //vérifie que la surface de b est égale à p
        surfacesEgales(b,p);
    }

    SUBCASE("Une brique construite avec une surface tueuse correspond à la bonne surface")
    {
        //crée une surface tueuse sT
        unique_ptr<surface> sT=make_unique<surfaceTueuse>();
        //crée un pointeur p qui recupère la surface tueuse sT
        surface* p=sT.get();
        //crée une brique b avec le rectangle r, la surface tueuse sT et le type de brique tb
        brique b{r,sT,tb};

        //vérifie que la surface de b est égale à p
        surfacesEgales(b,p);
    }
}


TEST_CASE("Test constructeur brique avec les bons types de brique")
{
     //crée une surface quelconque s qui sera utilisée pour construire des briques
    unique_ptr<surface> s=make_unique<surfaceNormale>();

    SUBCASE("Une brique construite avec un type de brique cassable correspond au bon type de brique")
    {
        //crée un type de brique cassable tbC
        unique_ptr<typeBrique> tbC=make_unique<typeBriqueCassable>(5);
        //crée un pointeur p qui récupère le type de brique tbC
        typeBrique* p=tbC.get();
        //crée une brique b avec le rectangle r, la surface s et le type de brique tbC
        brique b{r,s,tbC};

        //vérifie que le type de brique de b est égal à p
        typesBriqueEgaux(b,p);
    }

    SUBCASE("Une brique construite avec un type de brique incassable correspond au bon type de brique")
    {
         //crée un type de brique incassable tbI
        unique_ptr<typeBrique> tbI=make_unique<typeBriqueIncassable>();
        //crée un pointeur p qui récupère le type de brique tbI
        typeBrique* p=tbI.get();
        //crée une brique b avec le rectangle r, la surface s et le type de brique tbI
        brique b{r,s,tbI};

        //vérifie que le type de brique de b est égal à p
        typesBriqueEgaux(b,p);
    }
}


TEST_CASE ("Test mutateurs")
{
    //crée une surface quelconque s qui sera utilisée pour construire une brique
    unique_ptr<surface> s=make_unique<surfaceNormale>();
    //crée un type de brique quelconque tb qui sera utilisé pour construire une brique
    unique_ptr<typeBrique> tb=make_unique<typeBriqueCassable>(3);

    SUBCASE("Test mutateur setSurface")
    {
        //crée une brique b avec le rectangle r, la surface s et le type de brique tb
        brique b{r,s,tb};
        //crée une surface sDiff différente de la surface s
        unique_ptr<surface> sDiff=make_unique<surfaceMolle>(0.1);
        //crée un pointeur p qui recupère sDiff
        surface* p=sDiff.get();
        //modifie la brique b avec la surface sDiff
        b.setSurface(sDiff);

        //vérifie que la surface de b est égale à p
        surfacesEgales(b,p);
    }

    SUBCASE("Test mutateur setTypeBrique")
    {
        //crée une brique b avec le rectangle r, la surface s et le type de brique tb
        brique b{r,s,tb};
        //crée un type de brique tbDiff différent du type de brique tb
        unique_ptr<typeBrique> tbDiff=make_unique<typeBriqueIncassable>();
        //crée un pointeur p qui recupère tbDiff
        typeBrique* p=tbDiff.get();
        //modifie la brique b avec la surface tbDiff
        b.setTypeBrique(tbDiff);

        //vérifie que le type de brique de b est égal à p
        typesBriqueEgaux(b,p);
    }

    SUBCASE("Test mutateur setEstDetruite")
    {
        //crée une brique b avec le rectangle r, la surface s et le type de brique tb (par défaut une brique n'est pas détruite)
        brique b{r,s,tb};
        //crée un booléen detruite qui vaut true
        bool detruite=true;
        //modifie la brique b avec le booléen t pour rendre la brique détruite
        b.setEstDetruite(detruite);

        //verifie que la brique est bien detruite
        briqueDetruite(b);
    }
}

TEST_CASE ("Test brique detruite")
{
    //crée une surface quelconque s qui sera utilisée pour construire une brique
    unique_ptr<surface> s=make_unique<surfaceNormale>();

    SUBCASE("Type de brique cassable avec 1 collision nécessaire")
    {
        //crée un type de brique cassable tb1 avec 1 collision nécessaire
        unique_ptr<typeBrique> tb1=make_unique<typeBriqueCassable>(1);
        //crée un pointeur p qui récupère le type de brique tb1
        typeBrique* p=tb1.get();
        //crée une brique b avec le rectangle r, la surface s et le type de brique tb1
        brique b{r,s,tb1};
        //ici brique touchée 1x
        b.briqueTouchee(p);
        //détruit la brique car la brique b a besoin d'1 collision pour être détruite

       //vérifie que la brique est détruite
       briqueDetruite(b);
    }

    SUBCASE("Type de brique cassable avec 3 collisions nécessaires")
    {
        int nbCollisionsNecessaires=3;
        //crée un type de brique cassable tb3 avec nbCollisionsNecessaires qui vaut 3
        unique_ptr<typeBrique> tb3=make_unique<typeBriqueCassable>(nbCollisionsNecessaires);
        //crée un pointeur p qui récupère le type de brique tb3
        typeBrique* p=tb3.get();
        //crée une brique b avec le rectangle r, la surface s et le type de brique tb3
        brique b{r,s,tb3};
        //ici brique touchée 3x (nbCollisionsNecessaires=3)
        for (int i=0;i<nbCollisionsNecessaires;++i)
        {
            b.briqueTouchee(p);
        }
        //détruit la brique car la brique b a besoin de 3 collisions pour être détruite

       //vérifie que la brique est détruite
       briqueDetruite(b);
    }
}


TEST_CASE ("Test brique non detruite")
{
    //crée une surface quelconque s qui sera utilisée pour construire une brique
    unique_ptr<surface> s=make_unique<surfaceNormale>();

    SUBCASE("Type de brique cassable avec 5 collisions nécessaires")
    {
        int nbCollisionsNecessaires=5;
        //crée un type de brique cassable tb5 avec nbCollisionsNecessaires qui vaut 5
        unique_ptr<typeBrique> tb5=make_unique<typeBriqueCassable>(nbCollisionsNecessaires);
        //crée un pointeur p qui récupère le type de brique tb
        typeBrique* p=tb5.get();
        //crée une brique b avec le rectangle r, la surface s et le type de brique tb
        brique b{r,s,tb5};
        //ici brique touchée 3x
        for (int i=0;i<3;++i)
        {
            b.briqueTouchee(p);
        }
        //ne détruit pas la brique car la brique b a besoin de 5 collisions pour être détruite

       //vérifie que la brique n'est pas détruite
       briquePasDetruite(b);
    }

    SUBCASE("Type de brique incassable")
    {
        //crée un type de brique incassable tbi
        unique_ptr<typeBrique> tbi=make_unique<typeBriqueIncassable>();
        //crée un pointeur p qui récupère le type de brique tbi
        typeBrique* p=tbi.get();
        //crée une brique b avec le rectangle r, la surface s et le type de brique tbi
        brique b{r,s,tbi};
        //ici brique touchée 10x
        for (int i=0;i<10;++i)
        {
            b.briqueTouchee(p);
        }
        //ne détruit pas la brique car la brique b est incassable

       //vérifie que la brique n'est pas détruite
       briquePasDetruite(b);
    }
}

TEST_CASE("Test pourcentages surfaces dures et molles")
{
    SUBCASE("Le pourcentage d'une surface dure est compris entre 0.0 et 1.0")
    {
        //crée une surfaceDure sD d'un pourcentage=0.3
        surfaceDure sD {0.3};

        //vérifie que le pourcentage de sD >= 0.0
        FAST_REQUIRE_GE(sD.pourcentage(),0.0);
        //vérifie que le pourcentage de sD <= 1.0
        FAST_REQUIRE_LE(sD.pourcentage(),1.0);
    }

    SUBCASE("Le pourcentage d'une surface molle est compris entre 0.0 et 1.0")
    {
        //crée une surfaceMolle sM d'un pourcentage=0.9
        surfaceMolle sM {0.9};

        //vérifie que le pourcentage de sM >= 0.0
        FAST_REQUIRE_GE(sM.pourcentage(),0.0);
        //vérifie que le pourcentage de sM <= 1.0
        FAST_REQUIRE_LE(sM.pourcentage(),1.0);
    }
}

