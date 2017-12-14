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
        
        
        Json::Reader reader;
        string line;

        ifstream record( "replay.txt",ios::in );
        if (record)
        {
            //reader.parse(record,obj);
            //cout << obj["commande"].asInt() << endl;
            
            std::string::size_type n;
            int cpt=0;
            int max=20; // à changer
            getline(record,line);

            while (getline(record,line))
            {
                Json::Value obj;
                reader.parse(record,obj);
                cout << obj.toStyledString() << endl;
                /*int n = line.find(":");
                //cout<<n;
                if (n>=0)
                {
                    switch (cpt)
                    {
                        case 0: 
                            obj[line.substr( 1, n-1 )] = line.substr(n+1);
                            break;
                        case 1:
                            obj[line.substr( 1, n-1 )]=line.substr(n+1);
                            break;
                        case 2: 
                            obj[line.substr( 0, n-1 )] = line.substr(n+1);
                            break;
                        case 3:
                            obj[line.substr( 0, n-1 )]=line.substr(n+1);
                            break;
                    }      
                }*/
                cpt+=1;
                if (cpt>max){
                    cpt=0;
                }
            }
            //cout << obj <<endl;
            record.close();
        }
        
        
        
    }
    else{}
}
