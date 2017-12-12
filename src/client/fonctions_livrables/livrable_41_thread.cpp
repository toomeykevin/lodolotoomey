/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <mutex>
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

// déclaration d'un mutex global
mutex mx;

// routine du thread secondaire
void engine_thread(HeuristicAI* AIPlayer, Engine& moteur)
{
    // on attend 10s avant d'exécuter l'AI :
    // ça laisse le temps à la fenêtre d'affichage de s'ouvrir
    sleep(milliseconds(10000));
    
    // tant que le jeu n'est pas fini
    while(!moteur.getState().isGameOver())
    {
        // on verrouille le mutex pour qu'il n'y ait pas d'affichage pendant que
        // l'AI modifie l'état
        {
            std::lock_guard<std::mutex> lck (mx);
            AIPlayer->run(moteur);
        }
        // on attend 3s avant de passer au tour suivant : permet un affichage clair
        sleep(milliseconds(3000));
    }
}

void livrable_41_thread(string commande)
{
    if (commande == "thread")
    {
        cout<<"La commande est thread"<<endl<<endl;
        
        HeuristicAI* AIPlayer = new HeuristicAI();
        Engine moteur;
        State& etat = moteur.getState();
        
        // initialisation de l'état
        InitBasicState* initState = new InitBasicState();
        moteur.addCommand((Command*)initState);
        moteur.update();
        
        // création du thread qui fait le calcul du tour
        thread th(&engine_thread, AIPlayer, std::ref(moteur));
        
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
            
            // on verrouille le mutex pour que le thread ne cherche pas à
            // modifier l'état, puisqu'on va l'afficher
            std::lock_guard<std::mutex> lck (mx);
            
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
                sleep(milliseconds(3000));
                window.close(); 
            }
        }
        th.join();
    }
    else
    {}
}
