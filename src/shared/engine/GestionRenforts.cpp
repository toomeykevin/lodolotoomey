/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "state.h"
#include "GestionRenforts.h"

using namespace std;
using namespace state;

namespace engine{
    GestionRenforts::GestionRenforts(int i)
    {
        m_renforts = i;
        m_commandTypeId = RENFORTS;
    }
    
    CommandTypeId GestionRenforts::getTypeId () const
    {
        return m_commandTypeId;
    }
    
    void GestionRenforts::execute (state::State& state, std::stack<shared_ptr<Action>>& actions)
    {    
        TeamStatus playerStatus=state.getPlayer();
        RenfortsAction* pR= new RenfortsAction(playerStatus);
        shared_ptr<Action> spRenforts((Action*)pR);
        actions.push(spRenforts);
        pR->apply(state);
    }
    
    int GestionRenforts::getRenforts ()
    {
        return m_renforts;
    }
    
    void GestionRenforts::setRenforts (int renforts)
    {
        m_renforts = renforts;
    }
    
    void GestionRenforts::serialize (Json::Value& out)
    {
        Json::Value command;
        command["commande_renforts"] = m_commandTypeId;
        command["renforts"] = m_renforts;
        out.append(command);
    }
    
    GestionRenforts* GestionRenforts::deserialize (Json::Value& in)
    {
        if (in.isMember("commande_renforts"))
        {
            if (in["commande_renforts"].asInt() == RENFORTS)
            {
                int renforts = in["renforts"].asInt();
                GestionRenforts* apportRenforts = new GestionRenforts(renforts);
                return apportRenforts;
            }
            else
            {
                
            }
        }
        else
        {
            throw std::runtime_error("Deserialize GestionRenforts failed");
        }
        throw std::runtime_error("Deserialize GestionRenforts failed");
    }
};