/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "state.h"
#include "GestionRenforts.h"

using namespace std;
using namespace state;

namespace engine{
    GestionRenforts::GestionRenforts(int i)
    {
        m_renforts = i;
        m_commandTypeId = RENFORTS;
    }
    
    CommandTypeId GestionRenforts::getTypeId () const
    {
        return m_commandTypeId;
    }
    
    void GestionRenforts::execute (state::State& state)
    {    
        int renfortTile = 0;
        
        for (int i=0; i<(int)(state.getTeamBoard().getHeight()); i++)
        {
            for (int j=0; j<(int)(state.getTeamBoard().getWidth()); j++)
            {
                int currentNbCr =
                        ((Team*)state.getTeamBoard().getElement(i,j))->getNbCreatures();
                if (((((Team*)state.getTeamBoard().getElement(i,j))->getTeamStatus()) ==
                        state.getPlayer()) && (renfortTile<m_renforts) && (currentNbCr!=0))
                {
                    ((Team*)state.getTeamBoard().getElement(i,j))->setNbCreatures(1+currentNbCr);
                }
            }
        }
    }
    
    int GestionRenforts::getRenforts ()
    {
        return m_renforts;
    }
    
    void GestionRenforts::setRenforts (int renforts)
    {
        m_renforts = renforts;
    }
    
};