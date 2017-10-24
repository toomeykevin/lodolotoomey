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
            window.clear(Color::White);
            
            Texture dragonTerritory;
            if (!dragonTerritory.loadFromFile("res/tile_dragon.png"))
            {
                // si ça ne marche pas, on fait une exception
                throw std::runtime_error("Impossible de lire le fichier");
            }
            
            VertexArray hexagonDragon(Quads,4);
            hexagonDragon[0].position = Vector2f(10,10);
            hexagonDragon[1].position = Vector2f(130,10);
            hexagonDragon[2].position = Vector2f(130,150);
            hexagonDragon[3].position = Vector2f(10,150);
            
            
            // on définit ici tout ce qu'on dessine
            window.draw(hexagonDragon,&dragonTerritory);
            // et on affiche le nouveau rendu
            window.display();
        }
        
    }
    else{
        //cout<< "la commande n'est pas render"<< endl; 
    }
}