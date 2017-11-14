/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "ElementTabLayer.h"
#include <iostream>
#include "Surface.h"
#include "TerritoryTileSet.h"
#include "Tile.h"
#include "state.h"

using namespace std;
using namespace state;
using namespace sf;



namespace render{
    ElementTabLayer::ElementTabLayer(state::ElementTab& tab) : m_tab(tab) {}
    
    void ElementTabLayer::initSurface()
    {
        m_tileSet = std::shared_ptr<TileSet> (new TerritoryTileSet());
        
        int width = m_tab.getWidth();
        int height = m_tab.getHeight();
        
        // crée une nouvelle surface
        Surface* surface_territory = new Surface();
        
        // charge la texture : loadTexture
        string texture_territory = m_tileSet->getImageFile();
        surface_territory->loadTexture(texture_territory);
        
        // initialise la liste des sprites : initHexas
        surface_territory->initHexas(4);
        
        // pour chaque cellule de la grille
        for (int x=0;x<height;x++)
        {
            for (int y=0;y<width;y++)
            {
                int i=x*width+y;
                // - la positionne dans la fenêtre
                surface_territory->setSpriteLocation(i,x,y);
                // - prend la partie de texture correspondante
                Element* elt = m_tab.getElement(x,y);
                if (elt==NULL)
                {
                    throw std::runtime_error("Element nul");
                }
                else
                {
                    surface_territory->setSpriteTexture(i,m_tileSet->getTile(*(elt)));
                }
            }
        }
        
        m_surface = std::unique_ptr<Surface> (surface_territory);
    }
};