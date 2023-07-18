#ifndef BASIC_H
#define BASIC_H

#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <vector>

struct Point {
  Point(int x, int y) : _y(y), _x(x) {}
  Point() : Point(-1, -1) {}
  bool operator<(const Point &other) const {
    if (_y < other._y)
      return true;
    if (_y == other._y && _x < other._x)
      return true;
    return false;
  }

  int _y;
  int _x;
};

void breadthFirst(const std::map<char, std::vector<char>> &graph, char start);
void depthFirstPrint(const std::map<char, std::vector<char>> &graph,
                     char start);

void depthFirstPrintRecursive(const std::map<char, std::vector<char>> &graph,
                              char start);

void depthFirstPrintRecursiveNoExcept(
    const std::map<char, std::vector<char>> &graph, char start) noexcept;

bool hasPath_breadthFirst(std::map<char, std::vector<char>> graph, char start,
                          char dest);
bool hasPath_depthFirstPrintRecursive(
    const std::map<char, std::vector<char>> &graph, char start, char dest);

bool hasPath_throws(std::map<char, std::vector<char>> graph, char start,
                    char dest, std::set<char> &already_in);
bool hasPath(const std::map<char, std::vector<char>> &graph, char start,
             char dest);

int howMAnyGroups(const std::map<int, std::vector<int>> &graph);
void walkAll(const std::map<int, std::vector<int>> &graph,
             std::set<int> &visited_nodes, int start_node);

int largestGroup(const std::map<int, std::vector<int>> &graph);
int walkAllCount(const std::map<int, std::vector<int>> &graph,
                 std::set<int> &visited_nodes, int start_node);

int shortestPath(const std::map<char, std::vector<char>> &graph, char start,
                 char dest);
int pathLength(std::map<char, std::vector<char>> graph, std::set<char> visited,
               char start, char dest);

int countIslands(const std::vector<std::vector<char>> &graph_draw);
bool newIslands(const std::vector<std::vector<char>> &graph_draw,
                std::set<Point> &visited, Point &start,
                const Point &graph_size);

int smallestIsland(const std::vector<std::vector<char>> &graph_draw);
int islandSize_graphic(const std::vector<std::vector<char>> &graph_draw,
                       std::set<Point> &visited, Point &start,
                       const Point &graph_size);

std::map<char, std::vector<char>>
edgesToGraph(const std::vector<std::vector<char>> &edges);
void printGraph(const std::map<char, std::vector<char>> &graph);

#endif // BASIC_H