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

//cr�e un rectangle quelconque r qui sera utilis� pour construire des briques
Rectangle r{{12,15},{25,30}};

TEST_CASE ("Test constructeur brique avec les bonnes surfaces")
{
    //cr�e un type de brique quelconque tb qui sera utilis� pour construire des briques
    unique_ptr<typeBrique> tb=make_unique<typeBriqueCassable>(3);

    SUBCASE("Une brique construite avec une surface normale correspond � la bonne surface")
    {
        //cr�e une surface normale sN
        unique_ptr<surface> sN=make_unique<surfaceNormale>();
        //cr�e un pointeur p qui recup�re la surface normale sN
        surface* p=sN.get();
        //cr�e une brique b avec le rectangle r, la surface normale sN et le type de brique tb
        brique b{r,sN,tb};

        //v�rifie que la surface de b est �gale � p
        surfacesEgales(b,p);
    }

    SUBCASE("Une brique construite avec une surface dure correspond � la bonne surface")
    {
        //cr�e une surface dure sD
        unique_ptr<surface> sD=make_unique<surfaceDure>(0.3);
        //cr�e un pointeur p qui recup�re la surface dure sD
        surface* p=sD.get();
        //cr�e une brique b avec le rectangle r, la surface dure sD et le type de brique tb
        brique b{r,sD,tb};

        //v�rifie que la surface de b est �gale � p
        surfacesEgales(b,p);
    }

    SUBCASE("Une brique construite avec une surface molle correspond � la bonne surface")
    {
        //cr�e une surface molle sM
        unique_ptr<surface> sM=make_unique<surfaceMolle>(0.4);
        //cr�e un pointeur p qui recup�re la surface molle sM
        surface* p=sM.get();
        //cr�e une brique b avec le rectangle r, la surface molle sM et le type de brique tb
        brique b{r,sM,tb};

        //v�rifie que la surface de b est �gale � p
        surfacesEgales(b,p);
    }

    SUBCASE("Une brique construite avec une surface tueuse correspond � la bonne surface")
    {
        //cr�e une surface tueuse sT
        unique_ptr<surface> sT=make_unique<surfaceTueuse>();
        //cr�e un pointeur p qui recup�re la surface tueuse sT
        surface* p=sT.get();
        //cr�e une brique b avec le rectangle r, la surface tueuse sT et le type de brique tb
        brique b{r,sT,tb};

        //v�rifie que la surface de b est �gale � p
        surfacesEgales(b,p);
    }
}


TEST_CASE("Test constructeur brique avec les bons types de brique")
{
     //cr�e une surface quelconque s qui sera utilis�e pour construire des briques
    unique_ptr<surface> s=make_unique<surfaceNormale>();

    SUBCASE("Une brique construite avec un type de brique cassable correspond au bon type de brique")
    {
        //cr�e un type de brique cassable tbC
        unique_ptr<typeBrique> tbC=make_unique<typeBriqueCassable>(5);
        //cr�e un pointeur p qui r�cup�re le type de brique tbC
        typeBrique* p=tbC.get();
        //cr�e une brique b avec le rectangle r, la surface s et le type de brique tbC
        brique b{r,s,tbC};

        //v�rifie que le type de brique de b est �gal � p
        typesBriqueEgaux(b,p);
    }

    SUBCASE("Une brique construite avec un type de brique incassable correspond au bon type de brique")
    {
         //cr�e un type de brique incassable tbI
        unique_ptr<typeBrique> tbI=make_unique<typeBriqueIncassable>();
        //cr�e un pointeur p qui r�cup�re le type de brique tbI
        typeBrique* p=tbI.get();
        //cr�e une brique b avec le rectangle r, la surface s et le type de brique tbI
        brique b{r,s,tbI};

        //v�rifie que le type de brique de b est �gal � p
        typesBriqueEgaux(b,p);
    }
}


TEST_CASE ("Test mutateurs")
{
    //cr�e une surface quelconque s qui sera utilis�e pour construire une brique
    unique_ptr<surface> s=make_unique<surfaceNormale>();
    //cr�e un type de brique quelconque tb qui sera utilis� pour construire une brique
    unique_ptr<typeBrique> tb=make_unique<typeBriqueCassable>(3);

    SUBCASE("Test mutateur setSurface")
    {
        //cr�e une brique b avec le rectangle r, la surface s et le type de brique tb
        brique b{r,s,tb};
        //cr�e une surface sDiff diff�rente de la surface s
        unique_ptr<surface> sDiff=make_unique<surfaceMolle>(0.1);
        //cr�e un pointeur p qui recup�re sDiff
        surface* p=sDiff.get();
        //modifie la brique b avec la surface sDiff
        b.setSurface(sDiff);

        //v�rifie que la surface de b est �gale � p
        surfacesEgales(b,p);
    }

    SUBCASE("Test mutateur setTypeBrique")
    {
        //cr�e une brique b avec le rectangle r, la surface s et le type de brique tb
        brique b{r,s,tb};
        //cr�e un type de brique tbDiff diff�rent du type de brique tb
        unique_ptr<typeBrique> tbDiff=make_unique<typeBriqueIncassable>();
        //cr�e un pointeur p qui recup�re tbDiff
        typeBrique* p=tbDiff.get();
        //modifie la brique b avec la surface tbDiff
        b.setTypeBrique(tbDiff);

        //v�rifie que le type de brique de b est �gal � p
        typesBriqueEgaux(b,p);
    }

    SUBCASE("Test mutateur setEstDetruite")
    {
        //cr�e une brique b avec le rectangle r, la surface s et le type de brique tb (par d�faut une brique n'est pas d�truite)
        brique b{r,s,tb};
        //cr�e un bool�en detruite qui vaut true
        bool detruite=true;
        //modifie la brique b avec le bool�en t pour rendre la brique d�truite
        b.setEstDetruite(detruite);

        //verifie que la brique est bien detruite
        briqueDetruite(b);
    }
}

TEST_CASE ("Test brique detruite")
{
    //cr�e une surface quelconque s qui sera utilis�e pour construire une brique
    unique_ptr<surface> s=make_unique<surfaceNormale>();

    SUBCASE("Type de brique cassable avec 1 collision n�cessaire")
    {
        //cr�e un type de brique cassable tb1 avec 1 collision n�cessaire
        unique_ptr<typeBrique> tb1=make_unique<typeBriqueCassable>(1);
        //cr�e un pointeur p qui r�cup�re le type de brique tb1
        typeBrique* p=tb1.get();
        //cr�e une brique b avec le rectangle r, la surface s et le type de brique tb1
        brique b{r,s,tb1};
        //ici brique touch�e 1x
        b.briqueTouchee(p);
        //d�truit la brique car la brique b a besoin d'1 collision pour �tre d�truite

       //v�rifie que la brique est d�truite
       briqueDetruite(b);
    }

    SUBCASE("Type de brique cassable avec 3 collisions n�cessaires")
    {
        int nbCollisionsNecessaires=3;
        //cr�e un type de brique cassable tb3 avec nbCollisionsNecessaires qui vaut 3
        unique_ptr<typeBrique> tb3=make_unique<typeBriqueCassable>(nbCollisionsNecessaires);
        //cr�e un pointeur p qui r�cup�re le type de brique tb3
        typeBrique* p=tb3.get();
        //cr�e une brique b avec le rectangle r, la surface s et le type de brique tb3
        brique b{r,s,tb3};
        //ici brique touch�e 3x (nbCollisionsNecessaires=3)
        for (int i=0;i<nbCollisionsNecessaires;++i)
        {
            b.briqueTouchee(p);
        }
        //d�truit la brique car la brique b a besoin de 3 collisions pour �tre d�truite

       //v�rifie que la brique est d�truite
       briqueDetruite(b);
    }
}


TEST_CASE ("Test brique non detruite")
{
    //cr�e une surface quelconque s qui sera utilis�e pour construire une brique
    unique_ptr<surface> s=make_unique<surfaceNormale>();

    SUBCASE("Type de brique cassable avec 5 collisions n�cessaires")
    {
        int nbCollisionsNecessaires=5;
        //cr�e un type de brique cassable tb5 avec nbCollisionsNecessaires qui vaut 5
        unique_ptr<typeBrique> tb5=make_unique<typeBriqueCassable>(nbCollisionsNecessaires);
        //cr�e un pointeur p qui r�cup�re le type de brique tb
        typeBrique* p=tb5.get();
        //cr�e une brique b avec le rectangle r, la surface s et le type de brique tb
        brique b{r,s,tb5};
        //ici brique touch�e 3x
        for (int i=0;i<3;++i)
        {
            b.briqueTouchee(p);
        }
        //ne d�truit pas la brique car la brique b a besoin de 5 collisions pour �tre d�truite

       //v�rifie que la brique n'est pas d�truite
       briquePasDetruite(b);
    }

    SUBCASE("Type de brique incassable")
    {
        //cr�e un type de brique incassable tbi
        unique_ptr<typeBrique> tbi=make_unique<typeBriqueIncassable>();
        //cr�e un pointeur p qui r�cup�re le type de brique tbi
        typeBrique* p=tbi.get();
        //cr�e une brique b avec le rectangle r, la surface s et le type de brique tbi
        brique b{r,s,tbi};
        //ici brique touch�e 10x
        for (int i=0;i<10;++i)
        {
            b.briqueTouchee(p);
        }
        //ne d�truit pas la brique car la brique b est incassable

       //v�rifie que la brique n'est pas d�truite
       briquePasDetruite(b);
    }
}

TEST_CASE("Test pourcentages surfaces dures et molles")
{
    SUBCASE("Le pourcentage d'une surface dure est compris entre 0.0 et 1.0")
    {
        //cr�e une surfaceDure sD d'un pourcentage=0.3
        surfaceDure sD {0.3};

        //v�rifie que le pourcentage de sD >= 0.0
        FAST_REQUIRE_GE(sD.pourcentage(),0.0);
        //v�rifie que le pourcentage de sD <= 1.0
        FAST_REQUIRE_LE(sD.pourcentage(),1.0);
    }

    SUBCASE("Le pourcentage d'une surface molle est compris entre 0.0 et 1.0")
    {
        //cr�e une surfaceMolle sM d'un pourcentage=0.9
        surfaceMolle sM {0.9};

        //v�rifie que le pourcentage de sM >= 0.0
        FAST_REQUIRE_GE(sM.pourcentage(),0.0);
        //v�rifie que le pourcentage de sM <= 1.0
        FAST_REQUIRE_LE(sM.pourcentage(),1.0);
    }
}

