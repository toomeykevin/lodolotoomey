#include "CommandsService.h"
#include <iostream>

#include "engine.h"
using namespace std;
using namespace engine;

namespace server {

    CommandsService::CommandsService (Json::Value& value): AbstractService("/commands"), m_ListCommand(value) {
    }
    
    // get sert à récupérer l'ensemble des commandes du tour numéro id
    HttpStatus CommandsService::get (Json::Value& out, int id)
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
        
        /*
        int taille = (int)m_ListCommand.size();
        int index = taille;
        // si la taille est différente de l'attribut m_long
        // il faut renvoyer quelque chose
        if (m_long != taille)
        {   
            // si la dernière commande est celle d'initialisation
            if (m_ListCommand[taille - 1]["commande"].asInt() == 0)
            {
                out = m_ListCommand[taille-1];
            }
            else
            {
                // on parcourt m_ListCommand en remontant pour trouver la commande
                // Gestion Renforts d'avant
                for (int i = taille - 2 ; i>= 0; i--)
                {
                    // si l'index i est une commande gestion renforts
                    if (m_ListCommand[i]["commande"].asInt() == 1)
                    {
                        // on renvoie l'index de cette commande
                        index = i;
                        break;
                    }
                }
                // on renvoie toutes les commandes entre l'avant dernier gestion renforts
                // et le dernier
                for (int k = index ; k<taille; k++)
                {
                    out.append(m_ListCommand[k]);
                    cout << out.toStyledString() << endl;
                }
            }
            
            m_long = taille;
            //cout << m_long << endl;
        }
        */
        
        int taille = (int)m_ListCommand.size();
        Json::Value& tour = m_ListCommand[taille -1];
        out = tour;
        if (taille > 1)
        {
            out.append(m_ListCommand[taille-2]);
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