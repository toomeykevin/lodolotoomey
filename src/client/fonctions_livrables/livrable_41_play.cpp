/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream> 
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

void livrable_41_play(string commande)
{
    if (commande == "play")
    {
        cout<<"La commande est play"<<endl;
       /* //replay.txt
        // monstream=ifstream(nomfichier)
        //monstream.read(unchar*, longueur de ton stream)
        //lsytream=monstream.tellg()
        //string en jason
        
        Json::Value root;
        Json::Reader reader;
        string line;
        

        ifstream myfile( "/home/kevin/Desktop/test.txt",ios::in );
        if (myfile)
        {
                std::string::size_type n;
                int cpt=0;
                int max=20; // achanger
                getline( myfile, line );

                while (getline( myfile, line ))
                {
                    int n=line.find(":");
                    cout<<n;
                    if (n>=0){
                        switch (cpt){
                            case 0: 
                                root[line.substr( 1, n-1 )] = line.substr(n+1);
                                break;
                            case 1:
                                root[line.substr( 1, n-1 )]=line.substr(n+1);
                                break;
                            case 2: 
                                root[line.substr( 0, n-1 )] = line.substr(n+1);
                                break;
                            case 3:
                                root[line.substr( 0, n-1 )]=line.substr(n+1);
                                break;
                        }      
                    }
                    
                    cpt+=1;
                    if (cpt>max){
                        cpt=0;
                    }
                    
                }
                cout << root<<endl;

            myfile.close();
        }*/
        
        
        
    }
    else{}
}
