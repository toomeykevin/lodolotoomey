/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include "state.h"
#include "engine.h"
#include "ai.h"

using namespace std;
using namespace state;
using namespace engine;
using namespace ai;

void livrable_41_record(string commande)
{
    if (commande == "record")
    {
        cout<<"La commande est record"<<endl;
        
        ofstream replay("replay.txt", ios::out);
        
        Json::StyledWriter styledWriter;
        
        if (replay)
        {
            HeuristicAI* AIPlayer = new HeuristicAI();
            Engine moteur;
            
            // initialisation de l'état
            InitBasicState* initState = new InitBasicState();
            
            Json::Value initialisation;
            initState->serialize(initialisation);

            moteur.addCommand((Command*)initState);
            moteur.update();
            
            Json::Value record;
            record.append(initialisation);
            
            AIPlayer->setRecorded(record);
            
            while (!(moteur.getState().isGameOver()))
            {
                AIPlayer->run(moteur);
            }
      
            replay << styledWriter.write(AIPlayer->getRecorded());
        }
        else
        {
            throw std::runtime_error("Erreur à l'ouverture");
        }
    }
    else
    {}
}
