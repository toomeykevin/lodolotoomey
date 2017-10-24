/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

void livrable_21_render(std::string commande){
    if (commande=="render"){
        std::cout<<"la commande est render"<<std::endl;
        
        RenderWindow window(VideoMode(800,600,32),"First try", Style::Close | Style::Titlebar);
        
        
        
        // on fait tourner le programme tant que la fenêtre n'est pas fermée
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                // fermeture de la fenêtre lorsque l'utilisateur le souhaite
                if (event.type == Event::Closed)
                {
                    window.close();
                }
            }
            
            // à chaque tour, on efface l'ancien rendu
            window.clear(Color::Black);
            
            // Texture des territoires de dragons
            Texture dragonTerritory;
            if (!dragonTerritory.loadFromFile("res/tile_dragon.png"))
            {
                // si ça ne marche pas, on fait une exception
                throw std::runtime_error("Impossible de lire le fichier");
            }
            
            // Texture des territoires de licornes
            Texture unicornTerritory;
            if (!unicornTerritory.loadFromFile("res/tile_unicorn.png"))
            {
                // si ça ne marche pas, on fait une exception
                throw std::runtime_error("Impossible de lire le fichier");
            }
            
            // Texture des territoires innacessibles
            Texture inaccessibleTerritory;
            if (!inaccessibleTerritory.loadFromFile("res/tile_inaccessible.png"))
            {
                // si ça ne marche pas, on fait une exception
                throw std::runtime_error("Impossible de lire le fichier");
            }
            
            // Vertex tile dragon
            VertexArray hexagonDragon(Quads,4);
            hexagonDragon[0].position = Vector2f(10,10);
            hexagonDragon[1].position = Vector2f(130,10);
            hexagonDragon[2].position = Vector2f(130,150);
            hexagonDragon[3].position = Vector2f(10,150);
            
            hexagonDragon[0].texCoords = Vector2f(0,0);
            hexagonDragon[1].texCoords = Vector2f(120,0);
            hexagonDragon[2].texCoords = Vector2f(120,140);
            hexagonDragon[3].texCoords = Vector2f(0,140);
            
            // Vertex tile unicorn
            VertexArray hexagonUnicorn(Quads,4);
            hexagonUnicorn[0].position = Vector2f(130,10);
            hexagonUnicorn[1].position = Vector2f(250,10);
            hexagonUnicorn[2].position = Vector2f(250,150);
            hexagonUnicorn[3].position = Vector2f(130,150);
            
            hexagonUnicorn[0].texCoords = Vector2f(0,0);
            hexagonUnicorn[1].texCoords = Vector2f(120,0);
            hexagonUnicorn[2].texCoords = Vector2f(120,140);
            hexagonUnicorn[3].texCoords = Vector2f(0,140);
            
            // Vertex tile inacessible
            VertexArray hexagonInaccessible(Quads,4);
            hexagonInaccessible[0].position = Vector2f(70,115);
            hexagonInaccessible[1].position = Vector2f(190,115);
            hexagonInaccessible[2].position = Vector2f(190,255);
            hexagonInaccessible[3].position = Vector2f(70,255);
            
            hexagonInaccessible[0].texCoords = Vector2f(0,0);
            hexagonInaccessible[1].texCoords = Vector2f(120,0);
            hexagonInaccessible[2].texCoords = Vector2f(120,140);
            hexagonInaccessible[3].texCoords = Vector2f(0,140);
            
            // on définit ici tout ce qu'on dessine
            window.draw(hexagonDragon,&dragonTerritory);
            window.draw(hexagonUnicorn,&unicornTerritory);
            window.draw(hexagonInaccessible,&inaccessibleTerritory);
            // et on affiche le nouveau rendu
            window.display();
        }
        
    }
    else{
        //cout<< "la commande n'est pas render"<< endl; 
    }
}