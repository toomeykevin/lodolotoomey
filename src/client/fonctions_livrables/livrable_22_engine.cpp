/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "render.h"
#include "state.h"
#include "engine.h"

using namespace sf;
using namespace render;
using namespace state;
using namespace engine;
using namespace std;

void livrable_22_engine(string commande){
    if (commande=="engine"){
        cout<<"la commande est engine"<<endl<<endl;
        srand(time(0));
        
        //Commandes Tests
        cout<<"Debut des Tests sur le moteur"<<endl;
        Engine moteur;
        State& etat=moteur.getState();
                
        int sizeVector=etat.getTeamBoard().getSizeVector();
        cout<<"taille du tableau de tuiles : "<<sizeVector<<endl;
        cout<<"taille du tableau height x width : "<<etat.getTeamBoard().getHeight()<<" x "<<etat.getTeamBoard().getWidth()<< endl;
        
        // initialisation de l'état initial
        cout<<"Mise en place de l'état initial"<<endl<<endl;;
        InitBasicState* initState=new InitBasicState();
        moteur.addCommand((Command*)initState);
        moteur.update();
        
        // Attack de la case 11 contre 12 : 4 Dragons contre 4 Licornes
        cout<<"Attaque de la case 11 contre la case 12"<<endl;
        int nbC11Avant=((Team*)etat.getTeamBoard().getElement(1,1))->getNbCreatures();
        int nbC12Avant=((Team*)etat.getTeamBoard().getElement(1,2))->getNbCreatures();
        TeamStatus teamStatus11Avant=((Team*)etat.getTeamBoard().getElement(1,1))->getTeamStatus();
        TeamStatus teamStatus12Avant=((Team*)etat.getTeamBoard().getElement(1,2))->getTeamStatus();
        TerritoryStatus territoryStatus11Avant=((Territory*)etat.getTerritoryBoard().getElement(1,1))->getTerritoryStatus();
        TerritoryStatus territoryStatus12Avant=((Territory*)etat.getTerritoryBoard().getElement(1,2))->getTerritoryStatus();
        cout<<"Equipes : 1=UNICORNS et 2=DRAGONS"<<endl;
        cout<<"territory : 1=UNICORNS_T et 2=DRAGONS_T et 3=Impossible"<<endl;
        cout<<"case 11 Avant : "<< nbC11Avant<<" Créatures de l'équipe : "<< teamStatus11Avant<<" Sur le territoire : "<<territoryStatus11Avant<<endl;
        cout<<"case 12 Avant : "<< nbC12Avant<<" Créatures de l'équipe : "<< teamStatus12Avant<<" Sur le territoire : "<<territoryStatus12Avant<<endl;
        //debut Attack
        AttackCommand* cmdAtt=new AttackCommand(1,1,1,2); // 1,1 vs 1,2
        moteur.addCommand((Command*)cmdAtt);
        moteur.update();
        //Resultat de l'attack
        cout<<endl<<"Resultat de l'attack"<<endl;
        int nbC11Apres=((Team*)etat.getTeamBoard().getElement(1,1))->getNbCreatures();
        int nbC12Apres=((Team*)etat.getTeamBoard().getElement(1,2))->getNbCreatures();
        TeamStatus teamStatus11Apres=((Team*)etat.getTeamBoard().getElement(1,1))->getTeamStatus();
        TeamStatus teamStatus12Apres=((Team*)etat.getTeamBoard().getElement(1,2))->getTeamStatus();
        TerritoryStatus territoryStatus11Apres=((Territory*)etat.getTerritoryBoard().getElement(1,1))->getTerritoryStatus();
        TerritoryStatus territoryStatus12Apres=((Territory*)etat.getTerritoryBoard().getElement(1,2))->getTerritoryStatus();
        cout<<"Equipes : 1=UNICORNS et 2=DRAGONS"<<endl;
        cout<<"territory : 1=UNICORNS_T et 2=DRAGONS_T et 3=Impossible"<<endl;
        cout<<"case 11 Apres : "<< nbC11Apres<<" Créatures de l'équipe : "<< teamStatus11Apres<<" Sur le territoire : "<<territoryStatus11Apres<<endl;
        cout<<"case 12 Apres : "<< nbC12Apres<<" Créatures de l'équipe : "<< teamStatus12Apres<<" Sur le teriitoire : "<<territoryStatus12Apres<<endl;
        cout<<"Fin de l'attaque"<<endl<<endl;;
        
        //Generation des renforts
        cout<<"Gestion des Renforts"<<endl;
        cout<<"c'est le tour des Dragons donc toutes les cases Dragons recuperent une Creature en plus"<<endl;
        GestionRenforts* gestionRenforts =new GestionRenforts(10); // 1,1 vs 1,2
        moteur.addCommand((Command*)gestionRenforts);
        moteur.update();
        nbC11Apres=((Team*)etat.getTeamBoard().getElement(1,1))->getNbCreatures();
        nbC12Apres=((Team*)etat.getTeamBoard().getElement(1,2))->getNbCreatures();
        teamStatus11Apres=((Team*)etat.getTeamBoard().getElement(1,1))->getTeamStatus();
        teamStatus12Apres=((Team*)etat.getTeamBoard().getElement(1,2))->getTeamStatus();
        territoryStatus11Apres=((Territory*)etat.getTerritoryBoard().getElement(1,1))->getTerritoryStatus();
        territoryStatus12Apres=((Territory*)etat.getTerritoryBoard().getElement(1,2))->getTerritoryStatus();
        cout<<"Equipes : 1=UNICORNS et 2=DRAGONS"<<endl;
        cout<<"territory : 1=UNICORNS_T et 2=DRAGONS_T et 3=Impossible"<<endl;
        cout<<"case 11 Apres : "<< nbC11Apres<<" Créatures de l'équipe : "<< teamStatus11Apres<<" Sur le territoire : "<<territoryStatus11Apres<<endl;
        cout<<"case 12 Apres : "<< nbC12Apres<<" Créatures de l'équipe : "<< teamStatus12Apres<<" Sur le teriitoire : "<<territoryStatus12Apres<<endl;
        cout<<"Fin de la phase renfort"<<endl<<endl;;
        
        cout<<"Fin des Tests sur le moteur"<<endl;

    }
    else{
        
    }
}