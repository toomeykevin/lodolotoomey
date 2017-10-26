/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TerritoryTileSet.h"
#include <iostream>
#include "state/Territory.h"

using namespace std;
using namespace state;


namespace render{
    TerritoryTileSet::TerritoryTileSet (){
        vector<Tile> m_territories(3);
        Tile licorne(0,0,120,140);
        Tile dragon(240,0,120,140);
        Tile impossible(120,0,120,140);
        m_territories[0]=licorne;
        m_territories[1]=impossible;
        m_territories[2]=dragon;
    }
    
    int TerritoryTileSet::getCellWidth (){
        return 120;    
    }
    
    int TerritoryTileSet::getCellHeight (){
        return 140;
    }
    
    std::string TerritoryTileSet::getImageFile (){
        return "res/textures_territoires.png";
    }
    
    Tile& TerritoryTileSet::getTile (state::Element& e){
        /*if (e.isStatic() == true)
        {
            Territory* p = (Territory*)&e;
            if (p->getTerritoryStatus() == 3)
            {
                // on renvoie l'hexagone inaccessible
                return m_territories[1];
            }
            if (p->getTerritoryStatus() == 2)
            {
                // on renvoit l'hexagone des dragons
                return m_territories[2];
            }
            if (p->getTerritoryStatus() == 1)
            {
                // on renvoit l'hexagone des licornes
                return m_territories[0];
            }
        }
        else
        {
            throw std::runtime_error("Le type de TileSet ne correspond pas à l'élément");
        }*/
        return m_territories[0];
        
    }
};