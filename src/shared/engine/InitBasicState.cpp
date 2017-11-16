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
using namespace engine;

namespace engine{
    
    InitBasicState::InitBasicState()
    {
        m_commandTypeId = INIT;
    }
    
    CommandTypeId InitBasicState::getTypeId () const
    {
        return m_commandTypeId;
    }
    
    void InitBasicState::execute (state::State& state)
    {
        int etat_Width = state.getTeamBoard().getWidth();
        int etat_Height = state.getTeamBoard().getHeight();
        int NbrCr = 4;
        
        for (int i=0; i<etat_Height; i++)
        {
            for (int j=0; j<etat_Width; j++)
            {
                TeamStatus teamStatus;
                TerritoryStatus territoryStatus;
                
                // le contour de la map est constitué de tiles inacessibles
                if ((i==0) || (i==etat_Height-1) || (j==0) || (j==etat_Width-1))
                {
                    territoryStatus = IMPOSSIBLE;
                    teamStatus = NONE;
                    NbrCr = 0;
                }
                // la moitié gauche de la map est constituée de tiles dragons
                else if(i<((int)etat_Height)/2)
                {
                    teamStatus = DRAGONS;
                    territoryStatus = DRAGONS_T;
                    NbrCr = 4;
                }
                // la moitié droite de la map est constituée de tiles licornes
                else
                {
                    teamStatus = UNICORNS;
                    territoryStatus = UNICORNS_T;
                    NbrCr = 4;
                }
                
                Team* team = new Team(NbrCr,teamStatus);
                Territory* territory = new Territory(territoryStatus);
                state.getTeamBoard().setElement(i,j,team);
                state.getTerritoryBoard().setElement(i,j,territory);
                team->setx(i);
                team->sety(j);
                territory->setx(i);
                territory->sety(j);
            }
        }
    
    }
};
