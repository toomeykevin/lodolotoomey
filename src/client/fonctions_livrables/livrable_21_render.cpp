/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "render/TerritoryTileSet.h"
#include "render/TeamTileSet.h"
#include "render/NumberTileSet.h"

using namespace sf;
using namespace render;

void livrable_21_render(std::string commande){
    if (commande=="render"){
        std::cout<<"la commande est render"<<std::endl;
        
        TerritoryTileSet territoires;
        TeamTileSet teams;
        NumberTileSet numbers;
        
        RenderWindow window(VideoMode(800,600,32),"Risk Fantasy | Unicorns VS Dragons", Style::Close | Style::Titlebar);
        
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
                
                // fermeture de la fenêtre quand on clique n'importe où sur la fenêtre
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    window.close();
                }
            }
            
            // à chaque tour, on efface l'ancien rendu
            window.clear(Color::Black);
            
            // Texture des territoires
            Texture territoryTextures;
            if (!territoryTextures.loadFromFile(territoires.getImageFile()))
            {
                // si ça ne marche pas, on fait une exception
                throw std::runtime_error("Impossible de lire le fichier");
            }
            
            // Texture des soldats
            Texture creatureTextures;
            if (!creatureTextures.loadFromFile(teams.getImageFile()))
            {
                // si ça ne marche pas, on fait une exception
                throw std::runtime_error("Impossible de lire le fichier");
            }
            
            // Texture des bulles
            Texture bubbleTextures;
            if (!bubbleTextures.loadFromFile(numbers.getImageFile()))
            {
                // si ça ne marche pas, on fait une exception
                throw std::runtime_error("Impossible de lire le fichier");
            }
            
            /* Création de la surface pour les territoires
             * utilisation de initSurface :
             * charge la texture adéquate
             * récupère le nb de cellules de la grille avec initHexas
             * utilise setSpriteLocation qui va positionner chaque
             * sprite (ici en fonction des coordonnées i,j dans la liste des
             * sprites, on pourra les placer dans la fenêtre)
             * utilise setSpriteTexture qui va permettre d'obtenir la
             * bonne texture pour chaque sprite. En l'occurrence on va
             * utiliser getTile(un élément du state = un sprite de la map)
             * pour récupérer la Tile, et à partir des coordonnées (x,y) du
             * coin en haut à gauche et de la taille (ici 120x140) va
             * récupérer dans la texture le bon élément.
             * 
             
             
             */
            
            
            /* Création de la surface pour les personnages
             
             
             
             */
            
            
            /* Création de la surface pour les bulles des nombres
             
             
             
             */
            
            
            
            // Vertex tile dragon
            // création du VertexArray en quad
            VertexArray hexagonDragon(Quads,4);
            // définition des coordonnées des 4 points du quads
            // ie position de l'hexagone dans la fenêtre
            hexagonDragon[0].position = Vector2f(0,0);
            hexagonDragon[1].position = Vector2f(120,0);
            hexagonDragon[2].position = Vector2f(120,140);
            hexagonDragon[3].position = Vector2f(0,140);
            // définition de la partie de la texture correspondant
            // au territoire des dragons
            hexagonDragon[0].texCoords = Vector2f(240,0);
            hexagonDragon[1].texCoords = Vector2f(360,0);
            hexagonDragon[2].texCoords = Vector2f(360,140);
            hexagonDragon[3].texCoords = Vector2f(240,140);
            
            // Vertex tile unicorn
            // création du VertexArray
            VertexArray hexagonUnicorn(Quads,4);
            // définition des quatres points du quad
            hexagonUnicorn[0].position = Vector2f(120,0);
            hexagonUnicorn[1].position = Vector2f(240,0);
            hexagonUnicorn[2].position = Vector2f(240,140);
            hexagonUnicorn[3].position = Vector2f(120,140);
            // définition de la partie de la texture correspondant
            // au territoire des licornes
            hexagonUnicorn[0].texCoords = Vector2f(0,0);
            hexagonUnicorn[1].texCoords = Vector2f(120,0);
            hexagonUnicorn[2].texCoords = Vector2f(120,140);
            hexagonUnicorn[3].texCoords = Vector2f(0,140);
            
            // Vertex tile inacessible
            // création du VertexArray
            VertexArray hexagonInaccessible(Quads,4);
            // définition des 4 points du quad
            hexagonInaccessible[0].position = Vector2f(60,105);
            hexagonInaccessible[1].position = Vector2f(180,105);
            hexagonInaccessible[2].position = Vector2f(180,245);
            hexagonInaccessible[3].position = Vector2f(60,245);
            // définition de la partie de la texture correspondant
            // à un territoire innaccesible
            hexagonInaccessible[0].texCoords = Vector2f(120,0);
            hexagonInaccessible[1].texCoords = Vector2f(240,0);
            hexagonInaccessible[2].texCoords = Vector2f(240,140);
            hexagonInaccessible[3].texCoords = Vector2f(120,140);
            
            // Placement du dragon dans son territoire
            VertexArray dragon(Quads,4);
            dragon[0].position = Vector2f(35,45);
            dragon[1].position = Vector2f(85,45);
            dragon[2].position = Vector2f(85,95);
            dragon[3].position = Vector2f(35,95);
            dragon[0].texCoords = Vector2f(50,0);
            dragon[1].texCoords = Vector2f(100,0);
            dragon[2].texCoords = Vector2f(100,50);
            dragon[3].texCoords = Vector2f(50,50);
            
            // Placement de la licorne dans son territoire
            VertexArray unicorn(Quads,4);
            unicorn[0].position = Vector2f(155,45);
            unicorn[1].position = Vector2f(205,45);
            unicorn[2].position = Vector2f(205,95);
            unicorn[3].position = Vector2f(155,95);
            unicorn[0].texCoords = Vector2f(0,0);
            unicorn[1].texCoords = Vector2f(50,0);
            unicorn[2].texCoords = Vector2f(50,50);
            unicorn[3].texCoords = Vector2f(0,50);
            
            // Placement de la force du dragon
            VertexArray dragonForce(Quads,4);
            dragonForce[0].position = Vector2f(73,45);
            dragonForce[1].position = Vector2f(85,45);
            dragonForce[2].position = Vector2f(85,57);
            dragonForce[3].position = Vector2f(73,57);
            dragonForce[0].texCoords = Vector2f(36,0);
            dragonForce[1].texCoords = Vector2f(48,0);
            dragonForce[2].texCoords = Vector2f(48,12);
            dragonForce[3].texCoords = Vector2f(36,12);
            
            // Force de la licorne
            VertexArray unicornForce(Quads,4);
            unicornForce[0].position = Vector2f(193,45);
            unicornForce[1].position = Vector2f(205,45);
            unicornForce[2].position = Vector2f(205,57);
            unicornForce[3].position = Vector2f(193,57);
            unicornForce[0].texCoords = Vector2f(84,0);
            unicornForce[1].texCoords = Vector2f(96,0);
            unicornForce[2].texCoords = Vector2f(96,12);
            unicornForce[3].texCoords = Vector2f(84,12);
            
            // on définit ici tout ce qu'on dessine
            window.draw(hexagonDragon,&territoryTextures);
            window.draw(hexagonUnicorn,&territoryTextures);
            window.draw(hexagonInaccessible,&territoryTextures);
            window.draw(dragon,&creatureTextures);
            window.draw(unicorn,&creatureTextures);
            window.draw(dragonForce,&bubbleTextures);
            window.draw(unicornForce,&bubbleTextures);
            
            // et on affiche le nouveau rendu
            window.display();
        }
        
    }
    else{
        //cout<< "la commande n'est pas render"<< endl; 
    }
}