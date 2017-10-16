#include <iostream>

//#include <SFML/Graphics.hpp>

#include "state.h"

using namespace std;
using namespace state;
void livrable_11_hello(string commande);
void livrable_1final_state(string commande);

int main(int argc,char* argv[]) 
{
    if (argc>1){
        string str(argv[1]);
        livrable_11_hello(str);
        livrable_1final_state(str);
        if (str=="render")
        {
           cout<<"La commande est render"<<endl;
        }
        else{cout<<"La commande n'est pas render"<<endl;}
    }
    else {cout<<"Il n'y a pas de commande"<<endl;}
    

    return 0;
}
