#include <iostream>

//#include <SFML/Graphics.hpp>


#include "state.h"

using namespace std;
using namespace state;

int main(int argc,char* argv[]) 
{
    Exemple exemple;
    exemple.setX(53);

    if (argc>1){
        string str(argv[1]);
        if (str=="state")
        {
            cout <<"Debut des tests"<<endl;
            Element element;
            
            
                   
                    
            cout <<"Fin des tests"<<endl;
        }
        else{cout<<"La commande n'est pas correct"<<endl;}
    }
    else {cout<<"Il n'y a pas de commande"<<endl;}
    

    return 0;
}
