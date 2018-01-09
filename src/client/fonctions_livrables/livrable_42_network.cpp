/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

using namespace std;
using namespace sf;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;


void livrable_42_network(string commande)
{
    if (commande == "network")
    {
        cout<<"La commande est network"<<endl;
        
        /* TUTO PROF METHODE PUT */
        sf::Http::Request request;
        request.setMethod(sf::Http::Request:ut);
        request.setUri("/player");
        request.setHttpVersion(1, 1);
        request.setField("Content-Type", "application/x-www-form-urlencoded");
        request.setBody(data.toStyledString());
        
        /* TUTO SFML METHODE POST */
        // préparation de la requête
        sf::Http::Request request("/send-score.php", sf::Http::Request::Post);

        // encodage des paramètres dans le corps de la requête
        std::ostringstream stream;
        stream << "name=" << name << "&score=" << score;
        request.setBody(stream.str());

        // envoi de la requête au serveur
        sf::Http http("http://www.myserver.com/");
        sf::Http::Response response = http.sendRequest(request);

        // vérification du statut
        if (response.getStatus() == sf::Http::Response::Ok)
        {
            // affichage de la réponse du serveur
            std::cout << response.getBody() << std::endl;
        }
        else
        {
            std::cout << "request failed" << std::endl;
        }
    }
    else{}
}
