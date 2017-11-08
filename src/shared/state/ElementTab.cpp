/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementTab.h"
#include <iostream>
using namespace std;

namespace state{
  ElementTab::ElementTab (size_t width, size_t height)
  {
      m_width=width;
      m_height=height;
      for (int i=0;i<(int)(height*width);i++){
          m_board.push_back(NULL);
      }
      //cout<<"la taille du tableau m_board"<<m_board.size()<<endl;
      
  }
 
  size_t ElementTab::getWidth()
  {
      return m_width;
  }
  
  size_t ElementTab::getHeight ()
  {
      return m_height;
  }
  
  Element* ElementTab::getElement(int i, int j){
      return m_board[i*m_width+j].get();
  }
  
  void ElementTab::setElement(int i, int j,Element* e){
      m_board[i*m_width+j]=std::unique_ptr<Element>(e);
  }
  
  void ElementTab::resize (size_t width, size_t height){ // peut poser probleme
      m_width=width;
      m_height=height;
  }
  
  void ElementTab::load (std::string& file){
      
  }
  
  Element& ElementTab::operator() (int i, int j){
      
      return *m_board[i*m_width+j];
  }
  
  void ElementTab::add (Element* e){
      m_board.push_back(std::unique_ptr<Element>(e));
  }
};