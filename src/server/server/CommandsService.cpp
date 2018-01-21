#include "CommandsService.h"
#include <iostream>

#include "engine.h"
using namespace std;
using namespace engine;

namespace server {

    CommandsService::CommandsService (Json::Value& value): AbstractService("/commands"), m_ListCommand(value) {
    }
    
    HttpStatus CommandsService::get (Json::Value& out, int id)
    {
        int taille = (int)m_ListCommand.size();
        Json::Value& tour = m_ListCommand[taille -1];
        out = tour;
        return HttpStatus::OK;
        
    }
    
    HttpStatus CommandsService::put (Json::Value& out, const Json::Value& in)
    {
        m_ListCommand.append(in);
        out["id"] = m_ListCommand.size() - 1;
        return HttpStatus::CREATED;
    }
};