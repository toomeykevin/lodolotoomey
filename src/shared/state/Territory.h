// Generated by dia2code
#ifndef STATE__TERRITORY__H
#define STATE__TERRITORY__H


namespace state {
  class Element;
}

#include "TerritoryStatus.h"
#include "Element.h"

namespace state {

  /// class Territory - 
  class Territory : public state::Element {
    // Associations
    // Attributes
  private:
    TerritoryStatus m_territoryStatus;
    // Operations
  public:
    Territory (TerritoryStatus territoryStatus = IMPOSSIBLE);
    TerritoryStatus getTerritoryStatus ();
    bool isStatic ();
    // Setters and Getters
  };

};

#endif
