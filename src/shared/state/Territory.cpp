/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Territory.h"

using namespace std;

namespace state{
    Territory::Territory (TerritoryStatus territoryStatus)
    {
        m_territoryStatus = territoryStatus;
    }
    
    TerritoryStatus Territory::getTerritoryStatus ()
    {
        return m_territoryStatus;
    }
    
    void Territory::setTerritoryStatus (TerritoryStatus territoryStatus)
    {
        m_territoryStatus = territoryStatus;
    }
    
    bool Territory::isStatic ()
    {
        return true;
    }
    
};