#include <iostream>

//#include <SFML/Graphics.hpp>

#include "state.h"

using namespace std;
using namespace state;
void livrable_11_hello(string commande);
void livrable_1final_state(string commande);
void livrable_21_render(string commande);

int main(int argc,char* argv[]) 
{
    if (argc>1){
        string str(argv[1]); // commande entrée lors de l'execution
        livrable_11_hello(str); // Appelle aux fonctions gérant les différents livrables
        livrable_1final_state(str);
        livrable_21_render(str);
        cout<<"Si rien ne s'est affiché, la commande n'est pas bonne"<<endl;
    }
    else {cout<<"Il n'y a pas de commande"<<endl;}
    

    return 0;
}
