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
        int n = 4;
        
        TerritoryTileSet territories;
        
        // m_state : deux ElementTab : la liste des teams et les territories
        ElementTab& TerritoryBoard = m_tab;
        int width = TerritoryBoard.getWidth();
        int height = TerritoryBoard.getHeight();
        
        // crée une nouvelle surface
        Surface surface_territory;
        
        // charge la texture : loadTexture
        string texture_territory = territories.getImageFile();
        surface_territory.loadTexture(texture_territory);
        
        // initialise la liste des sprites : initHexas
        surface_territory.initHexas(n);
        
        // pour chaque cellule de la grille
        for (int x=0;x<height;x++)
        {
            for (int y=0;y<width;y++)
            {
                int i=x*width+y;
                // - la positionne dans la fenêtre
                surface_territory.setSpriteLocation(i,x,y);
                // - prend la partie de texture correspondante
                surface_territory.setSpriteTexture(i,territories.getTile(*(TerritoryBoard.getElement(x,y))));
            }
        }  
    }
};