/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Surface.h"
#include "Tile.h"
#include <iostream>

using namespace std;
using namespace sf;


namespace render{
    sf::VertexArray Surface::getHexas()
    {
        return m_hexas;
    }
    
    /*sf::Texture Surface::getTexture()
    {
        return m_textures;
    }
    
    void Surface::setTexture(Texture texture)
    {
        m_textures = texture;
    }*/
    
    void Surface::loadTexture (const std::string& imageFile)
    {
        if (!m_texture.loadFromFile(imageFile))
            {
                // si ça ne marche pas, on fait une exception
                throw std::runtime_error("Impossible de charger la texture");
            }
    }
    
    void Surface::initHexas (int count)
    {
        m_hexas.setPrimitiveType(Quads);
        m_hexas.resize(count*4);
    }
    
    void Surface::setSpriteLocation (int i, int x, int y)
    {
        sf::Vertex* quad = &m_hexas[i*4];
        // si ligne paire
        if (y%2==0)
        {
            quad[0].position = Vector2f(105*x,120*y);
            quad[1].position = Vector2f(105*(x+1),120*y);
            quad[2].position = Vector2f(105*(x+1),120*y+140);
            quad[3].position = Vector2f(105*x,120*y+140);
        }
        // si ligne impaire, il faut tout décaler de 60 pixels
        if (y%2!=0)
        {
            quad[0].position = Vector2f(60+105*x,120*y);
            quad[1].position = Vector2f(60+105*(x+1),120*y);
            quad[2].position = Vector2f(60+105*(x+1),120*y+140);
            quad[3].position = Vector2f(60+105*x,120*y+140);
        }
    }
    
    void Surface::setSpriteTexture (int i, Tile& tex)
    {
        sf::Vertex* quad = &m_hexas[i*4];
        
        int x = tex.getx();
        int y = tex.gety();
        int h = tex.getHeight();
        int w = tex.getWidth();
        
        quad[0].texCoords = Vector2f(x, y);
        quad[1].texCoords = Vector2f(x+w, y);
        quad[2].texCoords = Vector2f(x+w, y+h);
        quad[3].texCoords = Vector2f(x, y+h);
    }
    
    void Surface::draw (sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = &m_texture;
        target.draw(m_hexas, states);
    }
};