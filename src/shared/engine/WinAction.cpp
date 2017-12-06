/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "WinAction.h"


using namespace std;
using namespace state;

namespace engine{
    WinAction::WinAction(int iAtt,int jAtt,int iDef,int jDef,
            int nbCreaturesAtt,int nbCreaturesDef,TeamStatus AttPlayerStatus){
        m_iAtt=iAtt;
        m_jAtt=jAtt;
        m_iDef=iDef;
        m_jDef=jDef;
        m_nbCreaturesAtt=nbCreaturesAtt;
        m_nbCreaturesDef=nbCreaturesDef;
        m_AttPlayerStatus=AttPlayerStatus;
    }
    
    void WinAction::apply (state::State& state)  { 
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
    
    void WinAction::undo (state::State& state){
        ((Team*)(state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->setNbCreatures(m_nbCreaturesAtt);
        ((Team*)(state.getTeamBoard().getElement(m_iDef,m_jDef)))->setNbCreatures(m_nbCreaturesDef);
        TeamStatus defPlayerStatus;
        if(m_AttPlayerStatus== DRAGONS){
            defPlayerStatus=UNICORNS;
        }
        else{
            defPlayerStatus=DRAGONS;
        }
        ((Team*)(state.getTeamBoard().getElement(m_iDef,m_jDef)))->setTeamStatus(defPlayerStatus);
        
        TerritoryStatus attTerritoryStatus =
                ((Territory*)(state.getTerritoryBoard().getElement(m_iAtt,m_jAtt)))->getTerritoryStatus();
        TerritoryStatus defTerritoryStatus;
        if(attTerritoryStatus== DRAGONS_T){
            defTerritoryStatus=UNICORNS_T;
        }
        else{
            defTerritoryStatus=DRAGONS_T;
        }
        ((Territory*)(state.getTerritoryBoard().getElement(m_iDef,m_jDef)))->setTerritoryStatus(defTerritoryStatus);
    
    }
};
