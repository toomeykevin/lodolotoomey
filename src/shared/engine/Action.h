// Generated by dia2code
#ifndef ENGINE__ACTION__H
#define ENGINE__ACTION__H


namespace state {
  class State;
}

#include "ActionTypeId.h"
#include "state/State.h"

namespace engine {

  /// class Action - 
  class Action {
    // Attributes
  protected:
    ActionTypeId m_actionTypeId;
    // Operations
  public:
    virtual ~Action ();
    virtual void apply (state::State& state) = 0;
    virtual void undo (state::State& state) = 0;
    virtual ActionTypeId getTypeId () const;
    // Setters and Getters
  };

};

#endif
