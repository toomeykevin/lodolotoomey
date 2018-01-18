// Generated by dia2code
#ifndef CLIENT__SUPERENGINE__H
#define CLIENT__SUPERENGINE__H


namespace engine {
  class Command;
  class Engine;
}

#include "engine/Engine.h"

namespace client {

  /// class SuperEngine - 
  class SuperEngine : public engine::Engine {
    // Operations
  public:
    SuperEngine ();
    void addCommand (engine::Command* cmd);
    // Setters and Getters
  };

};

#endif
