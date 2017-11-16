/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AI.h"
#include "state/Team.h"
#include "engine/AttackCommand.h"

#include <iostream>
using namespace std;
using namespace ai;
using namespace engine;
using namespace state;

namespace ai{
    void AI::addAroundCommands (vector<unique_ptr<Command>>& list, State& state, int i, int j)
    {
        ElementTab& teamBoard = state.getTeamBoard();
        TeamStatus playerStatus = state.getPlayer();
        Team* tij = (Team*)teamBoard.getElement(i,j);
        
        if (tij->getTeamStatus()==playerStatus && (tij->getNbCreatures()>1))
        {
            // on déclare les cases autour de la case de coordonnées (i,j)
            Team* teamNordEst;
            Team* teamEst;
            Team* teamSudEst;
            Team* teamSudOuest;
            Team* teamOuest;
            Team* teamNordOuest;
            
            // on récupère les tuiles correspondantes à toutes les directions
            // en distinguant si on se situe sur une ligne paire
            if (i%2==0)
            {
                teamNordEst = ((Team*)teamBoard.getElement(i-1,j));
                teamEst = ((Team*)teamBoard.getElement(i,j+1));
                teamSudEst = ((Team*)teamBoard.getElement(i+1,j));
                teamSudOuest = ((Team*)teamBoard.getElement(i+1,j-1));
                teamOuest = ((Team*)teamBoard.getElement(i,j-1));
                teamNordOuest = ((Team*)teamBoard.getElement(i-1,j-1));
            }
            // ou une ligne impaire
            else
            {
                teamNordEst = ((Team*)teamBoard.getElement(i-1,j+1));
                teamEst = ((Team*)teamBoard.getElement(i,j+1));
                teamSudEst = ((Team*)teamBoard.getElement(i+1,j+1));
                teamSudOuest = ((Team*)teamBoard.getElement(i+1,j));
                teamOuest = ((Team*)teamBoard.getElement(i,j-1));
                teamNordOuest = ((Team*)teamBoard.getElement(i-1,j));
            }
            
            AttackCommand* Acommand;
            
            if (teamNordEst != NULL && (teamNordEst->getTeamStatus() != playerStatus) &&
                    (teamNordEst->getNbCreatures() > 0))
            {
                Acommand = new AttackCommand(i,j,teamNordEst->getx(),teamNordEst->gety());
                list.push_back(unique_ptr<Command>((Command*)Acommand)); 
            }
            if (teamEst != NULL && (teamEst->getTeamStatus() != playerStatus) &&
                    (teamEst->getNbCreatures() > 0))
            {
                Acommand = new AttackCommand(i,j,teamEst->getx(),teamEst->gety());
                list.push_back(unique_ptr<Command>((Command*)Acommand)); 
            }
            if (teamSudEst != NULL && (teamSudEst->getTeamStatus() != playerStatus) &&
                    (teamSudEst->getNbCreatures() > 0))
            {
                Acommand = new AttackCommand(i,j,teamSudEst->getx(),teamSudEst->gety());
                list.push_back(unique_ptr<Command>((Command*)Acommand)); 
            }
            if (teamSudOuest != NULL && (teamSudOuest->getTeamStatus() != playerStatus) &&
                    (teamSudOuest->getNbCreatures() > 0))
            {
                Acommand = new AttackCommand(i,j,teamSudOuest->getx(),teamSudOuest->gety());
                list.push_back(unique_ptr<Command>((Command*)Acommand)); 
            }
            if (teamOuest != NULL && (teamOuest->getTeamStatus() != playerStatus) &&
                    (teamOuest->getNbCreatures() > 0))
            {
                Acommand = new AttackCommand(i,j,teamOuest->getx(),teamOuest->gety());
                list.push_back(unique_ptr<Command>((Command*)Acommand)); 
            }
            if (teamNordOuest != NULL && (teamNordOuest->getTeamStatus() != playerStatus) &&
                    (teamNordOuest->getNbCreatures() > 0))
            {
                Acommand = new AttackCommand(i,j,teamNordOuest->getx(),teamNordOuest->gety());
                list.push_back(unique_ptr<Command>((Command*)Acommand)); 
            }
        }
        else{}
    }
    
    void AI::listCommands (vector<unique_ptr<Command>>& list, State& state)
    {
        ElementTab& teamBoard = state.getTeamBoard();
        TeamStatus playerStatus = state.getPlayer();
               
        for (int i=0; i<(int)(teamBoard.getHeight()); i++)
        {
            for (int j=0; j<(int)(teamBoard.getWidth()); j++)
            {
                Element* e = teamBoard.getElement(i,j);
                if (!e || e->isStatic())
                {
                    continue;
                }
                Team* t = (Team*)e;
                if ((t->getTeamStatus()) == playerStatus)
                {
                    if (((Team*)teamBoard.getElement(i,j))->getNbCreatures()>1)
                    {
                        addAroundCommands(list,state,i,j);
                    }
                }
            }
            
        }
    }
    
    void AI::run (Engine& engine) {}
};