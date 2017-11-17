/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "TileSet.h"

using namespace std;

namespace render{
    TileSet::~TileSet(){}
    
    Tile& TileSet::getTile (state::Element& e)
    {
        throw runtime_error("Fonction TileSet::getTile non définie");
    }
    
    Tile& TileSet::getCharTile (int c)
    {
        throw runtime_error("Fonction TileSet::getCharTile non définie");
    }
};