/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "CommandsService.h"
using namespace std;

namespace server {

    CommandsService::CommandsService (): AbstractService("/commands"){}
    
    // get sert à récupérer l'ensemble des commandes du tour numéro id
    HttpStatus CommandsService::get (Json::Value& out, int id) const
    {
        // ici on va renvoyer toutes les commandes d'un tour pour qu'elles soient jouées
        // les commandes seront désérialisées par le client après
        // on cherche le tour en question
        
        // si le tour n'existe pas, on renvoie une exception
        
        // si le tour existe, il faut envoyer les commandes
        
        return HttpStatus::OK;
    }
    
    HttpStatus CommandsService::put (Json::Value& out, Json::Value& in)
    {
        // ici on va rajouter une commande à la liste de commandes
        // la commande a été sérialisée par le client avant
        
        // le Json in contient les données de la commande en question
        // le Json out sert à renvoyer juste l'id de la nouvelle commande
        
        return HttpStatus::CREATED;
    }
};