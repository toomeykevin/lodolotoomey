/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream> 
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

void livrable_41_play(string commande)
{
    if (commande == "play")
    {
        cout<<"La commande est play"<<endl;
        
        // on crée l'état, le moteur, un reader pour lire le fichier
        Engine moteur;
        State& etat = moteur.getState();
        Json::Reader reader;
        // on ouvre le fichier replay
        ifstream record( "replay.txt",ios::in );
        
        // si le fichier s'est bien ouvert
        if (record)
        {
            Json::Value root;
            reader.parse(record,root);
            
            // si le fichier ne commence pas par la commande d'initialisation
            // alors message d'erreur car le jeu ne peut pas être commencé
            if (root[0]["commande"].asInt() != 0)
            {
                throw runtime_error("L'enregistrement ne commence pas par l'initialisation de l'état");
            }
            // si le fichier commence bien par la commande d'initialisation
            else
            {
                // alors on crée la commande InitBasicState à partir du premier objet Json
                InitBasicState* init = InitBasicState::deserialize(root[0]);
                // on l'ajoute à la liste des commandes à exécuter par le moteur
                moteur.addCommand((Command*)init);
                // on l'exécute
                moteur.update();
                
                ElementTabLayer Layer1(etat.getTerritoryBoard());
                ElementTabLayer Layer2(etat.getTeamBoard());
                StateLayer Layer3(etat);
                
                // on fait la liste des emplacements des commandes "GestionRenforts"
                vector<int> list_renforts;
                list_renforts.push_back(0);
                for (int i=1; i< (int)root.size(); i++)
                {
                    Json::Value node = root[i];
                    if (node["commande"].asInt() == 1)
                    {
                        list_renforts.push_back(i);
                    }
                }
                
                // Entre deux commandes GestionRenforts, on fait les attaques
                // d'un même joueur
                vector<Command*> list_command;
                for (int i=0; i<(int)list_renforts.size(); i++)
                {
                    for (int j = list_renforts[i]; j<list_renforts[i+1]; j++)
                    {
                        Json::Value obj = root[j];
                        cout << obj.toStyledString() << endl;
                        switch (obj["commande"].asInt())
                        {
                            case 0 :
                            {
                                break;
                            }
                            case 1 :
                            {
                                GestionRenforts* gestionRenforts = GestionRenforts::deserialize(obj);
                                list_command.push_back(gestionRenforts);
                                //moteur.addCommand((Command*)gestionRenforts);
                                //moteur.update();
                                //sleep(milliseconds(3));
                                break;
                            }
                            case 2 :
                            {
                                AttackCommand* attackCommand = AttackCommand::deserialize(obj);
                                list_command.push_back(attackCommand);
                                //moteur.addCommand((Command*)attackCommand);
                                //moteur.update();
                                //sleep(milliseconds(3));
                                break;
                            }
                        }
                    }
                }
                
                int index = 0;
                
                // ouverture de la page du jeu
                RenderWindow window(VideoMode(800,600,32),"Risk Fantasy | Unicorns VS Dragons",
                        Style::Close | Style::Titlebar);
                
                // on fait tourner le programme tant que la fenêtre n'est pas fermée
                while (window.isOpen())
                {
                    Event event;
                    while (window.pollEvent(event))
                    {
                        // fermeture de la fenêtre lorsque l'utilisateur le souhaite
                        if (event.type == Event::Closed)
                        {
                            window.close();
                        }
                    }
                    
                    // à chaque tour, on efface l'ancien rendu
                    window.clear(Color::Black);

                    // on dessine la surface des territoires
                    Layer1.initSurface();
                    window.draw(*(Layer1.getSurface()));

                    // on dessine la surface des équipes
                    Layer2.initSurface();
                    window.draw(*(Layer2.getSurface()));

                    // on dessine la surface des chiffres
                    Layer3.initSurface();
                    window.draw(*(Layer3.getSurface()));

                    // et on affiche le nouveau rendu
                    window.display();
                    
                    Command* commande = list_command[index];
                    index = index + 1;
                    
                    if (index < (int)list_command.size())
                    {
                        if (commande->getTypeId() == RENFORTS)
                        {
                            sleep(milliseconds(1000));
                            moteur.addCommand(commande);
                            moteur.update();
                            if (etat.getPlayer() == DRAGONS)
                            {
                                etat.setPlayer(UNICORNS);
                            }
                            else if (etat.getPlayer() == UNICORNS)
                            {
                                etat.setPlayer(DRAGONS);
                            }
                            else
                            {
                                cout << "PlayerStatus = NONE ??" << endl;
                            }
                            cout << "Renforts" << endl;
                        }
                        else
                        {
                            sleep(milliseconds(1000));
                            moteur.addCommand(commande);
                            moteur.update();
                            cout << "Attaque" << endl;
                        }
                    }
                }
            }
            // on termine en fermant le fichier
            record.close();
        }
        // si le fichier ne s'est pas ouvert : message d'erreur
        else
        {
            throw runtime_error("Problème d'ouverture du fichier");
        }
    }
    else{}
}
