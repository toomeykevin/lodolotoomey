// Generated by dia2code
#ifndef SERVER__COMMANDSSERVICE__H
#define SERVER__COMMANDSSERVICE__H

#include <json/json.h>

namespace server {
  class AbstractService;
};
namespace engine {
  class Command;
}

#include "HttpStatus.h"
#include "AbstractService.h"
#include "engine/Command.h"

namespace server {

  /// class CommandsService - 
  class CommandsService : public server::AbstractService {
    // Associations
    // Attributes
  private:
    Json::Value& m_ListCommand;
    int m_long;
    // Operations
  public:
    CommandsService (Json::Value& value);
    HttpStatus get (Json::Value& out, int id);
    HttpStatus put (Json::Value& out, const Json::Value& in);
    // Setters and Getters
  };

};

#endif
