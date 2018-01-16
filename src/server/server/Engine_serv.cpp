/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <SFML/Network.hpp>
#include "Engine_serv.h"
#include <iostream>
using namespace engine;
using namespace sf;
using namespace std;

namespace server {

Engine_serv::Engine_serv () { 
}

void Engine_serv::addCommand (Command* cmd) {
    //m_currentCommands.push_back(std::unique_ptr<Command>(cmd));
        sf::Http http("http://localhost",8080);
        
        sf::Http::Request requestPut;
        requestPut.setMethod(sf::Http::Request::Put);
        requestPut.setUri("/command");
        requestPut.setHttpVersion(1, 1);
        requestPut.setField("Content-Type", "application/x-www-form-urlencoded");
        // Ce joueur s'appelle Roger
        Json::Value data;
        cout << "Entrez votre pseudo" << endl;
 
        requestPut.setBody(data.toStyledString());
        // On envoie la requête au serveur
        sf::Http::Response responsePut = http.sendRequest(requestPut);
        cout << "-- Requête PUT --" << endl;
        cout << "Statut du serveur : " << responsePut.getStatus() << endl;
        cout << "Réponse du serveur : \n" << responsePut.getBody() << endl;
}

};
