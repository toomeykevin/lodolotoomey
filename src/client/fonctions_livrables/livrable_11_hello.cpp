/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

using namespace std;
using namespace sf;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;


void livrable_11_hello(string commande)
{
    if (commande == "hello")
    {
        cout<<"Hello World"<<endl;
    }
    else{}
}
