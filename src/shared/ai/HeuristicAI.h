// Generated by dia2code
#ifndef AI__HEURISTICAI__H
#define AI__HEURISTICAI__H

#include <random>
#include <vector>
#include <memory>

namespace engine {
  class Engine;
  class Command;
};
namespace state {
  class State;
};
namespace ai {
  class AI;
}

#include "engine/Command.h"
#include "AI.h"

namespace ai {

  /// class HeuristicAI - 
  class HeuristicAI : public ai::AI {
    // Attributes
  private:
    std::mt19937 randgen;
    // Operations
  public:
    void run (engine::Engine& engine);
    int bestCommand (std::vector<std::unique_ptr<engine::Command>>& listOrd, state::State& state);
    HeuristicAI ();
    // Setters and Getters
  };

};

#endif