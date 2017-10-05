// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H


namespace state {

  /// class Element - 
  class Element {
    // Attributes
  protected:
    int m_x;
    int m_y;
    // Operations
  public:
    Element ();
    ~Element ();
    virtual bool isStatic () = 0;
    // Setters and Getters
    int getM_x() const;
    void setM_x(int m_x);
    int getM_y() const;
    void setM_y(int m_y);
  };

};

#endif