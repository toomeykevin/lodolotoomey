// Generated by dia2code
#ifndef ENGINE__INITBASICSTATE__H
#define ENGINE__INITBASICSTATE__H


namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class InitBasicState - 
  class InitBasicState : public engine::Command {
    // Operations
  public:
    InitBasicState ();
    CommandTypeId getTypeId () const;
    void execute (state::State& state);
    // Setters and Getters
  };

};

#endif