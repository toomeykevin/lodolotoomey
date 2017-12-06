/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "RenfortsAction.h"


using namespace std;
using namespace state;

namespace engine{
    RenfortsAction::RenfortsAction(TeamStatus AttPlayerStatus){
        m_playerStatus=AttPlayerStatus;
    }
    
    void RenfortsAction::apply (state::State& state)  { }
    
    void RenfortsAction::undo (state::State& state)
    {
        for (int i=0; i<(int)(state.getTeamBoard().getHeight()); i++)
        {
            for (int j=0; j<(int)(state.getTeamBoard().getWidth()); j++)
            {
                int currentNbCr =
                    ((Team*)state.getTeamBoard().getElement(i,j))->getNbCreatures();
                if (((((Team*)state.getTeamBoard().getElement(i,j))->getTeamStatus()) ==
                        state.getPlayer()) && (currentNbCr != 1) && (currentNbCr != 0))
                {
                    ((Team*)state.getTeamBoard().getElement(i,j))->setNbCreatures(currentNbCr - 1);
                }
            }
        }
    }
};
