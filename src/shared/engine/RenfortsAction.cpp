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
    
    void RenfortsAction::undo (state::State& state){}
};
