/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "LooseAction.h"


using namespace std;
using namespace state;

namespace engine{
    LooseAction::LooseAction(int iAtt,int jAtt,int iDef,int jDef,
            int nbCreaturesAtt,int nbCreaturesDef,TeamStatus AttPlayerStatus){
        m_iAtt=iAtt;
        m_jAtt=jAtt;
        m_iDef=iDef;
        m_jDef=jDef;
        m_nbCreaturesAtt=nbCreaturesAtt;
        m_nbCreaturesDef=nbCreaturesDef;
        m_AttPlayerStatus=AttPlayerStatus;
    }
    
    void LooseAction::apply (state::State& state)  {
        ((Team*)(state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->setNbCreatures(1);
    }
    
    void LooseAction::undo (state::State& state){
        ((Team*)(state.getTeamBoard().getElement(m_iAtt,m_jAtt)))->setNbCreatures(m_nbCreaturesAtt);
    }
};
