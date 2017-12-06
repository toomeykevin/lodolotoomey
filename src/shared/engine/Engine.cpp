/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Engine.h"
#include "GestionRenforts.h"
#include "AttackCommand.h"
#include "InitBasicState.h"
#include "state/Team.h"
#include "engine.h"

using namespace std;
using namespace state;

namespace engine{
    Engine::Engine (){}
    
    Engine::~Engine (){}
    
    state::State& Engine::getState ()
    {
        return m_currentState;
    }
    
    void Engine::addPassivCommands ()
    {
        //GestionRenforts* passivGestionRenforts= new GestionRenforts(i); //i a determiner
        //Command* cmd=((Command*)passivGestionRenforts);
        //m_currentCommands.push_back(std::unique_ptr<Command>(cmd));
    }
    
    void Engine::addCommand (Command* cmd)
    {
        m_currentCommands.push_back(std::unique_ptr<Command>(cmd));
    }
    
    std::stack<std::shared_ptr<Action>> Engine::update ()
    {
        std::stack<shared_ptr<Action>> actions;
        if (m_currentCommands.size()!=0){
            
            for (int i=0; i<((int)(m_currentCommands.size())); i++)
            {
                if ((m_currentCommands[i]).get()->getTypeId() == RENFORTS)
                {
                    ((GestionRenforts*)(m_currentCommands[i]).get())->execute(m_currentState,actions);
                }
                else if ((m_currentCommands[i]).get()->getTypeId() == ATTACK)
                {
                    
                    ((AttackCommand*)(m_currentCommands[i]).get())->execute(m_currentState,actions);
                }
                else
                {
                    ((InitBasicState*)(m_currentCommands[i]).get())->execute(m_currentState,actions);
                }
                m_currentCommands.clear();
            }
        }
        else{
            throw runtime_error(" la list de commandes est vide");
            shared_ptr<Action> p(NULL);
            actions.push(p);
        }
        return actions;
    }
    void Engine::undo(std::stack<shared_ptr<Action>>& actions){
        
        for (int i=0;i< (int)actions.size();i++){
            shared_ptr<Action> l=actions.top();
            l.get()->undo(m_currentState);      
        }
    }
};