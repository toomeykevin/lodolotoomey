/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Action.h"

using namespace std;
using namespace engine;

namespace engine{
    Action::~Action (){}
    
    void Action::apply (state::State& state)  { }
    
    void Action::undo (state::State& state){}
    
    ActionTypeId Action::getTypeId() const {
        return m_actionTypeId;
    }
};
