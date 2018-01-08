// Generated by dia2code
#ifndef ENGINE__INITBASICSTATE__H
#define ENGINE__INITBASICSTATE__H

#include <stack>
#include <memory>
#include <json/json.h>

namespace state {
  class State;
};
namespace engine {
  class Action;
  class InitBasicState;
  class Command;
}

#include "CommandTypeId.h"
#include "Action.h"
#include "Command.h"

namespace engine {

  /// class InitBasicState - 
  class InitBasicState : public engine::Command {
    // Operations
  public:
    InitBasicState ();
    CommandTypeId getTypeId () const;
    void execute (state::State& state, std::stack<std::shared_ptr<Action>>& actions);
    void serialize (Json::Value& out);
    static InitBasicState* deserialize (Json::Value& in);
    // Setters and Getters
  };

};

#endif
