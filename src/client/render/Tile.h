// Generated by dia2code
#ifndef RENDER__TILE__H
#define RENDER__TILE__H


namespace render {

  /// class Tile - 
  class Tile {
    // Attributes
  protected:
    int x     = 0;
    int y     = 0;
    int m_width;
    int m_height;
    // Operations
  public:
    Tile ();
    Tile (int x, int y, int w, int h);
    // Setters and Getters
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    int getM_width() const;
    void setM_width(int m_width);
    int getM_height() const;
    void setM_height(int m_height);
  };

};

#endif
