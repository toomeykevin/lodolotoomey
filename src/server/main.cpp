/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <string>
#include "server.h"

using namespace std;
using namespace server;

void livrable_41_record(string commande);
void livrable_42_listen(string commande);

int main(int argc,char* argv[]) 
{
    if (argc>1)
    {
        string str(argv[1]); // commande entrée lors de l'execution
        livrable_41_record(str); // Appel à la seule fonction de ce binaire
        livrable_42_listen(str);
        cout<<"Si rien ne s'est affiché, la commande n'est pas valable"<<endl;
    }
    else
    {
        cout<<"Il n'y a pas de commande"<<endl;
    }
    return 0;
}
