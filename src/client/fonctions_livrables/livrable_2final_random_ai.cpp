/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include<state.h>
#include<render.h>
#include<engine.h>
#include<ai.h>
using namespace std;
using namespace state;
using namespace engine;
using namespace render;
using namespace ai;


void livrable_2final_random_ai(string commande){
    if (commande=="random_ai"){
        cout<<"La commande est random_ai. "<<endl;

        RandomAI* AIPlayer= new RandomAI();
        Engine moteur;
        State& etat=moteur.getState();
                
        int sizeVector=etat.getTeamBoard().getSizeVector();
        cout<<"taille du tableau de tuiles : "<<sizeVector<<endl;
        cout<<"taille du tableau height x width : "<<etat.getTeamBoard().getHeight()<<" x "<<etat.getTeamBoard().getWidth()<< endl;
        
        //initialisation de l'état
        InitBasicState* initState=new InitBasicState();
        moteur.addCommand((Command*)initState);
        moteur.update();
        cout<<((Territory*)moteur.getState().getTerritoryBoard().getElement(1,1))->getTerritoryStatus()<<endl<<endl;
        cout<<"Appuyer la touche ENTER"<<endl;
        getchar(); // attente de l'appui de la touche ENTER
        AIPlayer->run(moteur);
        
        
    }
    else{
        //cout<< "la commande n'est pas random_ai"<< endl; 
    }
}
