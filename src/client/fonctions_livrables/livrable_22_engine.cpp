/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "render.h"
#include "state.h"
#include "engine.h"

using namespace sf;
using namespace render;
using namespace state;
using namespace engine;
using namespace std;

void livrable_22_engine(string commande){
    if (commande=="engine"){
        cout<<"la commande est engine"<<endl;
        
        
        //Commandes Tests
        
        Engine moteur;
        State& etat=moteur.getState();
        int iAtt=((int)etat.getTeamBoard().getHeight())/2;
        int jAtt=((int)etat.getTeamBoard().getWidth())/2;
        cout<<"coord att : "<<iAtt<<" "<<jAtt<<endl;
        
        //InitBasicState* initState;
        //moteur.addCommand((Command*)initState);
        //moteur.update();

        //AttackCommand* cmdAtt=new AttackCommand(2,2,2,3); // 2,2 vs 2,3
        //moteur.addCommand((Command*)cmdAtt);
        //moteur.update();
        int newnb22=((Team*)etat.getTeamBoard().getElement(2,2))->getNbCreatures();
        cout<<"nb22 new : "<< newnb22<<endl;
        
        
        
    }
    else{
        
    }
}