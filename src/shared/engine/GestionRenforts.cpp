/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "GestionRenforts.h"
#include "state.h"
#include <iostream>
using namespace std;
using namespace state;

namespace engine{
    GestionRenforts::GestionRenforts(int i){
        m_renforts=i;
    }
    CommandTypeId GestionRenforts::getTypeId () const {
        return RENFORTS;
    }
    void GestionRenforts::execute (state::State& state){// ajouter le joueurs dans state
        
        int renfortTile=0;
        for (int i=0; i<(int)(state.getTeamBoard().getHeight());i++){
            for (int j=0; j<(int)(state.getTeamBoard().getWidth());j++){
                if (((((Team*)state.getTeamBoard().getElement(i,j))->getTeamStatus())==DRAGONS )&& (renfortTile<m_renforts)){//il faudea mettre le teamstatus du joueur
                    ((Team*)state.getTeamBoard().getElement(i,j))->setNbCreatures(1);
                }
            }
        }
       
    
    } 
    int GestionRenforts::getRenforts (){
        return m_renforts;
    }
    void GestionRenforts::setRenforts (int renforts){
        m_renforts=renforts;
    }
    
};