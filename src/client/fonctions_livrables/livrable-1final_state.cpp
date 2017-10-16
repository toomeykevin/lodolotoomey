/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "state.h"
#include <iostream>
using namespace std;
using namespace state;

void livrable_1final_state(string commande){
    if (commande=="state"){
            bool test= false;
            cout <<"Debut des tests"<< endl;
            Team team1; //new Team(TeamStatus::UNICORNS);
            Team team2;
            team2.setNbCreatures(5);
            Territory* territoryI= new Territory(IMPOSSIBLE);
            Territory territoryA;
            //cout<<territoryI->getTerritoryStatus()<<endl;
            
            //Class Team Test
            if(team1.getNbCreatures()==1){
                test=true;
                cout<<"Team::getNbCreatures() works"<<endl;
            }
            else {
                test= false;
                cout<<"Team::getCreatures() failed"<<endl;
                
            }
            if(team2.getNbCreatures()==5){
                test=true; 
                cout<<"Team::setNbCreatures(int) works"<<endl;
            }
            else {
                test= false;
                cout<<"Team::setNbCreatures(int) failed"<<endl;
                
            }
            // Class Territory Test
            if(territoryI->getTerritoryStatus()==2){
                test=true; 
                cout<<"Team::Team(teamStatus) works"<<endl;
            }
            else {
                test= false; 
                cout<<"Team::Team(TeamStatus) failed"<<endl;
            }
            if(territoryA.getTerritoryStatus()==1){
                test=true;
                cout<<"Team::getTeamStatus() works"<<endl;
            }
            else {
                test= false;  
                cout<<"Team::getTeamStatus() failed"<<endl;
            }
           cout<<test<<endl;
           if (test==true){
               cout<<"Test worked"<<endl;
           }
           else {
               cout<<"Test failed"<<endl;
               
           }
           // team->getNbCreatures();            
                   
                    
            cout <<"Fin des tests"<<endl;
    }
    else{
        cout<< "la commande n'est pas state"<< endl; 
    }
}

