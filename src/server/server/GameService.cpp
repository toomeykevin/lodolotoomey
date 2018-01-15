
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"GameService.h"

using namespace std;

namespace server {

    GameService::GameService (UserDB& game) :AbstractService("/game"), m_game(game){
    }
    HttpStatus GameService::get (int id, Json::Value& out) const{
        return HttpStatus::CREATED;
    }
    // Setters and Getters
  
  };
