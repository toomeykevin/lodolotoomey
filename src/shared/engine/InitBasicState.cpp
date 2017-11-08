/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "InitBasicState.h"
#include "state.h"
#include <iostream>
using namespace std;
using namespace state;

namespace engine{
    
    InitBasicState::InitBasicState(){
        
    }
    CommandTypeId InitBasicState::getTypeId () const {
        return INIT;
    }
    void InitBasicState::execute (state::State& state){
        int etat_Width=state.getTeamBoard().getWidth();
        int etat_Height=state.getTeamBoard().getHeight();
        cout<<"taille du tableau "<<state.getTeamBoard().getWidth()<<" x "<<state.getTeamBoard().getHeight()<< endl;
        for (int i=0;i<etat_Height;i++){
            for (int j=0;j<etat_Width;j++){
                TeamStatus teamStatus;
                TerritoryStatus territoryStatus;

                if ((i==0) ||(i==etat_Width-1)||(j==0) ||(j==etat_Height-1)){
                    territoryStatus=IMPOSSIBLE;
                    teamStatus=DRAGONS;
                }
                else if(j<((int)etat_Height)/2){
                    teamStatus=DRAGONS;
                    territoryStatus=DRAGONS_T;
                }
                else{
                    teamStatus=UNICORNS;
                    territoryStatus=UNICORNS_T;
                }
                Team* team=new Team(4,teamStatus);
                Territory* territory=new Territory(territoryStatus);
                state.getTeamBoard().setElement(i,j,team);
                state.getTerritoryBoard().setElement(i,j,territory);
            }
        }
    
    }
};
