/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"
#include <iostream>
using namespace std;

namespace engine{
    Engine::Engine (){}
    Engine::~Engine (){}
    state::State& Engine::getState (){
        return m_currentState;
    }
    void Engine::addPassivCommands (){}
    void Engine::addCommand (Command* cmd){
        m_currentCommands.push_back(std::unique_ptr<Command>(cmd));
    }
    void Engine::update (){}
};