/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "ElementTab.h"

using namespace std;

namespace state{
  ElementTab::ElementTab (size_t width, size_t height)
  {
      m_width=width;
      m_height=height;
      for (int i=0;i<(int)(height*width);i++)
      {
          m_board.push_back(NULL);
      }
      //cout<<"la taille du tableau m_board"<<m_board.size()<<endl;
  }
  
  int ElementTab::getSizeVector()
  {
      return m_board.size();
  }
  
  size_t ElementTab::getWidth()
  {
      return m_width;
  }
  
  size_t ElementTab::getHeight ()
  {
      return m_height;
  }
  
  Element* ElementTab::getElement(int i, int j)
  {
      if (i<0 || j<0 || i>=(int)m_height || j>=(int)m_width){
          return NULL;
      }
      else {return m_board[i*m_width+j].get();}
  }
  
  void ElementTab::setElement(int i, int j, Element* e)
  {
      m_board[i*m_width+j] = std::unique_ptr<Element>(e);
  }
  
  void ElementTab::resize (size_t width, size_t height)
  {
      m_board.clear();
      for (int i=0;i<(int)(height*width);i++)
      {
          m_board.push_back(NULL);
      }
      m_width=width;
      m_height=height;
  }
  
  void ElementTab::load (std::string& file)
  {
      throw std::runtime_error("Fonction ElementTab::load pas définie");
  }
  
  Element& ElementTab::operator() (int i, int j)
  {
      return *m_board[i*m_width+j];
  }
  
  void ElementTab::add (Element* e)
  {
      m_board.push_back(std::unique_ptr<Element>(e));
  }
};