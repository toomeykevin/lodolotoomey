/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Command.h"

using namespace std;

namespace engine{
    Command::~Command (){}
    
    CommandTypeId Command::getTypeId () const
    {
        return m_commandTypeId;
    }
    
    void Command::execute (state::State& state, std::stack<shared_ptr<Action>>& actions){}
    
    void Command::serialize (Json::Value& out){}
    
    Command* Command::deserialize (Json::Value& in)
    {
        Command* commande;
        return commande;
    }
};
