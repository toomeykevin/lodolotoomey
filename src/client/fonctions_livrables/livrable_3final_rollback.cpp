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
        std::stack<shared_ptr<Action>> actionsTemp;
        vector<shared_ptr<Action>> vectorActionsTemp;
                
        if(moteur.getState().getPlayer()==DRAGONS)
        {
            cout<<"It is now the DRAGONS' turn !"<<endl;
        }
        else
        {
            cout<< "It is now the UNICORNS' turn !"<<endl;
        }
        cout<<"Appuyez sur la touche Entrée pour continuer"<<endl;
        cout<<"Appuyez sur la touche Retour pour revenir en arrière"<<endl<<endl;
        
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
        
        
        int k=0;
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
   
            if(Keyboard::isKeyPressed(Keyboard::Return))
            {
                cout<<"Fermez la fenêtre pour quitter"<<endl;
                cout<<"Appuyez sur la touche Entrée pour continuer"<<endl;
                cout<<"Appuyez sur la touche Retour pour revenir en arriere"<<endl;
                 
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
                    //commadnes tests rollback
                    AttackCommand* attCommand1 = new AttackCommand(2,1,3,0);  // att DRAGONS
                    AttackCommand* attCommand2 = new AttackCommand(4,3,3,2); //att UNICRONS
                    GestionRenforts* renfCommand1 = new GestionRenforts(1);
                    GestionRenforts* renfCommand2 = new GestionRenforts(1);
                    vector<Command*> vectTest;
                    vectTest.push_back((Command*)attCommand1);
                    vectTest.push_back((Command*)renfCommand1);
                    vectTest.push_back((Command*)attCommand2);
                    vectTest.push_back((Command*)renfCommand2);
                    
                    vectTest.clear();
                    if (k<3){
                        moteur.addCommand(vectTest[k]);
                        moteur.addCommand(vectTest[k+1]);
                        k+=2;
                        TeamStatus playerStatus = moteur.getState().getPlayer();
                        string strPlayer;
                        if(playerStatus==2){
                            strPlayer="DRAGONS";
                        }
                        else if (playerStatus==1){
                            strPlayer="UNICORNS";
                        }
                        cout<<"Apply attack de "<< strPlayer <<endl<<endl;
                    }
                    
                    
                    actionsTemp = moteur.update();
                    int lActions=(int)actionsTemp.size();
                    for (int i=0;i<lActions;i++){
                        vectorActionsTemp.push_back(actionsTemp.top());
                        actionsTemp.pop();
                    }
                    for (int j=0;j<(int)vectorActionsTemp.size();j++){
                        int n=(int)vectorActionsTemp.size();
                        actions.push(vectorActionsTemp[n-j-1]);
                    }
                    vectorActionsTemp.clear();
                }
                sleep(milliseconds(1000));
                //cangement de tour
                if (moteur.getState().getPlayer()==DRAGONS)
                {
                     moteur.getState().setPlayer(UNICORNS);
                }
                else
                {
                     moteur.getState().setPlayer(DRAGONS);
                }
            }
            else if(Keyboard::isKeyPressed(Keyboard::BackSpace)){
                cout<<"Fermez la fenêtre pour quitter"<<endl;
                cout<<"Appuyez sur la touche Entrée pour continuer"<<endl;
                cout<<"Appuyez sur la touche Retour pour revenir en arriere"<<endl;
                moteur.undo(actions);
                sleep(milliseconds(1000));
                if(k>0){
                    k=k-2;
                    //cahngement de tour
                    if (moteur.getState().getPlayer()==DRAGONS)
                    {
                         moteur.getState().setPlayer(UNICORNS);
                    }
                    else
                    {
                         moteur.getState().setPlayer(DRAGONS);
                    }
                    
                    TeamStatus playerStatus = moteur.getState().getPlayer();
                    string strPlayer;
                    if(playerStatus==2){
                        strPlayer="DRAGONS";
                    }
                    else if (playerStatus==1){
                        strPlayer="UNICORNS";
                    }
                    cout<<"Undo attack de "<< strPlayer <<endl<<endl;
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
    else{}
}
