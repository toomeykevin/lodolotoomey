/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"
#include "server.h"
#include "client.h"

using namespace std;
using namespace sf;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;
using namespace server;
using namespace client;

// déclaration d'un mutex global
mutex m;

// routine du thread secondaire
void routine_thread(HeuristicAI* AIPlayer, SuperEngine& moteur)
{
    // on attend 10s avant d'exécuter l'AI :
    // ça laisse le temps à la fenêtre d'affichage de s'ouvrir
    sleep(milliseconds(10000));
    // tant que le jeu n'est pas fini
    while(!moteur.getState().isGameOver())
    {
        // on verrouille le mutex pour qu'il n'y ait pas d'affichage pendant que
        // l'AI modifie l'état
        {
            std::lock_guard<std::mutex> lck (m);
            AIPlayer->run(moteur);
            //moteur.undo(stackActions);
        }
        // on attend 3s avant de passer au tour suivant : permet un affichage clair
        sleep(milliseconds(3000));
    }
}

void livrable_42_network(string commande)
{
    if (commande == "network")
    {
        sf::Http http("http://localhost",8080);
        
        sf::Http::Request requestPut;
        requestPut.setMethod(sf::Http::Request::Put);
        requestPut.setUri("/user");
        requestPut.setHttpVersion(1, 1);
        requestPut.setField("Content-Type", "application/x-www-form-urlencoded");
        // On demande son pseudo au joueur
        Json::Value data;
        cout << "Entrez votre pseudo" << endl;
        string pseudo;
        cin >> pseudo;
        data["name"]=pseudo;
        requestPut.setBody(data.toStyledString());
        // On envoie la requête au serveur
        sf::Http::Response responsePut = http.sendRequest(requestPut);
        cout << "-- AJOUT D'UN NOUVEAU JOUEUR --" << endl;
        cout << "Statut du serveur : " << responsePut.getStatus() << endl;
        cout << "Réponse du serveur : \n" << responsePut.getBody() << endl;
        
        // on veut savoir si après s'être rajouté à la liste des joueurs
        // la partie est lancée
        Json::Reader reader;
        Json::Value reponse;
        reader.parse(responsePut.getBody(),reponse);
        
        // si on est le premier joueur, on reste en attente du serveur
        if (reponse["Game started"].asBool() == false)
        {
            // Attente du lancement de la partie
            bool g = false;
            while (!g)
            {
                sf::Http::Request requestGetGame;
                requestGetGame.setMethod(sf::Http::Request::Get);
                requestGetGame.setUri("/game/2");
                requestGetGame.setHttpVersion(1, 1);
                requestGetGame.setField("Content-Type", "application/x-www-form-urlencoded");
                // On envoie la requête au serveur
                sf::Http::Response responseGetGame = http.sendRequest(requestGetGame);

                // on veut savoir si la partie est lancée
                Json::Reader reader;
                Json::Value reponseGetGame;
                reader.parse(responseGetGame.getBody(),reponseGetGame);
                
                if (reponseGetGame["Game started"].asBool() == true)
                {
                    g = true;
                    cout << "-- LANCEMENT DE LA PARTIE --" << endl;
                }
            }
            
            sf::Http::Request requestGetCmd;
            requestGetCmd.setMethod(sf::Http::Request::Get);
            requestGetCmd.setUri("/commands/1");
            requestGetCmd.setHttpVersion(1, 1);
            requestGetCmd.setField("Content-Type", "application/x-www-form-urlencoded");
            // On envoie la requête au serveur
            sf::Http::Response responseGetCmd = http.sendRequest(requestGetCmd);
            cout << "Statut du serveur : " << responseGetCmd.getStatus() << endl;
            cout << "Réponse du serveur : \n" << responseGetCmd.getBody() << endl;
            
            // Attente de commande de la part du serveur
            while(1)
            {
                
            }
        }
        
        // si on est le deuxième joueur, on est celui qui lance la partie
        // et affiche la fenêtre
        if (reponse["Game started"].asBool() == true)
        {
            cout << "-- LANCEMENT DE LA PARTIE --" << endl;
            
            // création AI, moteur et état
            HeuristicAI* AIPlayer = new HeuristicAI();
            
            SuperEngine moteur;
            State& etat = moteur.getState();
            
            InitBasicState* init = new InitBasicState();
            // on l'ajoute à la liste des commandes à exécuter par le moteur
            moteur.addCommand((Command*)init);
            // on l'exécute
            moteur.update();
            
            // création du thread qui fait le calcul du tour
            thread th(&routine_thread, AIPlayer, std::ref(moteur));

            ElementTabLayer Layer1(etat.getTerritoryBoard());
            ElementTabLayer Layer2(etat.getTeamBoard());
            StateLayer Layer3(etat);
            
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
                
                // on verrouille le mutex pour que le thread ne cherche pas à
                // modifier l'état, puisqu'on va l'afficher
                std::lock_guard<std::mutex> lck (m);

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
                
                if (moteur.getState().isGameOver())
                {
                    string strfinal;
                    if(moteur.getState().getPlayer()==DRAGONS)
                    {
                        strfinal="UNICORNS";
                    }
                    else
                    {
                        strfinal="DRAGONS";
                    }

                    cout<< "GAME OVER : The winner is "<<strfinal<<endl;
                    sleep(milliseconds(3000));
                    window.close();
                }

            }
            th.join();
        }
        
        /*
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
        */
        
        
        
        /* LIVRABLE 4.2 */
        /*
        // Première requête : POST
        // Pour modifier l'utilisateur ajouté lors du lancement du serveur
        sf::Http::Request requestPost;
        requestPost.setMethod(sf::Http::Request::Post);
        requestPost.setUri("/user/1");
        requestPost.setHttpVersion(1, 1);
        requestPost.setField("Content-Type", "application/x-www-form-urlencoded");
        // On veut remplacer Paul par Thierry
        Json::Value dataPost;
        dataPost["name"]="Thierry";
        requestPost.setBody(dataPost.toStyledString());
        // On envoie la requête au serveur
        sf::Http::Response responsePost = http.sendRequest(requestPost);
        cout << "Première requête : POST - remplacement Paul par Thierry" << endl;
        std::cout << "Statut du serveur : " << responsePost.getStatus() << std::endl;
        std::cout << "Réponse du serveur : \n" << responsePost.getBody() << std::endl;
        
        // Deuxième requête : PUT
        // On ajoute un deuxième utilisateur
        sf::Http::Request requestPut;
        requestPut.setMethod(sf::Http::Request::Put);
        requestPut.setUri("/user");
        requestPut.setHttpVersion(1, 1);
        requestPut.setField("Content-Type", "application/x-www-form-urlencoded");
        // Ce joueur s'appelle Roger
        Json::Value data;
        data["name"]="Roger";
        requestPut.setBody(data.toStyledString());
        // On envoie la requête au serveur
        sf::Http::Response responsePut = http.sendRequest(requestPut);
        cout << "Deuxième requête : PUT - ajout du joueur Roger" << endl;
        std::cout << "Statut du serveur : " << responsePut.getStatus() << std::endl;
        std::cout << "Réponse du serveur : \n" << responsePut.getBody() << std::endl;
        
        Http::Response::Status StatusPutOK=Http::Response::Created;
        if (responsePut.getStatus()==StatusPutOK)
        {
            NbrJoueurs+=1;
        }
        if (NbrJoueurs==2)
        {
            cout <<"La partie est prête pour le lancement : Nous avons 2 joueurs"<<endl<<endl;
        }
        
        // Troisième requête : PUT
        // On tente d'ajouter un troisième utilisateur, ce qui normalement n'est pas possible
        sf::Http::Request requestPut2;
        requestPut2.setMethod(sf::Http::Request::Put);
        requestPut2.setUri("/user");
        requestPut2.setHttpVersion(1, 1);
        requestPut2.setField("Content-Type", "application/x-www-form-urlencoded");
        // Ludovic essaie de s'ajouter à la partie
        Json::Value data2;
        data2["name"]="Ludovic";
        requestPut2.setBody(data2.toStyledString());
        // On envoie la requête au serveur
        sf::Http::Response responsePut2 = http.sendRequest(requestPut2);
        cout << "On essaie d'ajouter un nouvel utilisateur." << endl;
        cout << "Normalement ce n'est pas possible, il y a déjà deux joueurs." << endl;
        std::cout << "Statut du serveur : " << responsePut2.getStatus() << std::endl;
        std::cout << "Réponse du serveur : \n" << responsePut2.getBody() << std::endl;
        
        // Quatrième requête : GET
        // Pour obtenir la liste des joueurs
        sf::Http::Request requestGet;
        requestGet.setMethod(sf::Http::Request::Get);
        requestGet.setUri("/user/-1");
        requestGet.setHttpVersion(1, 1);
        requestGet.setField("Content-Type", "application/x-www-form-urlencoded");
        // On envoie la requête au serveur
        sf::Http::Response responseGet = http.sendRequest(requestGet);
        std::cout << "Statut du serveur : " << responseGet.getStatus() << std::endl;
        cout << "Les joueurs en ligne pour la partie sont : " << endl;
        std::cout << responseGet.getBody() << std::endl;
        */
    }
    else{}
}
