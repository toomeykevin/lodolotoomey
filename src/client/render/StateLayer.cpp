/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "StateLayer.h"
#include <iostream>

using namespace std;


namespace render{
    StateLayer::StateLayer (state::State& state): m_state(state){}
    void StateLayer::initSurface (){}
};
