/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TeamTileSet.h"
#include <iostream>

using namespace std;


namespace render{
    TeamTileSet::TeamTileSet (){
     
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
        return m_teams[0];
    }
};