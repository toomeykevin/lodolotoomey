/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "AttackCommand.h"
#include <iostream>
using namespace std;

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
    void AttackCommand::execute (state::State& state){}
    
    void AttackCommand::attackWins (state::State& state){}
    void AttackCommand::attackLooses (state::State& state){}
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

