// Generated by dia2code
#ifndef STATE__ELEMENTTAB__H
#define STATE__ELEMENTTAB__H

#include <vector>
#include <memory>
#include <stdlib.h>

namespace state {
  class Element;
}

#include "Element.h"

namespace state {

  /// class ElementTab - 
  class ElementTab {
    // Associations
    // Attributes
  private:
    std::vector<std::unique_ptr<Element>> m_board;
    size_t m_width;
    size_t m_height;
    // Operations
  public:
    ElementTab (size_t width = 5, size_t height = 5);
    size_t getWidth ();
    size_t getHeight ();
    // Setters and Getters
  };

};

#endif
