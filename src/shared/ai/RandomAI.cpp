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
        while(l!=0){
            listCommands(list,engine.getState());
            l=list.size();
            std::uniform_int_distribution<int> uni(0,l-1); // guaranteed unbiased
            auto random_integer = uni(randgen);
            cout<<" random integer : "<<random_integer<<","<<endl;
            if (l>0){
                cout<<"iatt"<<((AttackCommand*)list[random_integer].get())->getIAtt()<<endl;
                cout<<"jatt"<<((AttackCommand*)list[random_integer].get())->getJAtt()<<endl;
                cout<<"idef"<<((AttackCommand*)list[random_integer].get())->getIDef()<<endl;
                cout<<"jdef"<<((AttackCommand*)list[random_integer].get())->getJDef()<<endl;
                engine.addCommand(list[random_integer].get());
                cout<<"je suis la "<<endl;
                engine.update();
                cout<<"je suis la "<<list.size()<<endl;
                list.clear();
                cout<<"je suis la !!!!"<<endl;
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