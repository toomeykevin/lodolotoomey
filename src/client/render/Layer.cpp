/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Layer.h"
#include <iostream>

using namespace std;


namespace render{
    Layer::Layer (){
        
    }
    Layer::~Layer (){}
    Surface* Layer::getSurface (){
        return m_surface.get();
    }
    void Layer::setSurface (Surface* surface){
        m_surface=std::unique_ptr<Surface>(surface);
    }
    void Layer::initSurface () {    }
    void printText (int x, int y, std::string& msg, size_t tileMinIndex, size_t tileMaxIndex){
        
    }
  
};