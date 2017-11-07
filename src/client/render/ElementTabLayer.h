// Generated by dia2code
#ifndef RENDER__ELEMENTTABLAYER__H
#define RENDER__ELEMENTTABLAYER__H


namespace state {
  class ElementTab;
};
namespace render {
  class Layer;
}

#include "Layer.h"
#include "state/ElementTab.h"

namespace render {

  /// class ElementTabLayer - 
  class ElementTabLayer : public render::Layer {
    // Associations
    // Attributes
  private:
    state::ElementTab& m_tab;
    // Operations
  public:
    ElementTabLayer (state::ElementTab& tab);
    void initSurface ();
    // Setters and Getters
  };

};

#endif