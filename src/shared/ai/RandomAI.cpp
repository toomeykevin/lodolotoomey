/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "RandomAI.h"
#include "engine.h"
#include "state.h"
#include <chrono>
#include <iostream>

using namespace std;
using namespace ai;
using namespace engine;
using namespace state;

namespace ai{
    
    void RandomAI::run (engine::Engine& engine){
        int l=1;

        vector<unique_ptr<Command>> list;
        cout<< "C'est le tour de l'équipe "<<engine.getState().getPlayer()<<endl;
        while(l!=0){
    
            listCommands(list,engine.getState());
            l=list.size();
                        
            if (l>0){
                std::uniform_int_distribution<int> uni(0,l-1); // guaranteed unbiased
                auto random_integer = uni(randgen);
                cout<<" random integer : "<<random_integer<<","<<endl;
                
                cout<<" Attaque de (iatt="<<((AttackCommand*)list[random_integer].get())->getIAtt();
                cout<<",jatt="<<((AttackCommand*)list[random_integer].get())->getJAtt()<<") ";
                cout<<"sur (idef="<<((AttackCommand*)list[random_integer].get())->getIDef();
                cout<<",jdef="<<((AttackCommand*)list[random_integer].get())->getJDef()<<")"<<endl;
                engine.addCommand(list[random_integer].release());
                
                engine.update();
                list.clear();
            }
            else{
                
            }  
        }
        cout<<endl;
        GestionRenforts* gestionRenfort= new GestionRenforts(1);
        engine.addCommand((Command*)gestionRenfort);
        engine.update();
        if (engine.getState().getPlayer()==DRAGONS){
             engine.getState().setPlayer(UNICORNS);
        }
        else{
             engine.getState().setPlayer(DRAGONS);
        }
       
        
    }
    RandomAI::RandomAI (){
        std::random_device rd;     // only used once to initialise (seed) engine
        std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
        
        randgen=rng;
        
    }

  
};