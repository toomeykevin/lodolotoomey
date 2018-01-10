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
        sf::Http::Request requestPost;
        requestPost.setMethod(sf::Http::Request::Put);
        requestPost.setUri("/user/1");
        requestPost.setHttpVersion(1, 1);
        requestPost.setField("Content-Type", "application/x-www-form-urlencoded");
        
        Json::Value dataPost;
        dataPost["name"]="Thierry";
        dataPost["age"]=55;
        requestPost.setBody(dataPost.toStyledString());

        sf::Http::Response responsePost = http.sendRequest(requestPost);
        std::cout << responsePost.getStatus() << std::endl;
        std::cout << responsePost.getBody() << std::endl<<endl;
        
        sf::Http::Request requestPut;
        requestPut.setMethod(sf::Http::Request::Put);
        requestPut.setUri("/user");
        requestPut.setHttpVersion(1, 1);
        requestPut.setField("Content-Type", "application/x-www-form-urlencoded");
        
        Json::Value data;
        data["name"]="Roger";
        data["age"]=42;
        requestPut.setBody(data.toStyledString());

        sf::Http::Response responsePut = http.sendRequest(requestPut);
        std::cout << responsePut.getStatus() << std::endl;
        std::cout << responsePut.getBody() << std::endl<<endl;
        
        sf::Http::Request requestGet;
        requestGet.setMethod(sf::Http::Request::Get);
        requestGet.setUri("/user/2");
        requestGet.setHttpVersion(1, 1);
        requestGet.setField("Content-Type", "application/x-www-form-urlencoded");
        
        sf::Http::Response responseGet = http.sendRequest(requestGet);
        std::cout << responseGet.getStatus() << std::endl;
        std::cout << responseGet.getBody() << std::endl;
        
        
        sf::Http::Request requestPut2;
        requestPut2.setMethod(sf::Http::Request::Put);
        requestPut2.setUri("/user");
        requestPut2.setHttpVersion(1, 1);
        requestPut2.setField("Content-Type", "application/x-www-form-urlencoded");
        
        Json::Value data2;
        data2["name"]="doesn't exist";
        data2["age"]=4596;
        requestPut2.setBody(data2.toStyledString());

        sf::Http::Response responsePut2 = http.sendRequest(requestPut2);
        std::cout << responsePut2.getStatus() << std::endl;
        std::cout << responsePut2.getBody() << std::endl<<endl;
        
        
        
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
