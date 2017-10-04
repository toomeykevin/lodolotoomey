/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Team.h"

namespace state {
    Team::Team(TeamStatus id){
        teamStatus=id;
    }
    
    int Team::getNbCreatures(){
        return nbCreatures;
    }
    
    void Team::setNbCreatures (int nbCreatures){
        nbCreatures=nbCreatures;
    }
    
    TeamStatus Team::getTeamStatus() {
        return teamStatus;
    }
    
};