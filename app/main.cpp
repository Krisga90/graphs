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
void example_4();
void example_5();
void example_6();
void example_7();


int main() 
{ 
    example_7();
    return 0; 
}


void example()
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
    std::vector<std::vector<char>> edges =  {{'i','j'}
                                            ,{'j','k'}
                                            ,{'k','i'}
                                            ,{'m','k'}
                                            ,{'k','l'}
                                            ,{'o','n'}
                                            };
    auto graph = edgesToGraph(edges);
    printGraph(graph);

    std::string answer = hasPath(graph, 'i', 'm') ? "has path\n" : "no path\n";
    std::cout << answer; 
    answer =  hasPath(graph, 'i', 'o') ? "has path\n" : "no path\n";
    std::cout << answer;
}

void example_4()
{
    std::map<int, std::vector<int>> graph = {{0, {8,1,5}}
                                            ,{1, {0}}
                                            ,{5,{0, 8}}
                                            ,{8,{0, 5}}
                                            ,{2, {3, 4}}
                                            ,{3, {2, 4}}
                                            ,{4, {3, 2}}
                                            };

    std::cout << "How Many groups\n" << howMAnyGroups(graph) << "\n";
}

void example_5()
{
    std::map<int, std::vector<int>> graph = {{0, {8,1,5}}
                                            ,{1, {0}}
                                            ,{5,{0, 8}}
                                            ,{8,{0, 5}}
                                            ,{2, {3, 4}}
                                            ,{3, {2, 4}}
                                            ,{4, {3, 2}}
                                            };

    std::cout << "How Many groups\n" << largestGroup(graph) << "\n";
}

void example_6()
{

    std::vector<std::vector<char>> edges =  {{'w','x'}
                                            ,{'x','y'}
                                            ,{'z','y'}
                                            ,{'z','v'}
                                            ,{'w','v'}
                                            };
    auto graph = edgesToGraph(edges);

    std::cout << "shortest path " << shortestPath(graph, 'w', 'z') << std::endl;

    std::vector<std::vector<char>> edges1 = {{'a','c'}
                                            ,{'a','b'}
                                            ,{'c','b'}
                                            ,{'c','d'}
                                            ,{'b','d'}
                                            ,{'e','d'}
                                            ,{'g','f'}
                                            };
    graph = edgesToGraph(edges1);
    // printGraph(graph);
    std::cout << "shortest path " << shortestPath(graph, 'a', 'e') << std::endl;

    std::cout << "shortest path " << shortestPath(graph, 'b', 'g') << std::endl;
}

void example_7()
{
    std::vector<std::vector<char>> graph_draw = {{'w', 'l', 'w', 'l', 'w'}
                                                ,{'w', 'l', 'w', 'w', 'w'}
                                                ,{'w', 'w', 'w', 'l', 'w'}
                                                ,{'w', 'w', 'l', 'l', 'w'}
                                                ,{'l', 'w', 'w', 'l', 'l'}
                                                ,{'l', 'l', 'w', 'w', 'w'}
                                                };
    std::cout << "counted_islands " << countIslands(graph_draw) <<std::endl;

    graph_draw = {{'w', 'l', 'w', 'l', 'w'}};
    std::cout << "counted_islands " << countIslands(graph_draw) <<std::endl;

    graph_draw = {{'w'}};
    std::cout << "counted_islands " << countIslands(graph_draw) <<std::endl;

    graph_draw = {{'l'}};
    std::cout << "counted_islands " << countIslands(graph_draw) <<std::endl;

    graph_draw =    {{'l', 'l'}
                    ,{'l', 'l'}};
    std::cout << "counted_islands " << countIslands(graph_draw) <<std::endl;
}

