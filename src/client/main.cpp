#include <iostream>

//#include <SFML/Graphics.hpp>


#include "state.h"

using namespace std;
using namespace state;

int main(int argc,char* argv[]) 
{

    if (argc>1){
        string str(argv[1]);
        if (str=="state")
        {
            bool test= false;
            cout <<"Debut des tests"<<endl;
            Team team1; //new Team(TeamStatus::UNICORNS);
            Team team2;
            team2.setNbCreatures(5);
            team2.getTypeId();
            Territory* territoryI= new Territory(IMPOSSIBLE);
            Territory territoryA;
            //cout<<territoryI->getTerritoryStatus()<<endl;
            
            //Class Team Test
            if(team1.getNbCreatures()==1){
                test=true;
                cout<<"Team::getNbCreatures() works"<<endl;
            }
            else {
                test= false;
                cout<<"Team::getCreatures() failed"<<endl;
                
            }
            if(team2.getNbCreatures()==5){
                test=true; 
                cout<<"Team::setNbCreatures(int) works"<<endl;
            }
            else {
                test= false;
                cout<<"Team::setNbCreatures(int) failed"<<endl;
                
            }
            // Class Territory Test
            if(territoryI->getTerritoryStatus()==2){
                test=true; 
                cout<<"Team::Team(teamStatus) works"<<endl;
            }
            else {
                test= false; 
                cout<<"Team::Team(TeamStatus) failed"<<endl;
            }
            if(territoryA.getTerritoryStatus()==1){
                test=true;
                cout<<"Team::getTeamStatus() works"<<endl;
            }
            else {
                test= false;  
                cout<<"Team::getTeamStatus() failed"<<endl;
            }
           cout<<test<<endl;
           // team->getNbCreatures();            
                   
                    
            cout <<"Fin des tests"<<endl;
        }
        else{cout<<"La commande n'est pas correcte"<<endl;}
    }
    else {cout<<"Il n'y a pas de commande"<<endl;}
    

    return 0;
}
