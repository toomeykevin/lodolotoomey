#include "CommandsService.h"
#include <iostream>

using namespace std;

namespace server {

    CommandsService::CommandsService (Json::Value& value): AbstractService("/commands"), m_ListCommand(value) {
    }
    
    // get sert à récupérer l'ensemble des commandes du tour numéro id
    HttpStatus CommandsService::get (Json::Value& out, int id) const
    {
        // ici on va renvoyer toutes les commandes d'un tour pour qu'elles soient jouées
        // les commandes seront désérialisées par le client après
        
        // si le tour n'existe pas, on renvoie une exception
        if (id >= (int)m_ListCommand.size())
        {
            throw ServiceException(HttpStatus::NOT_FOUND,"Numéro de tour invalide");
        }
        // si le tour existe, il faut envoyer les commandes
        else
        {
           // on cherche le tour demandé
            Json::Value& tour = m_ListCommand[id];
            out = tour;
        }
        return HttpStatus::OK;
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