// Generated by dia2code
#ifndef RENDER__STATELAYER__H
#define RENDER__STATELAYER__H


namespace state {
  class State;
};
namespace render {
  class Layer;
}

#include "Layer.h"
#include "state/State.h"

namespace render {

  /// class StateLayer - 
  class StateLayer : public render::Layer {
    // Associations
    // Attributes
  private:
    state::State& m_state;
    // Operations
  public:
    StateLayer (state::State& state);
    void initSurface ();
    // Setters and Getters
  };

};

#endif