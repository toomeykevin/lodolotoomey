/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Tile.h"
#include <iostream>

using namespace std;


namespace render{
    Tile::Tile() {
        
    }
    
    Tile::Tile(int x, int y, int w, int h){
        x=x;
        y=y;
        m_width=w;
        m_height=h;
    }
    
    int Tile::getx(){
        return x;
    }
    
    int Tile::gety(){
        return y;
    }
};