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
    WinAction::WinAction(int m_iAtt,int m_jAtt,int m_iDef,int m_jDef,
            int m_nbCreaturesAtt,int m_nbCreaturesDef,TeamStatus m_AttPlayerStatus){
        
    }
    
    void WinAction::apply (state::State& state)  { }
    
    void WinAction::undo (state::State& state){}
};
