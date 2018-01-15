/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "CommandsService.h"
using namespace std;

namespace server {

    CommandsService::CommandsService (engine::Engine& engine): AbstractService("/commands"),m_engine(engine){
    }
    HttpStatus CommandsService::get (Json::Value& out, int id) const{
        return HttpStatus::OK;
    }
    HttpStatus CommandsService::put (Json::Value& out, Json::Value& in){
        return HttpStatus::CREATED;
    }
};