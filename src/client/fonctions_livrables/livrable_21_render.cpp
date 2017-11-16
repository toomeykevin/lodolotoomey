/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "render.h"
#include "state.h"

using namespace sf;
using namespace render;
using namespace state;
using namespace std;

void livrable_21_render(std::string commande){
    if (commande=="render"){
        std::cout<<"la commande est render"<<std::endl;

        // Création d'un état
        State etat;
        ElementTab& territory = etat.getTerritoryBoard();
        ElementTab& team = etat.getTeamBoard();
        
        // On resize pour avoir une grille 4x4
        territory.resize(2,2);
        team.resize(2,2);
        
        // On construit le TerritoryBoard
        Territory* t00 = new Territory(DRAGONS_T);
        Territory* t01 = new Territory(UNICORNS_T);
        Territory* t10 = new Territory(IMPOSSIBLE);
        Territory* t11 = new Territory(DRAGONS_T);
        
        territory.setElement(0,0,t00);
        territory.setElement(0,1,t01);
        territory.setElement(1,0,t10);
        territory.setElement(1,1,t11);
        
        // On construit le TeamBoard
        Team* e00 = new Team(8,DRAGONS);
        Team* e01 = new Team(3,UNICORNS);
        Team* e10 = new Team(0,NONE);
        Team* e11 = new Team(1,DRAGONS);
        
        team.setElement(0,0,e00);
        team.setElement(0,1,e01);
        team.setElement(1,0,e10);
        team.setElement(1,1,e11);

        // on crée une couche à partir de l'ElementTabLayer qu'on a construit
        ElementTabLayer Layer1(etat.getTerritoryBoard());
        ElementTabLayer Layer2(etat.getTeamBoard());
        StateLayer Layer3(etat);

        // ouverture de la page du jeu
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
            }
            
            // à chaque tour, on efface l'ancien rendu
            window.clear(Color::Black);
            
            // on dessine la surface des territoires
            Layer1.initSurface();
            window.draw(*(Layer1.getSurface()));

            // on dessine la surface des équipes
            Layer2.initSurface();
            window.draw(*(Layer2.getSurface()));
            
            // on dessine la surface des chiffres
            Layer3.initSurface();
            window.draw(*(Layer3.getSurface()));
            
            // et on affiche le nouveau rendu
            window.display();
        }
        
    }
    else{
        //cout<< "la commande n'est pas render"<< endl; 
    }
}