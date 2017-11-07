// Generated by dia2code
#ifndef ENGINE__ATTACKCOMMAND__H
#define ENGINE__ATTACKCOMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class AttackCommand - 
  class AttackCommand : public engine::Command {
    // Attributes
  private:
    int m_iAtt;
    int m_jAtt;
    int m_iDef;
    int m_jDef;
    // Operations
  public:
    AttackCommand (int iAtt, int jAtt, int iDef, int jDef);
    CommandTypeId getTypeId () const;
    void execute (state::State& state);
    void attackWins (state::State& state);
    void attackLooses (state::State& state);
    int getIAtt ();
    void setIAtt (int iAtt);
    int getJAtt ();
    void setJAtt (int jAtt);
    int getIDef ();
    void setIDef (int iDef);
    int getJDef ();
    void setJDef (int jDef);
    // Setters and Getters
  };

};

#endif