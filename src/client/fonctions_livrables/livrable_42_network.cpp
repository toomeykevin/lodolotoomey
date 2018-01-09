/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
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
        
        sf::Http http("http://localhost",8080);
        
        /* TUTO PROF METHODE PUT */
        sf::Http::Request requestP;
        requestP.setMethod(sf::Http::Request::Put);
        requestP.setUri("/user");
        requestP.setHttpVersion(1, 1);
        requestP.setField("Content-Type", "application/x-www-form-urlencoded");
        
        Json::Value data;
        data["name"]="Roger";
        data["age"]=42;
        requestP.setBody(data.toStyledString());

        sf::Http::Response responseP = http.sendRequest(requestP);
        std::cout << responseP.getStatus() << std::endl;
        std::cout << responseP.getBody() << std::endl<<endl;
        
        sf::Http::Request requestG;
        requestG.setMethod(sf::Http::Request::Get);
        requestG.setUri("/user/2");
        requestG.setHttpVersion(1, 1);
        requestG.setField("Content-Type", "application/x-www-form-urlencoded");
        
        sf::Http::Response responseG = http.sendRequest(requestG);
        std::cout << responseG.getStatus() << std::endl;
        std::cout << responseG.getBody() << std::endl;
        
        
        
        
        // vérification du statut
       /* if (response.getStatus() == sf::Http::Response::Ok)
        {
            // affichage de la réponse du serveur
            std::cout << response.getBody() << std::endl;
        }
        else
        {
            std::cout << "request failed" << std::endl;
        }*/
    }
    else{}
}
