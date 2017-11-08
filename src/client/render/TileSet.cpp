/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TileSet.h"
#include <iostream>

using namespace std;


namespace render{
    
    TileSet::~TileSet(){}
    Tile& TileSet::getTile (state::Element& e){
        throw runtime_error("non implanté");
    }
    Tile& TileSet::getCharTile (int c){
        throw runtime_error("non implanté");
    }
};