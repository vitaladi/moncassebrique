#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
#include "doctest.h"
#include "meilleursScore.h"


inline void joueurEnPlaceNumero(int i,  meilleursScore &m, const joueur *j)
{
    FAST_REQUIRE_EQ(m.joueurEn(i),j);
}

TEST_CASE ("La capacit� d'un tableau dynamique de meilleurs score a une capacit� �gale � la constante NB_MEILLEURSSCORE")
{
    meilleursScore m{};
    FAST_REQUIRE_EQ(m.capacite(),NB_MEILLEURSSCORE);
}

TEST_CASE ("Ajouter des joueurs")
{
    SUBCASE("Ajouter un joueur aux meilleurs score l'ajoute correctement")
    {
        meilleursScore m{};
        //cr�e un joueur j1 Arnaud
        auto j1=std::make_unique<joueur>("Arnaud");
        //cr�e un pointeur p1 qui recup�re le joueur j1
        joueur *p1=j1.get();
        //ajoute le joueur j1 aux meilleurs score m (� la place 0 du tableau)
        m.ajouteJoueurAuxMeilleursScore(std::move(j1));
        //verifie que le joueur � la place 0 de m est �gal � p1
        joueurEnPlaceNumero(0,m,p1);

        SUBCASE("Ajouter un deuxi�me joueur aux meilleurs score l'ajoute correctement")
        {
            //cr�e un joueur j2 Vital
            auto j2=std::make_unique<joueur>("Vital");
            //cr�e un pointeur p2 qui recup�re le joueur j2
            joueur *p2=j2.get();
            //ajoute le joueur j2 aux meilleurs score m (� la place 1 du tableau)
            m.ajouteJoueurAuxMeilleursScore(std::move(j2));
            //verifie que le joueur � la place 1 de m est �gal � p2
            joueurEnPlaceNumero(1,m,p2);
        }
    }
}

TEST_CASE("Mise a jour meilleurs score")
{
    SUBCASE("Trier les meilleurs score dans l'ordre d�croissant les trie correctement")
    {
        meilleursScore m{};
        //cr�e un joueur j1 Arnaud avec un score de 500
        //cr�e un pointeur p1 qui recup�re le joueur j1
        //ajoute le joueur j1 aux meilleurs score m
        auto j1=std::make_unique<joueur>("Arnaud");
        j1->setScore(500);
        joueur *p1=j1.get();
        m.ajouteJoueurAuxMeilleursScore(std::move(j1));

        //cr�e un joueur j2 Vital avec un score de 1000
        //cr�e un pointeur p2 qui recup�re le joueur j2
        //ajoute le joueur j2 aux meilleurs score m
        auto j2=std::make_unique<joueur>("Vital");
        j2->setScore(1000);
        joueur *p2=j2.get();
        m.ajouteJoueurAuxMeilleursScore(std::move(j2));

        //cr�e un joueur j3 Nathan avec un score de 200
        //cr�e un pointeur p3 qui recup�re le joueur j3
        //ajoute le joueur j3 aux meilleurs score m
        auto j3=std::make_unique<joueur>("Nathan");
        j3->setScore(200);
        joueur *p3=j3.get();
        m.ajouteJoueurAuxMeilleursScore(std::move(j3));

        //cr�e un joueur j4 JC avec un score de 600
        //cr�e un pointeur p4 qui recup�re le joueur j4
        //ajoute le joueur j4 aux meilleurs score m
        auto j4=std::make_unique<joueur>("JC");
        j4->setScore(600);
        joueur *p4=j4.get();
        m.ajouteJoueurAuxMeilleursScore(std::move(j4));

        //cr�e un joueur j5 Arthur avec un score de 100
        //cr�e un pointeur p5 qui recup�re le joueur j5
        //ajoute le joueur j5 aux meilleurs score m
        auto j5=std::make_unique<joueur>("Arthur");
        j5->setScore(100);
        joueur *p5=j5.get();
        m.ajouteJoueurAuxMeilleursScore(std::move(j5));

        //tri les meilleurs score
        m.triMeilleursScore();

        //l'ordre des meilleurs score doit �tre :
        //j2("Vital",1000) ; j4("JC",600) ; j1("Arnaud",500) ; j3("Nathan",200) ; j5("Arthur",100)
        //autrement dit on doit obtenir cet ordre : p2 ; p4 ; p1 ; p3 ; p5
        joueurEnPlaceNumero(0,m,p2);
        joueurEnPlaceNumero(1,m,p4);
        joueurEnPlaceNumero(2,m,p1);
        joueurEnPlaceNumero(3,m,p3);
        joueurEnPlaceNumero(4,m,p5);

        SUBCASE ("R�duit la liste des meilleurs score si le nombre de meilleurs scores est sup�rieur � la constante NB_MEILLEURSSCORE")
        {
            //cr�e un joueur j6 Paul avec un score de 800
            //cr�e un pointeur p6 qui recup�re le joueur j6
            //ajoute le joueur j6 aux meilleurs score m
            auto j6=std::make_unique<joueur>("Paul");
            j6->setScore(800);
            joueur *p6=j6.get();
            m.ajouteJoueurAuxMeilleursScore(std::move(j6));

            //cr�e un joueur j7 Victor avec un score de 900
            //cr�e un pointeur p7 qui recup�re le joueur j7
            //ajoute le joueur j7 aux meilleurs score m
            auto j7=std::make_unique<joueur>("Victor");
            j7->setScore(900);
            joueur *p7=j7.get();
            m.ajouteJoueurAuxMeilleursScore(std::move(j7));

            //tri les meilleurs score
            m.triMeilleursScore();

            //reduit la liste des meilleurs score pour ne garder que les NB_MEILLEURSSCORE meilleurs score
            if (m.taille()>NB_MEILLEURSSCORE)
                m.reduitListeMeilleursScore();

            //l'ordre des meilleurs score doit �tre :
            //j2("Vital",1000) ; j7("Victor",900) ; j6("Paul",800) ; j4("JC",600) ; j1("Arnaud",500)
            //autrement dit on doit obtenir cet ordre : p2 ; p7 ; p6 ; p4 ; p1
            joueurEnPlaceNumero(0,m,p2);
            joueurEnPlaceNumero(1,m,p7);
            joueurEnPlaceNumero(2,m,p6);
            joueurEnPlaceNumero(3,m,p4);
            joueurEnPlaceNumero(4,m,p1);

            //v�rifie que le nombre de meilleurs score est �gal � la constante NB_MEILLEURSSCORE
            FAST_REQUIRE_EQ(m.taille(),NB_MEILLEURSSCORE);
        }
    }
}

