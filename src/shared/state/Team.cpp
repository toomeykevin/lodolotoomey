/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Team.h"
#include "State.h"

using namespace std;

namespace state {
    Team::Team(int nbCreatures, TeamStatus teamStatus)
    {
        m_nbCreatures=nbCreatures;
        m_teamStatus=teamStatus;
    }
    
    int Team::getNbCreatures(){
        return m_nbCreatures;
    }
    
    void Team::setNbCreatures (int nbCreatures)
    {
        if (nbCreatures <1 || nbCreatures >8)
        {
            //cout << "nbCreatures invalide" << endl;
        }
        else
        {
            m_nbCreatures=nbCreatures;
        }
    }
    
    TeamStatus Team::getTeamStatus()
    {
        return m_teamStatus;
    }
    
    void Team::setTeamStatus(TeamStatus teamStatus)
    {
        if (teamStatus != DRAGONS && teamStatus != UNICORNS)
        {
            cout << "TeamStatus invalide" << endl;
        }
        else
        {
            m_teamStatus = teamStatus;
        }
    }
    
    bool Team::isStatic()
    {
        return false;
    }
   
};