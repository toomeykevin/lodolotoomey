/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "RandomAI.h"
#include "engine/Engine.h"

#include <iostream>
using namespace std;
using namespace ai;
using namespace engine;

namespace ai{
    void RandomAI::run (engine::Engine& engine){
        vector<unique_ptr<Command>> list;
        listCommands(list,engine.getState());
    }
    RandomAI::RandomAI (){
              
        
    }

  
};