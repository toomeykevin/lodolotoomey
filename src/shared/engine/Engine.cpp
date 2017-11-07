/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"
#include "GestionRenforts.h"
#include "AttackCommand.h"
#include <iostream>
using namespace std;

namespace engine{
    Engine::Engine (){}
    Engine::~Engine (){}
    state::State& Engine::getState (){
        return m_currentState;
    }
    void Engine::addPassivCommands (){
        //GestionRenforts* passivGestionRenforts= new GestionRenforts(i); //i a determiner
        //Command* cmd=((Command*)passivGestionRenforts);
        //m_currentCommands.push_back(std::unique_ptr<Command>(cmd));
    }
    void Engine::addCommand (Command* cmd){
        m_currentCommands.push_back(std::unique_ptr<Command>(cmd));
    }
    void Engine::update (){
        for (int i=0; i<(int)(m_currentCommands.size());i++){
            if ((m_currentCommands[i]).get()->getTypeId()==RENFORTS){
                ((GestionRenforts*)(m_currentCommands[i]).get())->execute(m_currentState);
            }
            else{
                ((AttackCommand*)(m_currentCommands[i]).get())->execute(m_currentState);
            }
            m_currentCommands.empty();
        }
    }
};