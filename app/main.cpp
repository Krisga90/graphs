#include <iostream>
#include <map>
#include <vector>

#include "basic.h"




int main() 
{ 
    std::map<char, std::vector<char>> graph =   {{'a', {'b', 'c'}}
                                                ,{'b', {'d'}}
                                                ,{'c',{'e'}}
                                                ,{'d',{'f'}}
                                                ,{'e', {'j'}}
                                                ,{'f',{}}
                                                };
    depthFirstPrintRecursiveNoExcept(graph, 'a');
    return 0; 
}
