/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "StateLayer.h"
#include <iostream>
#include "Surface.h"
#include "NumberTileSet.h"
#include "Tile.h"
#include "state.h"

using namespace std;
using namespace state;
using namespace sf;

namespace render{
    StateLayer::StateLayer (state::State& state): m_state(state) {}
    
    void StateLayer::initSurface ()
    {
        m_tileSet = std::shared_ptr<TileSet> (new NumberTileSet());
        
        // m_state : deux ElementTab : la liste des teams et les territories
        int width = m_state.getTeamBoard().getWidth();
        int height = m_state.getTeamBoard().getHeight();
        
        // crée une nouvelle surface
        Surface* surface_number = new Surface();
        
        // charge la texture : loadTexture
        string texture_number = m_tileSet->getImageFile();
        surface_number->loadTexture(texture_number);
        
        // initialise la liste des sprites : initHexas
        surface_number->initHexas(4);
        
        // pour chaque cellule de la grille
        for (int x=0;x<height;x++)
        {
            for (int y=0;y<width;y++)
            {
                int i=x*width+y;
                // - la positionne dans la fenêtre
                surface_number->setSpriteLocation(i,x,y);
                //surface_number.setSpriteLocation(i,x,y);
                // - prend la partie de texture correspondante
                Element* elt = m_state.getTeamBoard().getElement(x,y);
                if (elt==NULL)
                {
                    throw std::runtime_error("Element nul");
                }
                else
                {
                    if (elt->isStatic() == false)
                    {
                        Team* t = (Team*) elt;
                        surface_number->setSpriteTexture(i,m_tileSet->getCharTile(t->getNbCreatures()));
                    }
                }
            }
        }
        
        m_surface=std::unique_ptr<Surface> (surface_number);
    }
};
