#include "graphics.h"
#include "brique.h"
#include "balle.h"
#include "Raquette.h"
#include "surfaceNormale.h"
#include "typeBriqueIncassable.h"
#include <memory>
#include <ctime>
#include <vector>

#define KEY_LEFT       75
#define KEY_RIGHT      77
#define KEY_DELETE     83
#define DELTA  0.2

namespace interface
{
    const int DECALAGE_TERRAIN= 10;
    const int TAILLE_MUR= 3;
    void MiseAJourTerrain (std::vector <brique> Murs , Raquette& player ,std::vector <brique> &Terrain,balle Balle)
    {
        cleardevice();
        for (int i =0 ;i<Murs.size() ; ++i)
        {
            bar(Murs[i].Get_P1().Get_x(),Murs[i].Get_P1().Get_y(),Murs[i].Get_P4().Get_x(),Murs[i].Get_P4().Get_y());
        }
        bar (player.Get_P1().Get_x(),player.Get_P1().Get_y(),player.Get_P4().Get_x(),player.Get_P4().Get_y());;
        for (int i =0 ; i < Terrain.size() ; ++i)
        {
            bar (Terrain[i].Get_P1().Get_x(),Terrain[i].Get_P1().Get_y(),Terrain[i].Get_P4().Get_x(),Terrain[i].Get_P4().Get_y());
        }
        circle(Balle.x(),Balle.y(),Balle.rayon());
    }
    void OpenGame (int hauteurFenetre , int largeurFenetre , int hauteurTerrain , int largeurTerrain ,Raquette& player, std::vector <brique> &Terrain,balle Balle , std::vector <brique> &Murs)
    {
        opengraphsize (largeurFenetre , hauteurFenetre);
        setcolor(WHITE);
        player.setP1(((DECALAGE_TERRAIN+(largeurTerrain)/2)-(player.Get_P4().Get_x()-player.Get_P1().Get_x()/2)),hauteurTerrain+DECALAGE_TERRAIN);
        player.setP4((DECALAGE_TERRAIN+(largeurTerrain)/2)+(player.Get_P4().Get_x()-player.Get_P1().Get_x()/2), player.Get_P1().Get_y());
        std::unique_ptr <surface> S =std::make_unique <surfaceNormale>();
    	std::unique_ptr <typeBrique> Tb=std::make_unique <typeBriqueIncassable>();
    	Murs.push_back({{DECALAGE_TERRAIN,DECALAGE_TERRAIN,DECALAGE_TERRAIN+TAILLE_MUR,hauteurTerrain+DECALAGE_TERRAIN},S,Tb});
        Murs.push_back({{DECALAGE_TERRAIN, DECALAGE_TERRAIN, largeurTerrain+DECALAGE_TERRAIN+TAILLE_MUR , DECALAGE_TERRAIN},S,Tb});
        Murs.push_back({{largeurTerrain+DECALAGE_TERRAIN, DECALAGE_TERRAIN , largeurTerrain+DECALAGE_TERRAIN+TAILLE_MUR ,hauteurTerrain+DECALAGE_TERRAIN},S,Tb});
        Balle.modifierPosition(largeurTerrain/2 ,hauteurTerrain-Balle.rayon());
        MiseAJourTerrain(Murs ,player,Terrain,Balle);
    }
    bool action (int hauteurFenetre , int largeurFenetre , std::vector <brique> Murs ,Raquette& player, std::vector <brique> &Terrain,balle Balle)
    {
            switch (getch())
            {
            case KEY_LEFT :
                player.deplaceRaquetteGauche();
                break;
            case KEY_RIGHT :
                player.deplaceRaquetteDroit();
                break;
            case KEY_DELETE :
                return false;
        }
    MiseAJourTerrain(Murs ,player,Terrain,Balle);
    return true;
    }
    void GameLoop (int hauteurFenetre , int largeurFenetre , int hauteurTerrain , int largeurTerrain ,Raquette& player, std::vector <brique> &Terrain,balle Balle)
    {
        time_t NewTime=0;
    	time_t OldTime=time(nullptr);
    	std::vector <brique> Murs;
        OpenGame(hauteurFenetre,largeurFenetre,hauteurTerrain ,largeurTerrain ,player,Terrain,Balle,Murs);
        bool game =true;
        while (game)
        {
        NewTime=time(nullptr);
        if (difftime (NewTime ,OldTime)>=DELTA)
        {
            Balle.deplacement();
                if (kbhit())
                {
                    game=action(hauteurFenetre,largeurFenetre,Murs ,player,Terrain,Balle);
                }
                else
                {
                    MiseAJourTerrain(Murs ,player,Terrain,Balle);
                }
        }
        OldTime=NewTime;
        }
    }
}
