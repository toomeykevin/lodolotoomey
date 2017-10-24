/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Surface.h"
#include <iostream>

using namespace std;


namespace render{
    void Surface::loadTexture (std::string& imageFile){}
    void Surface::initHexas (int count){}
    void Surface::setSpriteLocation (int i, int x, int y){}
    void Surface::setSpriteTexture (int i, Tile& tex){}
    void Surface::draw (sf::RenderTarget& target, sf::RenderStates states){}
};