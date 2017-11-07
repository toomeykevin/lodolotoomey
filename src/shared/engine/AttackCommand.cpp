/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "AttackCommand.h"
#include <iostream>
#include "state.h"
using namespace std;
using namespace state;

namespace engine{
    
    AttackCommand::AttackCommand (int iAtt, int jAtt, int iDef, int jDef){
        m_iAtt=iAtt;
        m_jAtt=jAtt;
        m_iDef=iDef;
        m_jDef=jDef;
    }
    CommandTypeId AttackCommand::getTypeId () const{
        return ATTACK;
    }
    void AttackCommand::execute (state::State& state){
        int attNbCreatures=((Team*)(state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->getNbCreatures();
        int defNbCreatures=((Team*)(state.getTeamBoard().getElement(m_iDef,m_jDef)))->getNbCreatures();
        int AttWin=0;
        int DefWin=0;
        srand(time(0));
        for (int k=0;k<attNbCreatures;k++){
            AttWin=AttWin+ (rand() %6) + 1;
        }
        srand(time(0));
        for (int m=0;m<defNbCreatures;m++){
            DefWin=DefWin+ (rand() %6) + 1;
        }
        if (AttWin>DefWin){
            attackWins(state);
        }
        else{
            attackLooses(state);
        } 
    }
    
    void AttackCommand::attackWins (state::State& state){
        int nbCreatures=((Team*)(state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->getNbCreatures();
        ((Team*)(state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->setNbCreatures(1);
        ((Team*)(state.getTeamBoard().getElement(m_iDef,m_jDef)))->setNbCreatures(nbCreatures-1);
        
        TeamStatus attTeamStatus=((Team*)(state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->getTeamStatus();
        ((Team*)(state.getTeamBoard().getElement(m_iDef,m_jDef)))->setTeamStatus(attTeamStatus);
        
        TerritoryStatus attTerritoryStatus=((Territory*)(state.getTerritoryBoard().getElement(m_iAtt,m_jAtt)))->getTerritoryStatus();
        ((Territory*)(state.getTerritoryBoard().getElement(m_iDef,m_jDef)))->setTerritoryStatus(attTerritoryStatus);
    }
    void AttackCommand::attackLooses (state::State& state){
        ((Team*)(state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->setNbCreatures(1);
    }
    int AttackCommand::getIAtt (){
        return m_iAtt;
    }
    void AttackCommand::setIAtt (int iAtt){
        m_iAtt=iAtt;
    }
    int AttackCommand::getJAtt (){
        return m_jAtt;
    }
    void AttackCommand::setJAtt (int jAtt){
        m_jAtt=jAtt;
    }
    int AttackCommand::getIDef (){
        return m_iDef;
    }
    void AttackCommand::setIDef (int iDef){
        m_iDef=iDef;
    }
    int AttackCommand::getJDef (){
        return m_jDef;
    }
    void AttackCommand::setJDef (int jDef){
        m_jDef=jDef;
    }
};

