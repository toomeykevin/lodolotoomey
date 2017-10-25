/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TerritoryTileSet.h"
#include <iostream>

using namespace std;


namespace render{
    TerritoryTileSet::TerritoryTileSet (){
     
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
        return m_territories[0];
    }
};