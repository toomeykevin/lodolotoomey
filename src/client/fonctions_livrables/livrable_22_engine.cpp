/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "state.h"
#include "render.h"
#include "engine.h"

using namespace std;
using namespace sf;
using namespace state;
using namespace render;
using namespace engine;

void livrable_22_engine(string commande)
{
    if (commande == "engine")
    {
        srand(time(0));

        //Commandes tests
        cout<<"Début des tests moteur"<<endl;
        Engine moteur;
        State& etat = moteur.getState();
        
        int sizeVector = etat.getTeamBoard().getSizeVector();
        cout<<"   Nombre de cases de la map : "<<sizeVector<<endl;
        cout<<"   Taille du tableau : "<<etat.getTeamBoard().getHeight()<<" x "<<etat.getTeamBoard().getWidth()<< endl;
          
        // initialisation de l'état initial
        cout<<"   Mise en place de l'état initial"<<endl;
        InitBasicState* initState = new InitBasicState();
        moteur.addCommand((Command*)initState);
        moteur.update();
        
        ElementTabLayer Layer1(moteur.getState().getTerritoryBoard());
        ElementTabLayer Layer2(moteur.getState().getTeamBoard());
        StateLayer Layer3(moteur.getState());
        
        cout<<endl<<"Appuyez sur la touche Entrée pour lancer l'attaque"<<endl<<endl;
        
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

            if(Keyboard::isKeyPressed(Keyboard::Return))
            {
                cout<<"Fermez la fenêtre pour quitter"<<endl;
                cout<<"Appuyez sur la touche Entrée pour continuer"<<endl;
                    
                // attaque de la case (1,1) contre (2,1) : 4 dragons contre 4 licornes
                cout<<"   Début de l'attaque"<<endl;
                cout<<"      Attaque de la case (1,1) contre la case (1,2)"<<endl;

                // stockage du nb de créatures des deux cases avant l'attaque
                int nbC11Avant =
                        ((Team*)etat.getTeamBoard().getElement(1,1))->getNbCreatures();
                int nbC21Avant =
                        ((Team*)etat.getTeamBoard().getElement(1,2))->getNbCreatures();
                // stockage des teamStatus et territoryStatus des deux cases avant l'attaque
                TeamStatus teamStatus11Avant =
                        ((Team*)etat.getTeamBoard().getElement(1,1))->getTeamStatus();
                TeamStatus teamStatus21Avant =
                        ((Team*)etat.getTeamBoard().getElement(1,2))->getTeamStatus();
                TerritoryStatus territoryStatus11Avant =
                        ((Territory*)etat.getTerritoryBoard().getElement(1,1))->getTerritoryStatus();
                TerritoryStatus territoryStatus21Avant =
                        ((Territory*)etat.getTerritoryBoard().getElement(1,2))->getTerritoryStatus();

                cout<<"      Team : 1=licornes et 2=dragons"<<endl;
                cout<<"      Territory : 1=licornes et 2=dragons et 3=inaccessible"<<endl;
                cout<<"      Case (1,1) avant attaque : "<< nbC11Avant<<" créatures de l'équipe "
                        <<teamStatus11Avant<<" sur un territoire de type "<<territoryStatus11Avant<<endl;
                cout<<"      Case (1,2) avant attaque : "<< nbC21Avant<<" créatures de l'équipe "
                        <<teamStatus21Avant<<" sur un territoire de type "<<territoryStatus21Avant<<endl;
                cout<<"  Fin de l'initialisation ... début de l'attaque"<<endl;
                cout<<"  Résultat de l'attaque dans 5s"<<endl<<endl;
                
                sleep(milliseconds(5000));
                
                // attaque
                AttackCommand* cmdAtt = new AttackCommand(1,1,1,2); // (1,1) vs (1,2)
                moteur.addCommand((Command*)cmdAtt);
                moteur.update();

                // résultat de l'attaque
                cout<<"   Résultat de l'attaque"<<endl;

                int nbC11Apres =
                        ((Team*)etat.getTeamBoard().getElement(1,1))->getNbCreatures();
                int nbC21Apres =
                        ((Team*)etat.getTeamBoard().getElement(1,2))->getNbCreatures();
                TeamStatus teamStatus11Apres =
                        ((Team*)etat.getTeamBoard().getElement(1,1))->getTeamStatus();
                TeamStatus teamStatus21Apres =
                        ((Team*)etat.getTeamBoard().getElement(1,2))->getTeamStatus();
                TerritoryStatus territoryStatus11Apres =
                        ((Territory*)etat.getTerritoryBoard().getElement(1,1))->getTerritoryStatus();
                TerritoryStatus territoryStatus21Apres =
                        ((Territory*)etat.getTerritoryBoard().getElement(1,2))->getTerritoryStatus();

                cout<<"      Team : 1=licornes et 2=dragons"<<endl;
                cout<<"      Territory : 1=licornes et 2=dragons et 3=inaccessible"<<endl;
                cout<<"      Case (1,1) après attaque : "<< nbC11Apres<<" créatures de l'équipe "
                        <<teamStatus11Apres<<" sur un territoire du type "<<territoryStatus11Apres<<endl;
                cout<<"      Case (1,2) après attaque : "<< nbC21Apres<<" créatures de l'équipe "
                        <<teamStatus21Apres<<" sur un territoire du type "<<territoryStatus21Apres<<endl;
                cout<<"   Fin de l'attaque"<<endl<<endl;
                
                // gestion des renforts
                GestionRenforts* gestionRenforts = new GestionRenforts(10); // 1,1 vs 1,2
                moteur.addCommand((Command*)gestionRenforts);
                moteur.update();

                // génération des renforts
                cout<<"   Gestion des renforts"<<endl;
                cout<<"      C'est le tour des dragons donc toutes les cases occupées par des dragons"<<
                        " ont droit chacune à 1 dragon en renfort"<<endl;

                nbC11Apres =
                        ((Team*)etat.getTeamBoard().getElement(1,1))->getNbCreatures();
                nbC21Apres =
                        ((Team*)etat.getTeamBoard().getElement(1,2))->getNbCreatures();
                teamStatus11Apres =
                        ((Team*)etat.getTeamBoard().getElement(1,1))->getTeamStatus();
                teamStatus21Apres =
                        ((Team*)etat.getTeamBoard().getElement(1,2))->getTeamStatus();
                territoryStatus11Apres =
                        ((Territory*)etat.getTerritoryBoard().getElement(1,1))->getTerritoryStatus();
                territoryStatus21Apres =
                        ((Territory*)etat.getTerritoryBoard().getElement(1,2))->getTerritoryStatus();

                cout<<"      Team : 1=licornes et 2=dragons"<<endl;
                cout<<"      Territory : 1=licornes et 2=dragons et 3=inaccessible"<<endl;
                cout<<"      Case (1,1) après renforts : "<< nbC11Apres<<" créatures de l'équipe "
                        <<teamStatus11Apres<<" sur un territoire de type "<<territoryStatus11Apres<<endl;
                cout<<"      Case (1,2) après renforts : "<< nbC21Apres<<" créatures de l'équipe "
                        <<teamStatus21Apres<<" sur un territoire de type "<<territoryStatus21Apres<<endl;
                cout<<"   Fin de la gestion des renforts"<<endl;
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
        }
        cout<<endl<<"Fin des tests moteur"<<endl;
    }
    else{}
}