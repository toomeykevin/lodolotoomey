/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <chrono>
#include "state.h"
#include "engine.h"
#include "RandomAI.h"

using namespace std;
using namespace engine;
using namespace state;
using namespace ai;

namespace ai{
    void RandomAI::run (engine::Engine& engine)
    {
        int l=1;

        vector<unique_ptr<Command>> list;
        
        cout<<"Team : 1=dragons 2=licornes"<<endl;
        cout<< "C'est le tour de l'équipe "<<engine.getState().getPlayer()<<endl;
        
        while(l!=0)
        {
            listCommands(list,engine.getState());
            l=list.size(); // size of the Commands list
                        
            if (l>0)// while there are still commands that can be executed
            {
                std::uniform_int_distribution<int> uni(0,l-1); // guaranteed unbiased
                auto random_integer = uni(randgen);
                cout<<"Entier aléatoire : "<<random_integer<<endl;
                
                cout<<" Attaque de ("<<((AttackCommand*)list[random_integer].get())->getIAtt();
                cout<<","<<((AttackCommand*)list[random_integer].get())->getJAtt()<<") ";
                cout<<"sur ("<<((AttackCommand*)list[random_integer].get())->getIDef();
                cout<<","<<((AttackCommand*)list[random_integer].get())->getJDef()<<")"<<endl;
                engine.addCommand(list[random_integer].release());
                
                engine.update();
                list.clear();
            }
            else{}  
        }
        
        cout<<endl;
        GestionRenforts* gestionRenfort = new GestionRenforts(1);
        engine.addCommand((Command*)gestionRenfort);
        engine.update();
        
        if (engine.getState().getPlayer()==DRAGONS)
        {
             engine.getState().setPlayer(UNICORNS);
        }
        else
        {
             engine.getState().setPlayer(DRAGONS);
        }    
    }
    
    RandomAI::RandomAI ()
    {
        std::random_device rd;     // only used once to initialise (seed) engine
        std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
        randgen=rng;
    }
};