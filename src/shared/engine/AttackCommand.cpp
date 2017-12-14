/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <random>
#include <chrono>
#include "state.h"
#include "AttackCommand.h"
#include "WinAction.h"
#include "json/json.h"

using namespace std;
using namespace state;
using namespace engine;

namespace engine{
    AttackCommand::AttackCommand (int iAtt, int jAtt, int iDef, int jDef, state::TeamStatus ts)
    {
        m_iAtt = iAtt;
        m_jAtt = jAtt;
        m_iDef = iDef;
        m_jDef = jDef;
        m_winner = ts;
        m_commandTypeId = ATTACK;
    }
    
    CommandTypeId AttackCommand::getTypeId () const
    {
        return m_commandTypeId;
    }
    
    void AttackCommand::execute (state::State& state, std::stack<std::shared_ptr<engine::Action>>& actions)
    {
        int attNbCreatures =
                ((Team*)(state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->getNbCreatures();
        int defNbCreatures =
                ((Team*)(state.getTeamBoard().getElement(m_iDef,m_jDef)))->getNbCreatures();
        int AttWin = 0;
        int DefWin = 0;
        TeamStatus DefTeamStatus =
                ((Team*)(state.getTeamBoard().getElement(m_iDef,m_jDef)))->getTeamStatus();
        TeamStatus playerStatus = state.getPlayer();
        
        // condition sur iAtt-iDef et sur la team
        for (int k=0; k<attNbCreatures; k++)
        {
            random_device rd; 
            mt19937 rng(rd());
            uniform_int_distribution<int> uni(1,6); // guaranteed unbiased
            auto random_integer = uni(rng);
            AttWin = AttWin + (random_integer);
        }
        
        for (int m=0; m<defNbCreatures; m++)
        {
            random_device rd; 
            mt19937 rng(rd());
            uniform_int_distribution<int> uni(1,6); // guaranteed unbiased
            auto random_integer = uni(rng);
            DefWin = DefWin + (random_integer);
        }
        
        if (abs(m_iAtt-m_iDef) < 2 && abs(m_jAtt-m_jDef) < 2 && (playerStatus != DefTeamStatus))
        {
            //cout<<"je suis execute atack command"<< ((Team*)state.getTeamBoard().getElement(2,1))->getNbCreatures()<<endl;
            if(not((m_iAtt!=m_iDef) && ((m_jAtt>m_jDef && m_iDef%2==0) || (m_jAtt< m_jDef && m_iDef%2!=0))))
            {
                
                if (AttWin > DefWin && attNbCreatures > 1 && defNbCreatures != 0)
                {
                    attackWins(state, actions);
                    m_winner = playerStatus;  
                }
                else if (AttWin <= DefWin && attNbCreatures > 1 && defNbCreatures != 0)
                {
                    attackLooses(state, actions);
                    if (playerStatus == DRAGONS)
                    {
                        m_winner = UNICORNS;
                    }
                    else if (playerStatus == UNICORNS)
                    {
                        m_winner = DRAGONS;
                    }
                } 
                else
                {
                    cout << "Ce territoire ne peut être attaqué par le territoire choisi"<< endl;
                }
            }
            else
            {
               throw runtime_error("la bataille est ni gagné ni perdu = probleme"); 
            }
        }
        else
        {
            cout << "Ce territoire ne peut être attaqué par le territoire choisi"<< endl;
        }

    }
    
    void AttackCommand::attackWins (state::State& state, std::stack<std::shared_ptr<engine::Action>>& actions)
    { 
        int nbCreaturesAtt =
            ((Team*)((AttackCommand*) state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->getNbCreatures();
        int nbCreaturesDef =
            ((Team*)((AttackCommand*) state.getTeamBoard().getElement(m_iDef,m_jDef)))->getNbCreatures();
        TeamStatus playerStatus =
            ((Team*)((AttackCommand*) state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->getTeamStatus();
        WinAction* pW =
            new WinAction(m_iAtt,m_jAtt,m_iDef,m_jDef,nbCreaturesAtt,nbCreaturesDef,playerStatus); 
        shared_ptr<Action> spWin((Action*)pW);
        actions.push(spWin); 
        pW->apply(state);
        m_winner = playerStatus;
    }
    
    void AttackCommand::attackLooses (state::State& state, std::stack<std::shared_ptr<engine::Action>>& actions)
    {
       int nbCreaturesAtt =
            ((Team*)((AttackCommand*) state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->getNbCreatures();
       int nbCreaturesDef =
            ((Team*)((AttackCommand*) state.getTeamBoard().getElement(m_iDef,m_jDef)))->getNbCreatures();
       TeamStatus playerStatus =
            ((Team*)((AttackCommand*) state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->getTeamStatus();

       LooseAction* pL =
            new LooseAction(m_iAtt,m_jAtt,m_iDef,m_jDef,nbCreaturesAtt,nbCreaturesDef,playerStatus); 
       shared_ptr<Action> spLoose((Action*)pL);
       actions.push(spLoose);
       
       pL->apply(state);
       m_winner = playerStatus;
    }
    
    int AttackCommand::getIAtt ()
    {
        return m_iAtt;
    }
    
    void AttackCommand::setIAtt (int iAtt)
    {
        m_iAtt = iAtt;
    }
    
    int AttackCommand::getJAtt ()
    {
        return m_jAtt;
    }
    
    void AttackCommand::setJAtt (int jAtt)
    {
        m_jAtt = jAtt;
    }
    
    int AttackCommand::getIDef ()
    {
        return m_iDef;
    }
    
    void AttackCommand::setIDef (int iDef)
    {
        m_iDef = iDef;
    }
    
    int AttackCommand::getJDef ()
    {
        return m_jDef;
    }
    
    void AttackCommand::setJDef (int jDef)
    {
        m_jDef = jDef;
    }
    
    void AttackCommand::serialize (Json::Value& out)
    {
        Json::Value command;
        command["commande_attaque"] = m_commandTypeId;
        command["iAtt"] = m_iAtt;
        command["jAtt"] = m_jAtt;
        command["iDef"] = m_iDef;
        command["jDef"] = m_jDef;
        command["gagnant"] = m_winner;
        out.append(command);
    }
    
    AttackCommand* AttackCommand::deserialize (Json::Value& in)
    {
        if (in.isMember("commande_attaque"))
        {
            if (in["commande_attaque"].asInt() == ATTACK)
            {
                int iAtt = in["iAtt"].asInt();
                int jAtt = in["jAtt"].asInt();
                int iDef = in["iDef"].asInt();
                int jDef = in["jDef"].asInt();
                int gagnant = in["gagnant"].asInt();
                
                //TeamStatus w;
                if (gagnant == 1)
                {
                    TeamStatus* w = new TeamStatus(DRAGONS);
                    AttackCommand* attaque = new AttackCommand(iAtt, jAtt, iDef, jDef, *w);
                    return attaque;
                }
                else if (gagnant == 2)
                {
                    TeamStatus* w = new TeamStatus(UNICORNS);
                    AttackCommand* attaque = new AttackCommand(iAtt, jAtt, iDef, jDef, *w);
                    return attaque;
                }
                else
                {
                    TeamStatus* w = new TeamStatus(NONE);
                    AttackCommand* attaque = new AttackCommand(iAtt, jAtt, iDef, jDef, *w);
                    return attaque;
                } 
            }
            else
            {
                
            }
        }
        else
        {
            throw std::runtime_error("Deserialize AttackCommand failed");
        }
        throw std::runtime_error("Deserialize AttackCommand failed");
    }
};

