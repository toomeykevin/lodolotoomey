// Generated by dia2code
#ifndef ENGINE__GESTIONRENFORTS__H
#define ENGINE__GESTIONRENFORTS__H

#include <stack>
#include <memory>
#include <json/json.h>

namespace state {
  class State;
};
namespace engine {
  class Action;
  class GestionRenforts;
  class Command;
  class RenfortsAction;
}

#include "CommandTypeId.h"
#include "Action.h"
#include "Command.h"
#include "RenfortsAction.h"

namespace engine {

  /// class GestionRenforts - 
  class GestionRenforts : public engine::Command {
    // Attributes
  protected:
    int m_renforts;
    // Operations
  public:
    GestionRenforts (int i);
    CommandTypeId getTypeId () const;
    int getRenforts ();
    void setRenforts (int renforts);
    void execute (state::State& state, std::stack<std::shared_ptr<Action>>& actions);
    void serialize (Json::Value& out);
    static GestionRenforts* deserialize (Json::Value& in);
    // Setters and Getters
  };

};

#endif
