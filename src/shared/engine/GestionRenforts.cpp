/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "GestionRenforts.h"
#include <iostream>
using namespace std;

namespace engine{
    GestionRenforts::GestionRenforts(int i){
        m_renforts=i;
    }
    CommandTypeId GestionRenforts::getTypeId () const {
        return RENFORTS;
    }
    void GestionRenforts::execute (state::State& state){}
    int GestionRenforts::getRenforts (){
        return m_renforts;
    }
    void GestionRenforts::setRenforts (int renforts){
        m_renforts=renforts;
    }
    
};