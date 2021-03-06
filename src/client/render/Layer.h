// Generated by dia2code
#ifndef RENDER__LAYER__H
#define RENDER__LAYER__H

#include <memory>
#include <string>
#include <stdlib.h>

namespace render {
  class Surface;
  class TileSet;
}

#include "Surface.h"
#include "TileSet.h"

namespace render {

  /// class Layer - 
  class Layer {
    // Associations
    // Attributes
  protected:
    std::unique_ptr<Surface> m_surface;
    std::shared_ptr<TileSet> m_tileSet;
    // Operations
  public:
    Layer ();
    virtual ~Layer ();
    Surface* getSurface ();
    void setSurface (Surface* surface);
    virtual void initSurface () = 0;
    void printText (int x, int y, std::string& msg, size_t tileMinIndex, size_t tileMaxIndex);
    TileSet* getTileSet ();
    void setTileSet (TileSet* tileSet);
    // Setters and Getters
  };

};

#endif
