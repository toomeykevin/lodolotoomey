/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"SuperEngine.h"
#include <SFML/Network.hpp>
#include "engine.h"
#include <iostream>

using namespace std;
using namespace engine;
using namespace sf;

namespace client {

    // Operations
    SuperEngine::SuperEngine (){
        
    }
    void SuperEngine::addCommand (engine::Command* cmd){
        m_currentCommands.push_back(std::unique_ptr<Command>(cmd));
        
        Json::Value dataCmd;
        if (cmd->getTypeId()==RENFORTS){
            ((GestionRenforts*)cmd)->serialize(dataCmd);    
        }
        else if (cmd->getTypeId()==INIT){
            ((InitBasicState*)cmd)->serialize(dataCmd);
        }
        else if (cmd->getTypeId()==ATTACK){
            ((AttackCommand*)cmd)->serialize(dataCmd); 
        }
        else{
            cout<<"command type error"<<endl;
        }

        sf::Http http("http://localhost",8080);
        
        sf::Http::Request requestPutCmd;
        requestPutCmd.setMethod(sf::Http::Request::Put);
        requestPutCmd.setUri("/Commands");
        requestPutCmd.setHttpVersion(1, 1);
        requestPutCmd.setField("Content-Type", "application/x-www-form-urlencoded");
        // On demande son pseudo au joueur
        

        requestPutCmd.setBody(dataCmd.toStyledString());
        // On envoie la requête au serveur
        sf::Http::Response responsePutCmd = http.sendRequest(requestPutCmd);
        cout << "Statut du serveur : " << responsePutCmd.getStatus() << endl;
        cout << "Réponse du serveur : \n" << responsePutCmd.getBody() << endl;
    }
  };
