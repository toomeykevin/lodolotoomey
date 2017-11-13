/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "StateLayer.h"
#include <iostream>
#include "Surface.h"
#include "TeamTileSet.h"
#include "NumberTileSet.h"
#include "Tile.h"
#include "state.h"

using namespace std;
using namespace state;
using namespace sf;

namespace render{
    StateLayer::StateLayer (state::State& state): m_state(state) {}
    
    void StateLayer::initSurface ()
    {
        TeamTileSet teams;
        //NumberTileSet numbers;
        
        // m_state : deux ElementTab : la liste des teams et les territories
        ElementTab& TeamBoard = m_state.getTeamBoard();
        int width = TeamBoard.getWidth();
        int height = TeamBoard.getHeight();
        
        // crée une nouvelle surface
        Surface surface_team;
        //Surface surface_number;
        
        // charge la texture : loadTexture
        string texture_team = teams.getImageFile();
        surface_team.loadTexture(texture_team);
        //string texture_number = numbers.getImageFile();
        //surface_number.loadTexture(texture_number);
        
        // initialise la liste des sprites : initHexas
        surface_team.initHexas(20);
        //surface_number.initHexas(20);
        
        // pour chaque cellule de la grille
        for (int x=0;x<height;x++)
        {
            for (int y=0;y<width;y++)
            {
                int i=x*width+y;
                // - la positionne dans la fenêtre
                surface_team.setSpriteLocation(i,x,y);
                //surface_number.setSpriteLocation(i,x,y);
                // - prend la partie de texture correspondante
                surface_team.setSpriteTexture(i,teams.getTile(*(TeamBoard.getElement(x,y))));
                //surface_number.setSpriteTexture(i,numbers.getCharTile(((Team*)(TeamBoard.getElement(x,y)))->getNbCreatures()));
            }
        }
        
        m_surface=std::unique_ptr<Surface> (&surface_team);
    }
};
