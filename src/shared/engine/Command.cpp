/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Command.h"
#include <iostream>
using namespace std;

namespace engine{
    Command::~Command (){}
    CommandTypeId Command::getTypeId () const {
        return ATTACK;
    }
    void Command::execute (state::State& state){}
};