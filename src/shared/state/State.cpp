/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "State.h"
#include "Team.h"

using namespace std;

namespace state{
  
  ElementTab& State::getTerritoryBoard ()
  {
      return m_territoryBoard;
  }
  
  ElementTab& State::getTeamBoard ()
  {
      return m_teamBoard;
  }
  
  TeamStatus State::getPlayer()
  {
      return m_player;
  }
  
  void State::setPlayer(TeamStatus player)
  {
      m_player=player;
  }
  
   bool State::isGameOver()
    {
        bool boolean= false;
        int nbDragons=0;
        int nbUnicorns=0;
        TeamStatus teamStatus;
        int width= ((int)m_teamBoard.getWidth());
        int height= ((int)m_teamBoard.getHeight());
        for (int i=0; i<height; i++)
        {
            for (int j=0; j<width;j++)
            {
                teamStatus=((Team*)m_teamBoard.getElement(i,j))->getTeamStatus();
                if (teamStatus==DRAGONS)
                {
                    nbDragons+=1;
                }
                else if (teamStatus==UNICORNS)
                {
                    nbUnicorns+=1;
                }
            }
        }
        if (nbUnicorns==0 || nbDragons==0){
            boolean=true;
        }
        
        return boolean;
    }
};