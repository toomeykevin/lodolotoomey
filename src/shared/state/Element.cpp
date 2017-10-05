/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Element.h"
#include <iostream>
using namespace std;

namespace state{
    Element::Element() {}
    
    Element::~Element() {}

    int Element::getM_x() const
    {
        return m_x;
    }
    
    void Element::setM_x(int x)
    {
        m_x=x;
    }
    
    int Element::getM_y() const
    {
        return m_y;
    }
    
    void Element::setM_y(int y)
    {
        m_y=y;
    }  
};

