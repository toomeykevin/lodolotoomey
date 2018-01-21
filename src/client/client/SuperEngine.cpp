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
    SuperEngine::SuperEngine (){}
    
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
        requestPutCmd.setUri("/commands");
        requestPutCmd.setHttpVersion(1, 1);
        requestPutCmd.setField("Content-Type", "application/x-www-form-urlencoded");
        requestPutCmd.setBody(dataCmd.toStyledString());
        // On envoie la requête au serveur
        sf::Http::Response responsePutCmd = http.sendRequest(requestPutCmd);
        cout << "Statut du serveur : " << responsePutCmd.getStatus() << endl;
        cout << "Réponse du serveur : \n" << responsePutCmd.getBody() << endl;
    }
    
    std::stack<std::shared_ptr<engine::Action>> SuperEngine::update ()
    {
        std::stack<shared_ptr<Action>> actions;
        if (m_currentCommands.size()!=0){
            for (int i=0; i<((int)(m_currentCommands.size())); i++)
            {
                if ((m_currentCommands[i]).get()->getTypeId() == RENFORTS)
                {
                    ((GestionRenforts*)(m_currentCommands[i]).get())->execute(m_currentState,actions);
                }
                else if ((m_currentCommands[i]).get()->getTypeId() == ATTACK)
                {
                    ((AttackCommand*)(m_currentCommands[i]).get())->execute(m_currentState,actions);
                }
                else
                {
                    ((InitBasicState*)(m_currentCommands[i]).get())->execute(m_currentState,actions);
                }
                
            }
            m_currentCommands.clear();
        }
        else{
            cout<<"la liste des commandes est vide"<<endl;
        }
        m_vectorStackActions.push_back(actions); // attention a vidé à l"nvers je  pense
        return actions;
    }
    void SuperEngine::rollback ()
    {
        int nLast=(int)m_vectorStackActions[m_vectorStackActions.size()-1].size();
        std::stack<std::shared_ptr<engine::Action>> stackLast=m_vectorStackActions[m_vectorStackActions.size()-1];
        for (int k=0;k<nLast;k++){
            std::shared_ptr<engine::Action> l;
            while(stackLast.size()>0){
                l=stackLast.top();
                l.get()->undo(m_currentState);
                stackLast.pop();
            }
        }
    }
  };
