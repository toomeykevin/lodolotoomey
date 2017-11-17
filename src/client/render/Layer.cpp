/*
 * To change this license header, choose License Headers in Project Properties.
 * To
 *  change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Layer.h"

using namespace std;

namespace render{
    Layer::Layer (){}
    Layer::~Layer (){}
    
    Surface* Layer::getSurface ()
    {
        return m_surface.get();
    }
    
    void Layer::setSurface (Surface* surface)
    {
        m_surface=std::unique_ptr<Surface>(surface);
    }
    
    void printText (int x, int y, std::string& msg, size_t tileMinIndex, size_t tileMaxIndex)
    {
        throw std::runtime_error("La fonction printText n'est pas définie pour le moment");
    }
    
    TileSet* Layer::getTileSet()
    {
        return m_tileSet.get();
    }
    
    void Layer::setTileSet(TileSet* tileSet)
    {
        m_tileSet=std::shared_ptr<TileSet>(tileSet);
    }
    
    void Layer::initSurface() {};
  
};