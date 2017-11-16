/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "state.h"

using namespace std;
using namespace state;

void livrable_1final_state(string commande)
{
    if (commande == "state")
    {
        bool test = true;
        cout <<"Début des tests"<< endl;
        Team team1;
        Team team2;
        team2.setNbCreatures(5);
        Territory* territoryI= new Territory(IMPOSSIBLE);
        Territory* territoryD=new Territory(DRAGONS_T);

        //Class Team Test
        if(team1.getNbCreatures()==1)
        {
            cout<<"Team::getNbCreatures() works"<<endl;
        }
        else
        {
            test = false;
            cout<<"Team::getCreatures() failed"<<endl;
        }
        
        if(team2.getNbCreatures() == 5)
        {

            cout<<"Team::setNbCreatures(int) works"<<endl;
        }
        else
        {
            test = false;
            cout<<"Team::setNbCreatures(int) failed"<<endl;

        }
        
        // Class Territory Test
        if(territoryI->getTerritoryStatus() == IMPOSSIBLE)
        {
            cout<<"Team::Team(teamStatus) works"<<endl;
        }
        else
        {
            test = false; 
            cout<<"Team::Team(TeamStatus) failed"<<endl;
        }
        
        if(territoryD->getTerritoryStatus() == DRAGONS_T)
        {
            cout<<"Team::getTeamStatus() works"<<endl;
        }
        else
        {
            test = false;  
            cout<<"Team::getTeamStatus() failed"<<endl;
        }
        
       cout<<test<<endl;
       
       if (test==true)
       {
           cout<<"Test worked"<<endl;
       }
       else
       {
           cout<<"Test failed"<<endl;

       }
       
       cout <<"Fin des tests"<<endl;
    }
    else{}
}

