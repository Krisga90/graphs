#include <iostream>
#include <map>
#include <vector>
#include <string>

#include <sstream>
#include <stdexcept>
#include <stack>

#include "basic.h"

void example();
void example_2();
void example_3();




int main() 
{ 
    example_3();


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

void example_2()
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
}

void example_3()
{
    std::vector<std::vector<char>> edges = {
                                            {'i','j'},
                                            {'j','k'},
                                            {'k','i'},
                                            {'m','k'},
                                            {'k','l'},
                                            {'o','n'}
                                            };
    auto graph = edgesToGraph(edges);
    printGraph(graph);

    std::string answer = hasPath(graph, 'i', 'm') ? "has path\n" : "no path\n";
    std::cout << answer; 
    answer =  hasPath(graph, 'i', 'o') ? "has path\n" : "no path\n";
    std::cout << answer;
}
