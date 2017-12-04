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
        std::stack<shared_ptr<Action>>* actions= new std::stack<shared_ptr<Action>>();
        if (m_currentCommands.size()!=0){
            
            for (int i=0; i<((int)(m_currentCommands.size())); i++)
            {
                if ((m_currentCommands[i]).get()->getTypeId() == RENFORTS)
                {
                    TeamStatus playerStatus=m_currentState.getPlayer();
                    RenfortsAction* pR= new RenfortsAction(playerStatus);
                    shared_ptr<Action> spRenforts((Action*)pR);
                    actions->push(spRenforts);
                    ((GestionRenforts*)(m_currentCommands[i]).get())->execute(m_currentState,*actions);
                }
                else if ((m_currentCommands[i]).get()->getTypeId() == ATTACK)
                {
                    int iAtt=((AttackCommand*) m_currentCommands[i].get())->getIAtt();
                    int jAtt=((AttackCommand*) m_currentCommands[i].get())->getJAtt();
                    int iDef=((AttackCommand*) m_currentCommands[i].get())->getIDef();
                    int jDef=((AttackCommand*) m_currentCommands[i].get())->getJDef();
                    int nbCreaturesAtt=((Team*)((AttackCommand*) m_currentState.getTeamBoard().getElement(iAtt,jAtt)))->getNbCreatures();
                    int nbCreaturesDef=((Team*)((AttackCommand*) m_currentState.getTeamBoard().getElement(iDef,jDef)))->getNbCreatures();
                    TeamStatus playerStatus=((Team*)((AttackCommand*) m_currentState.getTeamBoard().getElement(iAtt,jAtt)))->getTeamStatus();
                    
                    ((AttackCommand*)(m_currentCommands[i]).get())->execute(m_currentState,*actions);
                    TeamStatus playerDefResult=((Team*)((AttackCommand*) m_currentState.getTeamBoard().getElement(iDef,jDef)))->getTeamStatus();
                    if (playerDefResult==playerStatus){
                        WinAction* pW= new WinAction(iAtt,jAtt,iDef,jDef,nbCreaturesAtt,nbCreaturesDef,playerStatus); 
                        shared_ptr<Action> spWin((Action*)pW);
                        actions->push(spWin); 
                    }
                    else{
                        LooseAction* pL= new LooseAction(iAtt,jAtt,iDef,jDef,nbCreaturesAtt,nbCreaturesDef,playerStatus); 
                        shared_ptr<Action> spLoose((Action*)pL);
                        actions->push(spLoose); 
                    }
                }
                else
                {
                    ((InitBasicState*)(m_currentCommands[i]).get())->execute(m_currentState,*actions);
                }
                m_currentCommands.clear();
            }
        }
        else{
            throw runtime_error(" la list de commandes est vide");
            shared_ptr<Action> p(NULL);
            actions->push(p);
        }
        return *actions;
    }
    void Engine::undo(std::stack<shared_ptr<Action>>& actions){
        
        for (int i=0;i< (int)actions.size();i++){
            shared_ptr<Action> l=actions.top();
            l.get()->undo(m_currentState);      
        }
    }
};