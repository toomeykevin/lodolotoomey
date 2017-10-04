/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Team.h"

    Team::Team(TeamStatus id){
        teamStatus=id;
    }
    int Team::getNbCreatures(){
        return NbCreatures;
    }
    void Team::setNbCreatures(int nbCreatures=1){
        nbCreatures=nbCreatures;
    }

    TeamStatus Team::getTeamStatus() const{
        return teamStatus;
    }
    TypeId Team::getTypeId() const {
        return typeId;
    }
    bool Team::isStatic() const{
        return True;
    }

