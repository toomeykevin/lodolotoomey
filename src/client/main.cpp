#include <iostream>
#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

using namespace std;
using namespace state;
using namespace render;

void livrable_11_hello(string commande);
void livrable_1final_state(string commande);
void livrable_21_render(string commande);
void livrable_22_engine(string commande);
void livrable_2final_random_ai(string commande);
void livrable_31_heuristic_ai(string commande);
void livrable_3final_deep_ai(string commande);
void livrable_3final_rollback(string commande);
void livrable_41_thread(string commande);
void livrable_41_play(string commande);

int main(int argc,char* argv[]) 
{
    if (argc>1)
    {
        string str(argv[1]); // commande entrée lors de l'execution
        livrable_11_hello(str); // Appel aux fonctions des différents livrables
        livrable_1final_state(str);
        livrable_21_render(str);
        livrable_22_engine(str);
        livrable_2final_random_ai(str);
        livrable_31_heuristic_ai(str);
        livrable_3final_rollback(str);
        livrable_3final_deep_ai(str);
        livrable_41_thread(str);
        livrable_41_play(str);
        cout<<"Si rien ne s'est affiché, la commande n'est pas valable"<<endl;
    }
    else
    {
        cout<<"Il n'y a pas de commande"<<endl;
    }
    return 0;
}
