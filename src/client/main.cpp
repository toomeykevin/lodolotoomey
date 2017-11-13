#include <iostream>

//#include <SFML/Graphics.hpp>

#include "state.h"
#include "render.h"
#include "engine.h"

using namespace std;
using namespace state;
using namespace render;
void livrable_11_hello(string commande);
void livrable_1final_state(string commande);
void livrable_21_render(string commande);
void livrable_22_engine(string commande);
void livrable_2final_random_ai(string commande);

int main(int argc,char* argv[]) 
{
    if (argc>1){
        string str(argv[1]); // commande entrée lors de l'execution
        livrable_11_hello(str); // Appelle aux fonctions gérant les différents livrables
        livrable_1final_state(str);
        livrable_21_render(str);
        livrable_22_engine(str);
        livrable_2final_random_ai(str);
        cout<<"Si rien ne s'est affiché, la commande n'est pas bonne"<<endl;
        
        
    }
    
    
    else {cout<<"Il n'y a pas de commande"<<endl;}
    

    return 0;
}
