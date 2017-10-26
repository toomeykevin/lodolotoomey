#include <iostream>

//#include <SFML/Graphics.hpp>

#include "state.h"
#include "render.h"

using namespace std;
using namespace state;
using namespace render;
void livrable_11_hello(string commande);
void livrable_1final_state(string commande);
void livrable_21_render(string commande);

int main(int argc,char* argv[]) 
{
    if (argc>1){
        string str(argv[1]); // commande entrée lors de l'execution
        livrable_11_hello(str); // Appelle aux fonctions gérant les différents livrables
        livrable_1final_state(str);
        livrable_21_render(str);
        cout<<"Si rien ne s'est affiché, la commande n'est pas bonne"<<endl;
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
    }
    else {cout<<"Il n'y a pas de commande"<<endl;}
    

    return 0;
}
