#include "CommandsService.h"
#include <iostream>

#include "engine.h"
using namespace std;
using namespace engine;

namespace server {

    CommandsService::CommandsService (Json::Value& value): AbstractService("/commands"), m_ListCommand(value) {
    }
    
    // get sert à récupérer l'ensemble des commandes du tour numéro id
    HttpStatus CommandsService::get (Json::Value& out, int id) const
    {
        /*const Command* cmd = m_ListCommand[id];
        if (!cmd)
        {
            return HttpStatus::NO_CONTENT;
        }
        else
        {
            out = m_ListCommand[id];
            return HttpStatus::OK;
        }
        */
        
        out = m_ListCommand[id];
        return HttpStatus::OK;
        /*
        int taille = (int)m_ListCommand.size();
        Json::Value& tour = m_ListCommand[taille -1];
        out = tour;
        return HttpStatus::OK;
        */
    }
    
    HttpStatus CommandsService::put (Json::Value& out, const Json::Value& in)
    {
        // ici on va rajouter un tour à la liste de commandes
        // les commandes ont été sérialisées par le client avant
        m_ListCommand.append(in);
        out["id"] = m_ListCommand.size() - 1;
        
        // potentiellement quelques conditions de vérification
        
        // le Json in contient les données de la commande en question
        // le Json out sert à renvoyer juste l'id de la nouvelle commande
        
        return HttpStatus::CREATED;
    }
};