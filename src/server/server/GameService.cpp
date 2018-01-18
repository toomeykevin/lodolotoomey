
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"GameService.h"

using namespace std;

namespace server {

    GameService::GameService (UserDB& game) :AbstractService("/game"), m_game(game) {}
    
    HttpStatus GameService::get (Json::Value& out, int id) const
    {
        const User* user = m_game.getUser(id);
        if (!user)
        {
            out["Game started"] = false;
            return HttpStatus::NO_CONTENT;
        }
        else
        {
            out["Game started"] = true;
            return HttpStatus::CREATED;
        }
    }
  
  };
