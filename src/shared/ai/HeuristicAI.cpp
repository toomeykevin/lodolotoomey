/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <chrono>
#include "state.h"
#include "engine.h"
#include "HeuristicAI.h"

using namespace std;
using namespace engine;
using namespace state;
using namespace ai;

namespace ai{
    void HeuristicAI::run (engine::Engine& engine)
    {
        int l=1;
        int bestIndice=0;

        vector<unique_ptr<Command>> list;
                
        while(l!=0 && bestIndice!=-1)
        {
            listCommands(list,engine.getState());
            l=list.size();
                       
            if (l>0)
            {
                //std::uniform_int_distribution<int> uni(0,l-1); // guaranteed unbiased
                //auto random_integer = uni(randgen);
                //cout<<"Entier aléatoire : "<<random_integer<<endl;
                
                bestIndice = bestCommand(list,engine.getState()); 
                //cout<<"best index : "<<bestIndice<<endl;
                if (bestIndice>=0){
                    int iAtt=((AttackCommand*)list[bestIndice].get())->getIAtt();
                    int jAtt=((AttackCommand*)list[bestIndice].get())->getJAtt();
                    int iDef=((AttackCommand*)list[bestIndice].get())->getIDef();
                    int jDef=((AttackCommand*)list[bestIndice].get())->getJDef();
                    cout<<" Attack of ("<<iAtt;
                    cout<<","<<jAtt<<") ";
                    cout<<"on ("<<iDef;
                    cout<<","<<jDef<<") and the winner is ";
                    engine.addCommand(list[bestIndice].release());
                    engine.update();
                    list.clear();
                    TeamStatus victorStatus=((Team*)engine.getState().getTeamBoard().getElement(iDef,jDef))->getTeamStatus();
                    if (victorStatus==DRAGONS)
                    {
                        cout<<"DRAGONS !"<<endl;
                    }
                    else
                    {
                        cout<< "UNICORNS !"<<endl;
                    }
                }
                
            }
            else{}  
        }
        
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
        // Afiichage pour le nom de l'équipe qui va jouer enuite.
        if(engine.getState().getPlayer()==DRAGONS)
        {
            cout<<endl<<"It is now the DRAGONS' turn !"<<endl;
        }
        else
        {
            cout<<endl<< "It is now the UNICORNS' turn !"<<endl;
        }
    }
    
    int HeuristicAI::bestCommand(vector<unique_ptr<Command>>& listOrd, State& state)
    {
        int l=listOrd.size();
        vector<int> tab;
        int indiceDuMax=0;
        for (int k=0; k<l; k++)
        {
            if (listOrd[k].get()->getTypeId()==ATTACK)
            {
                int IAtt=((AttackCommand*)listOrd[k].get())->getIAtt();
                int JAtt=((AttackCommand*)listOrd[k].get())->getJAtt();
                int IDef=((AttackCommand*)listOrd[k].get())->getIDef();
                int JDef=((AttackCommand*)listOrd[k].get())->getJDef();
                Team* TeamAtt=((Team*)state.getTeamBoard().getElement(IAtt,JAtt));
                Team* TeamDef=((Team*)state.getTeamBoard().getElement(IDef,JDef));
                int NbCrAtt=TeamAtt->getNbCreatures();
                int NbCrDef=TeamDef->getNbCreatures();
                int Weight=NbCrAtt-NbCrDef;
                tab.push_back(Weight);
             }
        }
        indiceDuMax=0;
        for(int k=0;k<(int)tab.size();k++)
        {
            //cout<<tab[k]<<" ";
            if (tab[k]>tab[indiceDuMax]) 
            {
               indiceDuMax=k; 
            }
        }
        //cout<<endl;
        //cout<<"tab[indice] : "<< tab[indiceDuMax]<<endl;
        if (tab[indiceDuMax]>=0){
            return indiceDuMax;
        }
        else{
            return -1;
        }
    }
    
    HeuristicAI::HeuristicAI ()
    {
        std::random_device rd;     // only used once to initialise (seed) engine
        std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
        randgen=rng;
    }
};