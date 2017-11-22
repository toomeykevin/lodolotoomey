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

using namespace std;
using namespace state;

namespace engine{
    AttackCommand::AttackCommand (int iAtt, int jAtt, int iDef, int jDef)
    {
        m_iAtt = iAtt;
        m_jAtt = jAtt;
        m_iDef = iDef;
        m_jDef = jDef;
        m_commandTypeId = ATTACK;
    }
    
    CommandTypeId AttackCommand::getTypeId () const
    {
        return m_commandTypeId;
    }
    
    void AttackCommand::execute (state::State& state)
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
            if(not((abs(m_iAtt-m_iDef)!=0) && ((m_jAtt-m_jDef < 0 && m_iDef%2==0) || (m_jAtt-m_jDef > 0 && m_iDef%2!=0)))){
                if (AttWin > DefWin && attNbCreatures > 1 && defNbCreatures != 0)
                {
                    attackWins(state);
                }
                else if (AttWin <= DefWin && attNbCreatures > 1 && defNbCreatures != 0)
                {
                    attackLooses(state);
                } 
                else
                {
                    cout << "Ce territoire ne peut être attaqué par le territoire choisi"<< endl;
                }
            }
        }
        else
        {
            cout << "Ce territoire ne peut être attaqué par le territoire choisi"<< endl;
        }
    
    }
    
    void AttackCommand::attackWins (state::State& state)
    {
        int nbCreatures =
                ((Team*)(state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->getNbCreatures();
        ((Team*)(state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->setNbCreatures(1);
        ((Team*)(state.getTeamBoard().getElement(m_iDef,m_jDef)))->setNbCreatures(nbCreatures-1);
        
        TeamStatus attTeamStatus =
                ((Team*)(state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->getTeamStatus();
        ((Team*)(state.getTeamBoard().getElement(m_iDef,m_jDef)))->setTeamStatus(attTeamStatus);
        
        TerritoryStatus attTerritoryStatus =
                ((Territory*)(state.getTerritoryBoard().getElement(m_iAtt,m_jAtt)))->getTerritoryStatus();
        ((Territory*)(state.getTerritoryBoard().getElement(m_iDef,m_jDef)))->setTerritoryStatus(attTerritoryStatus);
    }
    
    void AttackCommand::attackLooses (state::State& state)
    {
        ((Team*)(state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->setNbCreatures(1);
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
};

