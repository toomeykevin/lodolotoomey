/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "render.h"
#include "state.h"
//#include "render/TeamTileSet.h"
//#include "render/NumberTileSet.h"

using namespace sf;
using namespace render;
using namespace state;
using namespace std;

void livrable_21_render(std::string commande){
    if (commande=="render"){
        std::cout<<"la commande est render"<<std::endl;

        // Création d'un état
        State etat;
        ElementTab& territory = etat.getTerritoryBoard();
        ElementTab& team = etat.getTeamBoard();
        
        // On resize pour avoir une grille 4x4
        territory.resize(2,2);
        team.resize(2,2);
        
        // On construit le TerritoryBoard
        Territory* t00 = new Territory(DRAGONS_T);
        Territory* t01 = new Territory(UNICORNS_T);
        Territory* t10 = new Territory(IMPOSSIBLE);
        Territory* t11 = new Territory(DRAGONS_T);
        
        territory.setElement(0,0,t00);
        territory.setElement(0,1,t01);
        territory.setElement(1,0,t10);
        territory.setElement(1,1,t11);
        
        // On construit le TeamBoard
        Team* e00 = new Team(8,DRAGONS);
        Team* e01 = new Team(3,UNICORNS);
        Team* e10 = new Team(0,NONE);
        Team* e11 = new Team(1,DRAGONS);
        
        team.setElement(0,0,e00);
        team.setElement(0,1,e01);
        team.setElement(1,0,e10);
        team.setElement(1,1,e11);
        
        /*cout<<t00->getTerritoryStatus()<<endl;
        cout<<t01->getTerritoryStatus()<<endl;
        cout<<t10->getTerritoryStatus()<<endl;
        cout<<t11->getTerritoryStatus()<<endl;
        
        cout<<((Territory*)territory.getElement(0,0))->getTerritoryStatus()<<endl;
        cout<<((Territory*)territory.getElement(0,1))->getTerritoryStatus()<<endl;
        cout<<((Territory*)territory.getElement(1,0))->getTerritoryStatus()<<endl;
        cout<<((Territory*)territory.getElement(1,1))->getTerritoryStatus()<<endl;*/

        // on crée une couche à partir de l'ElementTabLayer qu'on a construit
        ElementTabLayer Layer1(etat.getTerritoryBoard());
        ElementTabLayer Layer2(etat.getTeamBoard());
        StateLayer Layer3(etat);
        
        /*//Création de l'état au hasard
        State etat;
        int Etat_Width=etat.getTeamBoard().getWidth();
        int Etat_Height=etat.getTeamBoard().getHeight();
        Team* team11=new Team(10);
        etat.getTeamBoard().setElement(1,1,team11);
        cout<<"taille du tableau "<<etat.getTeamBoard().getWidth()<< endl;
        cout<<"nombre de Dragons"<<((Team*)(etat.getTeamBoard().getElement(1,1)))->getNbCreatures()<<endl;
        srand(time(0));
        cout<<"rand 1 ou 2 :"<<(rand() %2) +1<<endl;
        srand(time(0));
        cout<<"rand 100 : "<<(rand() %100) <<endl;
        for (int i=0;i<Etat_Width;i++){
            for (int j=0;j<Etat_Height;j++){
                srand(time(0));
                int rand1=(rand() %8) +1;
                srand(time(0));
                int rand2=(rand() %10) +1;
                TeamStatus teamStatus;
                TerritoryStatus territoryStatus;
                if (rand1<=4){
                    teamStatus=UNICORNS;
                }
                else{
                    teamStatus=DRAGONS;
                }
                if (rand2<=2){
                    territoryStatus=IMPOSSIBLE;
                }
                else if(rand2<=6){
                    territoryStatus=DRAGONS_T;
                }
                else{
                    territoryStatus=UNICORNS_T;
                }
                
                Team* team=new Team(rand1,teamStatus);
                Territory* territory=new Territory(territoryStatus);
                etat.getTeamBoard().setElement(i,j,team);
                etat.getTerritoryBoard().setElement(i,j,territory);
       
            }
        }
        
        StateLayer Layer1(etat);*/
        
        // ouverture de la page du jeu
        RenderWindow window(VideoMode(800,600,32),"Risk Fantasy | Unicorns VS Dragons", Style::Close | Style::Titlebar);
        
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
        }
        
    }
    else{
        //cout<< "la commande n'est pas render"<< endl; 
    }
}