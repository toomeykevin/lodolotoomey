/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "state.h"
#include "InitBasicState.h"

using namespace std;
using namespace state;
using namespace engine;

namespace engine{
    InitBasicState::InitBasicState()
    {
        m_commandTypeId = INIT;
    }
    
    CommandTypeId InitBasicState::getTypeId () const
    {
        return m_commandTypeId;
    }
    
    void InitBasicState::serialize (Json::Value& out)
    {
        out["commande"] = m_commandTypeId;
    }
    
    InitBasicState* InitBasicState::deserialize (Json::Value& in)
    {
        if (in.isMember("commande"))
        {
            if (in["commande"].asInt() == INIT)
            {
                InitBasicState* initial = new InitBasicState();
                return initial;
            }
            else
            {
                
            }
        }
        else
        {
            throw std::runtime_error("Deserialize InitBasicState failed");
        }
        throw std::runtime_error("Deserialize InitBasicState failed");
    }
    
    void InitBasicState::execute (state::State& state, std::stack<shared_ptr<Action>>& actions)
    {
        ElementTab& territory = state.getTerritoryBoard();
        ElementTab& team = state.getTeamBoard();
        territory.resize(5,5);
        team.resize(5,5);
        
        // définition 1e ligne
            // définition 1e élément
        Territory* tr00 = new Territory(UNICORNS_T);
        tr00 -> setx(0); tr00 -> sety(0);
        territory.setElement(0,0,tr00);
        Team* tm00 = new Team(3,UNICORNS);
        tm00 -> setx(0); tm00 -> sety(0);
        team.setElement(0,0,tm00);
        
            // définition 2e élément
        Territory* tr01 = new Territory(DRAGONS_T);
        tr01 -> setx(0); tr01 -> sety(1);
        territory.setElement(0,1,tr01);
        Team* tm01 = new Team(4,DRAGONS);
        tm01 -> setx(0); tm01 -> sety(1);
        team.setElement(0,1,tm01);
        
            // définition 3e élément
        Territory* tr02 = new Territory(DRAGONS_T);
        tr02 -> setx(0); tr02 -> sety(2);
        territory.setElement(0,2,tr02);
        Team* tm02 = new Team(2,DRAGONS);
        tm02 -> setx(0); tm02 -> sety(2);
        team.setElement(0,2,tm02);
        
            // définition 4e élément
        Territory* tr03 = new Territory(DRAGONS_T);
        tr03 -> setx(0); tr03 -> sety(3);
        territory.setElement(0,3,tr03);
        Team* tm03 = new Team(4,DRAGONS);
        tm03 -> setx(0); tm03 -> sety(3);
        team.setElement(0,3,tm03);
        
            // définition 5e élément
        Territory* tr04 = new Territory(UNICORNS_T);
        tr04 -> setx(0); tr04 -> sety(4);
        territory.setElement(0,4,tr04);
        Team* tm04 = new Team(7, UNICORNS);
        tm04 -> setx(0); tm04 -> sety(4);
        team.setElement(0,4,tm04);
        
        // définition 2e ligne
            // définition 1e élément
        Territory* tr10 = new Territory(UNICORNS_T);
        tr10 -> setx(1); tr10 -> sety(0);
        territory.setElement(1,0,tr10);
        Team* tm10 = new Team(5,UNICORNS);
        tm10 -> setx(1); tm10 -> sety(0);
        team.setElement(1,0,tm10);
        
            // définition 2e élément
        Territory* tr11 = new Territory(IMPOSSIBLE);
        tr11 -> setx(1); tr11 -> sety(1);
        territory.setElement(1,1,tr11);
        Team* tm11 = new Team(0,NONE);
        tm11 -> setx(1); tm11 -> sety(1);
        team.setElement(1,1,tm11);
        
            // définition 3e élément
        Territory* tr12 = new Territory(UNICORNS_T);
        tr12 -> setx(1); tr12 -> sety(2);
        territory.setElement(1,2,tr12);
        Team* tm12 = new Team(3,UNICORNS);
        tm12 -> setx(1); tm12 -> sety(2);
        team.setElement(1,2,tm12);
        
            // définition 4e élément
        Territory* tr13 = new Territory(UNICORNS_T);
        tr13 -> setx(1); tr13 -> sety(3);
        territory.setElement(1,3,tr13);
        Team* tm13 = new Team(3,UNICORNS);
        tm13 -> setx(1); tm13 -> sety(3);
        team.setElement(1,3,tm13);
        
            // définition 5e élément
        Territory* tr14 = new Territory(UNICORNS_T);
        tr14 -> setx(1); tr14 -> sety(4);
        territory.setElement(1,4,tr14);
        Team* tm14 = new Team(8,UNICORNS);
        tm14 -> setx(1); tm14 -> sety(4);
        team.setElement(1,4,tm14);
        
        // définition 3e ligne
            // définition 1e élément
        Territory* tr20 = new Territory(DRAGONS_T);
        tr20 -> setx(2); tr20 -> sety(0);
        territory.setElement(2,0,tr20);
        Team* tm20 = new Team(2,DRAGONS);
        tm20 -> setx(2); tm20 -> sety(0);
        team.setElement(2,0,tm20);
        
            // définition 2e élément
        Territory* tr21 = new Territory(DRAGONS_T);
        tr21 -> setx(2); tr21 -> sety(1);
        territory.setElement(2,1,tr21);
        Team* tm21 = new Team(6,DRAGONS);
        tm21 -> setx(2); tm21 -> sety(1);
        team.setElement(2,1,tm21);
        
            // définition 3e élément
        Territory* tr22 = new Territory(UNICORNS_T);
        tr22 -> setx(2); tr22 -> sety(2);
        territory.setElement(2,2,tr22);
        Team* tm22 = new Team(4,UNICORNS);
        tm22 -> setx(2); tm22 -> sety(2);
        team.setElement(2,2,tm22);
        
            // définition 4e élément
        Territory* tr23 = new Territory(DRAGONS_T);
        tr23 -> setx(2); tr23 -> sety(3);
        territory.setElement(2,3,tr23);
        Team* tm23 = new Team(5,DRAGONS);
        tm23 -> setx(2); tm23 -> sety(3);
        team.setElement(2,3,tm23);
        
            // définition 5e élément
        Territory* tr24 = new Territory(UNICORNS_T);
        tr24 -> setx(2); tr24 -> sety(4);
        territory.setElement(2,4,tr24);
        Team* tm24 = new Team(7,UNICORNS);
        tm24 -> setx(2); tm24 -> sety(4);
        team.setElement(2,4,tm24);
        
        // définition 4e ligne
            // définition 1e élément
        Territory* tr30 = new Territory(UNICORNS_T);
        tr30 -> setx(3); tr30 -> sety(0);
        territory.setElement(3,0,tr30);
        Team* tm30 = new Team(3,UNICORNS);
        tm30 -> setx(3); tm30 -> sety(0);
        team.setElement(3,0,tm30);
        
            // définition 2e élément
        Territory* tr31 = new Territory(DRAGONS_T);
        tr31 -> setx(3); tr31 -> sety(1);
        territory.setElement(3,1,tr31);
        Team* tm31 = new Team(4,DRAGONS);
        tm31 -> setx(3); tm31 -> sety(1);
        team.setElement(3,1,tm31);
        
            // définition 3e élément
        Territory* tr32 = new Territory(DRAGONS_T);
        tr32 -> setx(3); tr32 -> sety(2);
        territory.setElement(3,2,tr32);
        Team* tm32 = new Team(3,DRAGONS);
        tm32 -> setx(3); tm32 -> sety(2);
        team.setElement(3,2,tm32);
        
            // définition du 4e élément
        Territory* tr33 = new Territory(IMPOSSIBLE);
        tr33 -> setx(3); tr33 -> sety(3);
        territory.setElement(3,3,tr33);
        Team* tm33 = new Team(0,NONE);
        tm33 -> setx(3); tm33 -> sety(3);
        team.setElement(3,3,tm33);
        
            // définition du 5e élément
        Territory* tr34 = new Territory(DRAGONS_T);
        tr34 -> setx(3); tr34 -> sety(4);
        territory.setElement(3,4,tr34);
        Team* tm34 = new Team(8,DRAGONS);
        tm34 -> setx(3); tm34 -> sety(4);
        team.setElement(3,4,tm34);
        
        // définition 5e ligne
            // définition 1e élément
        Territory* tr40 = new Territory(UNICORNS_T);
        tr40 -> setx(4); tr40 -> sety(0);
        territory.setElement(4,0,tr40);
        Team* tm40 = new Team(5,UNICORNS);
        tm40 -> setx(4); tm40 -> sety(0);
        team.setElement(4,0,tm40);
        
            // définition 2e élément
        Territory* tr41 = new Territory(DRAGONS_T);
        tr41 -> setx(4); tr41 -> sety(1);
        territory.setElement(4,1,tr41);
        Team* tm41 = new Team(4,DRAGONS);
        tm41 -> setx(4); tm41-> sety(1);
        team.setElement(4,1,tm41);
        
            // définition 3e élément
        Territory* tr42 = new Territory(IMPOSSIBLE);
        tr42 -> setx(4); tr42 -> sety(2);
        territory.setElement(4,2,tr42);
        Team* tm42 = new Team(0,NONE);
        tm42 -> setx(4); tm42 -> sety(2);
        team.setElement(4,2,tm42);
        
            // définition 4e élément
        Territory* tr43 = new Territory(UNICORNS_T);
        tr43 -> setx(4); tr43 -> sety(3);
        territory.setElement(4,3,tr43);
        Team* tm43 = new Team(7,UNICORNS);
        tm43 -> setx(4); tm43 -> sety(3);
        team.setElement(4,3,tm43);
        
            // définition 5e élément
        Territory* tr44 = new Territory(DRAGONS_T);
        tr44 -> setx(4); tr44 -> sety(4);
        territory.setElement(4,4,tr44);
        Team* tm44 = new Team(6,DRAGONS);
        tm44 -> setx(4); tm44 -> sety(4);
        team.setElement(4,4,tm44);
    }
};
