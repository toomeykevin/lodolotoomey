/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Element.h"

using namespace std;

namespace state{
    Element::Element() {}
    
    Element::~Element() {}

    int Element::getx() 
    {
        return m_x;
    }
    
    void Element::setx(int x)
    {
        m_x=x;
    }
    
    int Element::gety() 
    {
        return m_y;
    }
    
    void Element::sety(int y)
    {
        m_y=y;
    }  
};

