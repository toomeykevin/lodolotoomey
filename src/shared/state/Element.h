// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H


#include "TypeId.h"

namespace state {

  /// class Element - 
  class Element {
    // Associations
    // Attributes
  private:
    TypeId const typeId;
  protected:
    int x;
    int y;
    // Operations
  public:
    Element ();
    ~Element ();
    virtual TypeId const getTypeId () = 0;
    virtual bool const isStatic () = 0;
    // Setters and Getters
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
  };

};

#endif
