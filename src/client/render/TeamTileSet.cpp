/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "TeamTileSet.h"
#include "state/Team.h"

using namespace std;
using namespace state;

namespace render{
    TeamTileSet::TeamTileSet (): m_teams(3)
    {
        m_teams[0] = Tile(0,0,120,140);
        m_teams[1] = Tile(120,0,120,140);
        m_teams[2] = Tile(240,0,120,140);
    }
    
    int TeamTileSet::getCellWidth ()
    {
        return 120;    
    }
    
    int TeamTileSet::getCellHeight ()
    {
        return 140;
    }
    
    std::string TeamTileSet::getImageFile ()
    {
        return "res/textures_soldats.png";
    }
    
    Tile& TeamTileSet::getTile (state::Element& e)
    {
        if (e.isStatic() == false)
        {
            Team& p = (Team&)e;
            if (p.getTeamStatus() == 2)
            {
                // on renvoit l'icône des dragons
                return m_teams[0];
            }
            if (p.getTeamStatus() == 1)
            {
                // on renvoit l'icône des licornes
                return m_teams[1];
            }
            if (p.getTeamStatus() == 3)
            {
                // on renvoit une texture vide
                return m_teams[2];
            }
        }
        else
        {
            throw std::runtime_error("Le type de TileSet ne correspond pas à l'élément");
        }
        
        return m_teams[2];
    }
    
    
};