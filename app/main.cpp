#include <iostream>
#include <map>
#include <vector>
#include <string>

#include <sstream>
#include <stdexcept>
#include <stack>

#include "basic.h"

void example();


int main() 
{ 
    std::map<char, std::vector<char>> graph =   {{'a', {'b', 'c'}}
                                                ,{'b', {'d'}}
                                                ,{'c',{'e'}}
                                                ,{'d',{}}
                                                ,{'e', {}}
                                                ,{'f',{}}
                                                };

    std::string answer = hasPath_breadthFirst(graph, 'a', 'f') ? "has path\n" : "no path\n";
    std::cout << answer; 
    answer = hasPath_depthFirstPrintRecursive(graph, 'a', 'f') ? "has path\n" : "no path\n";
    std::cout << answer; 

    return 0; 
}

void example()
{
    {
    std::map<char, std::vector<char>> graph =   {{'a', {'b', 'c'}}
                                                ,{'b', {'d'}}
                                                ,{'c',{'e'}}
                                                ,{'d',{'f'}}
                                                ,{'e', {'j'}}
                                                ,{'f',{}}
                                                };
    depthFirstPrintRecursiveNoExcept(graph, 'a');
    }
}

