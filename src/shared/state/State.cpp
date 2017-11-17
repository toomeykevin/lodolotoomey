/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "State.h"

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
};