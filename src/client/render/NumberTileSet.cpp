/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NumberTileSet.h"
#include <iostream>

using namespace std;


namespace render{
    NumberTileSet::NumberTileSet (){
     
    }
    int NumberTileSet::getCellWidth (){
        return 12;    
    }
    int NumberTileSet::getCellHeight (){
        return 12;
    }
    std::string NumberTileSet::getImageFile (){
        return "res/textures_bulles.png";
    }
    Tile& NumberTileSet::getCharTile (char c){
        return m_numbers[0];
    }
};