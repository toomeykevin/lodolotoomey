// Generated by dia2code
#ifndef STATE__TERRITORY__H
#define STATE__TERRITORY__H


namespace state {
  class Element;
}

#include "TerritoryTypeId.h"
#include "Element.h"

namespace state {

  /// class Territory - 
  class Territory : public state::Element {
    // Associations
    // Attributes
  private:
    TerritoryTypeId const territoryTypeId;
    // Operations
  public:
    TypeId const getTypeId ();
    bool const isStatic ();
    TerritoryTypeId const getTerritoryTypeId ();
    Territory (TerritoryTypeId id = ACCESSABLE);
    // Setters and Getters
  };

};

#endif
