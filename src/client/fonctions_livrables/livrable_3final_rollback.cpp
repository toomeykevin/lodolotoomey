/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <SFML/Graphics.hpp>
#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

using namespace std;
using namespace sf;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;

using namespace std;

void livrable_3final_rollback(string commande)
{
    sleep(milliseconds(1000));
    if (commande == "rollback")
    {
        cout<<"La commande est rollback"<<endl;
                
        Engine moteur;
        State& etat = moteur.getState();
        std::stack<shared_ptr<Action>> actions;
                
        if(moteur.getState().getPlayer()==DRAGONS)
        {
            cout<<"It is now the DRAGONS' turn !"<<endl;
        }
        else
        {
            cout<< "It is now the UNICORNS' turn !"<<endl;
        }
        cout<<"Appuyez sur la touche Entrée pour continuer"<<endl<<endl;
        
        // initialisation de l'état
        InitBasicState* initState = new InitBasicState();
        moteur.addCommand((Command*)initState);
        moteur.update();

        // on crée une couche à partir de l'ElementTabLayer qu'on a construit
        ElementTabLayer Layer1(etat.getTerritoryBoard());
        ElementTabLayer Layer2(etat.getTeamBoard());
        StateLayer Layer3(etat);

        // ouverture de la page du jeu
        RenderWindow window(VideoMode(800,600,32),"Risk Fantasy | Unicorns VS Dragons",
                Style::Close | Style::Titlebar);
        
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
            
            AttackCommand* attCommand1 = new AttackCommand(2,1,3,0);
            moteur.addCommand((Command*)attCommand1);
          
            if(Keyboard::isKeyPressed(Keyboard::Return))
            {
                cout<<"Fermez la fenêtre pour quitter"<<endl;
                cout<<"Appuyez sur la touche Entrée pour continuer"<<endl<<endl;
 
                if (moteur.getState().isGameOver()){
                    string strfinal;
                    if(moteur.getState().getPlayer()==DRAGONS)
                    {
                        strfinal="UNICORNS";
                    }
                    else
                    {
                        strfinal="DRAGONS";
                    }

                    cout<< "GAME OVER : The winner is "<<strfinal<<endl;
                    window.close(); 
                }
                else
                {
                    actions = moteur.update();
                    cout<<"Rollback"<<" "<< actions.size()<<endl;
                }
                sleep(milliseconds(1000));
            }
            else if(Keyboard::isKeyPressed(Keyboard::BackSpace)){
                cout<<"Rollback"<<" "<< actions.size()<<endl;
                moteur.undo(actions);
                sleep(milliseconds(1000));
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
    else{}
}
