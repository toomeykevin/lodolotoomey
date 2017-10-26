/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NumberTileSet.h"
#include <iostream>
#include "state/Team.h"

using namespace std;
using namespace state;


namespace render{
    NumberTileSet::NumberTileSet (){
        vector<Tile> m_numbers(8);
    }
    
    int NumberTileSet::getCellWidth (){
        return 12;    
    }
    
    int NumberTileSet::getCellHeight (){
        return 12;
    }
    
    std::string NumberTileSet::getImageFile (){
        return "res/textures_bulles.png";
    }
    
    Tile& NumberTileSet::getCharTile (char c){
        if (c == '1')
        {
            // on renvoit la bulle avec le numéro 1
            return m_numbers[0];
        }
        if (c == '2')
        {
            // on renvoit la bulle avec le numéro 2
            return m_numbers[1];
        }
        if (c == '3')
        {
            // on renvoit la bulle avec le numéro 3
            return m_numbers[2];
        }
        if (c == '4')
        {
            // on renvoit la bulle avec le numéro 4
            return m_numbers[3];
        }
        if (c == '5')
        {
            // on renvoit la bulle avec le numéro 5
            return m_numbers[4];
        }
        if (c == '6')
        {
            // on renvoit la bulle avec le numéro 6
            return m_numbers[5];
        }
        if (c == '7')
        {
            // on renvoit la bulle avec le numéro 7
            return m_numbers[6];
        }
        if (c == '8')
        {
            // on renvoit la bulle avec le numéro 8
            return m_numbers[7];
        }
        else
        {
            throw std::runtime_error("Impossible d'avoir une armée de cette taille");
        }
    }
};