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
#include "server.h"

using namespace std;
using namespace sf;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;
using namespace server;

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
        // Ce joueur s'appelle Roger
        Json::Value data;
        cout << "Entrez votre pseudo" << endl;
        string pseudo;
        cin >> pseudo;
        data["name"]=pseudo;
        requestPut.setBody(data.toStyledString());
        // On envoie la requête au serveur
        sf::Http::Response responsePut = http.sendRequest(requestPut);
        cout << "-- Requête PUT --" << endl;
        cout << "Statut du serveur : " << responsePut.getStatus() << endl;
        cout << "Réponse du serveur : \n" << responsePut.getBody() << endl;
        
        
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
