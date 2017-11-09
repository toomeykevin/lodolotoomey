// Generated by dia2code
#ifndef ENGINE__COMMAND__H
#define ENGINE__COMMAND__H


namespace state {
  class State;
}

#include "CommandTypeId.h"
#include "state/State.h"

namespace engine {

  /// class Command - 
  class Command {
    // Attributes
  protected:
    CommandTypeId m_commandTypeId;
    // Operations
  public:
    virtual ~Command ();
    virtual CommandTypeId getTypeId () const;
    virtual void execute (state::State& state);
    // Setters and Getters
  };

};

#endif
