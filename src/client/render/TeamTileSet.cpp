/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TeamTileSet.h"
#include <iostream>
#include "state/Team.h"

using namespace std;
using namespace state;

namespace render{
    TeamTileSet::TeamTileSet (){
        vector<Tile> m_teams(2);
    }
    
    int TeamTileSet::getCellWidth (){
        return 50;    
    }
    
    int TeamTileSet::getCellHeight (){
        return 50;
    }
    
    std::string TeamTileSet::getImageFile (){
        return "res/textures_soldats.png";
    }
    
    Tile& TeamTileSet::getTile (state::Element& e){
        if (e.isStatic() == false)
        {
            Team* p = (Team*)&e;
            if (p->getTeamStatus() == 1)
            {
                // on renvoit l'hexagone des dragons
                return m_teams[0];
            }
            if (p->getTeamStatus() == 2)
            {
                // on renvoit l'hexagone des licornes
                return m_teams[1];
            }
        }
        else
        {
            throw std::runtime_error("Le type de TileSet ne correspond pas à l'élément");
        }
    }
    
    
};