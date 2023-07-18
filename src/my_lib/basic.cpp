#include "basic.h"

#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <vector>

void breadthFirst(const std::map<char, std::vector<char>> &graph, char start) {
  std::queue<char> graph_que;
  graph_que.push(start);
  std::vector<char> graph_path_order;

  while (true) {
    char current_node = graph_que.front();
    graph_que.pop();
    // because of at we can change this if to try/catch
    if (graph.count(current_node)) {
      graph_path_order.push_back(current_node);
      // don't know why operator[] is not working :/
      const std::vector<char> &neighbors = graph.at(current_node);

      for (char neighbour : neighbors) {
        graph_que.push(neighbour);
      }
    } else {
      std::cerr << "No " << current_node << " node in graph\n";
      break;
    }
    if (graph_que.empty()) {
      break;
    }
  }

  std::cout << "breadth search path:\n";
  for (char neighbour : graph_path_order) {
    std::cout << (neighbour) << ", ";
  }
  std::cout << std::endl;
}

void depthFirstPrint(const std::map<char, std::vector<char>> &graph,
                     char start) {
  std::stack<char> graph_stack;
  graph_stack.push(start);
  std::vector<char> graph_path_order;

  while (true) {
    char current_node = graph_stack.top();
    graph_stack.pop();
    // because of at we can change this if to try/catch
    if (graph.count(current_node)) {
      graph_path_order.push_back(current_node);
      const std::vector<char> &neighbors =
          graph.at(current_node); // don't know why operator[] is not working :/
      for (char neighbour : neighbors) {
        graph_stack.push(neighbour);
      }
    } else {
      std::cerr << "No " << current_node << " node in graph\n";
      break;
    }
    if (graph_stack.empty()) {
      break;
    }
  }

  std::cout << "depth search path:\n";
  for (char neighbour : graph_path_order) {
    std::cout << (neighbour) << ", ";
  }
  std::cout << std::endl;
}

void depthFirstPrintRecursive(const std::map<char, std::vector<char>> &graph,
                              char start) {
  if (graph.count(start)) {
    std::cout << start << ", ";
    for (char neighbour : graph.at(start)) {
      depthFirstPrintRecursive(graph, neighbour);
    }
  } else {
    std::stringstream ss;
    ss << "\n\ninvalid node name: " << start << "!!\n\n";
    throw std::invalid_argument(ss.str());
  }
}

void depthFirstPrintRecursiveNoExcept(
    const std::map<char, std::vector<char>> &graph, char start) noexcept {
  try {
    depthFirstPrintRecursive(graph, start);
  } catch (const std::exception &e) {
    std::cerr << e.what();
  }
}

bool hasPath_breadthFirst(std::map<char, std::vector<char>> graph, char start,
                          char dest) {
  std::queue<char> graph_que;
  graph_que.push(start);
  std::vector<char> graph_path_order;

  while (true) {
    char current_node = graph_que.front();
    graph_que.pop();
    // because of at we can change this if to try/catch
    if (graph.count(current_node)) {
      if (current_node == dest) {
        return true;
      }
      graph_path_order.push_back(current_node);
      // don't know why operator[] is not working :/
      const std::vector<char> &neighbors = graph.at(current_node);

      for (char neighbour : neighbors) {
        graph_que.push(neighbour);
      }
    } else {
      std::cerr << "No " << current_node << " node in graph\n";
      break;
    }
    if (graph_que.empty()) {
      break;
    }
  }
  return false;
}

bool hasPath_depthFirstPrintRecursive(
    const std::map<char, std::vector<char>> &graph, char start, char dest) {
  if (start == dest) {
    return true;
  }
  if (graph.count(start)) {
    for (char neighbour : graph.at(start)) {
      if (hasPath_depthFirstPrintRecursive(graph, neighbour, dest)) {
        return true;
      }
    }
  } else {
    std::stringstream ss;
    ss << "\n\ninvalid node name: " << start << "!!\n\n";
    throw std::invalid_argument(ss.str());
  }
  return false;
}

bool hasPath_throws(std::map<char, std::vector<char>> graph, char start,
                    char dest, std::set<char> &already_in) {
  if (start == dest) {
    return true;
  }
  if (already_in.count(start)) {
    return false;
  }
  if (graph.count(start)) {
    already_in.insert(start);
    for (auto neighbour : graph.at(start)) {
      if (hasPath_throws(graph, neighbour, dest, already_in)) {
        return true;
      }
    }
  }
  return false;
}

bool hasPath(const std::map<char, std::vector<char>> &graph, char start,
             char dest) {
  std::set<char> visited;
  try {
    return hasPath_throws(graph, start, dest, visited);
  } catch (const std::exception &e) {
    std::cerr << e.what();
  }
  return false;
}

std::map<char, std::vector<char>>
edgesToGraph(const std::vector<std::vector<char>> &edges) {
  std::map<char, std::vector<char>> graph;
  for (auto edge : edges) {
    graph[edge[0]].push_back(edge[1]);
    graph[edge[1]].push_back(edge[0]);
  }
  return std::move(graph);
}

void printGraph(const std::map<char, std::vector<char>> &graph) {
  for (auto node : graph) {
    std::cout << "Node: " << node.first << " Neighbors:  ";
    for (auto neighbour : node.second) {
      std::cout << neighbour << ", ";
    }
    std::cout << std::endl;
  }
}

int howMAnyGroups(const std::map<int, std::vector<int>> &graph) {
  int num_of_groups = 0;
  std::set<int> visited_nodes;
  std::deque<int> keys;

  for (auto node : graph) {
    keys.push_back(node.first);
  }

  for (auto key : keys) {
    if (visited_nodes.count(key)) {
      continue;
    }
    num_of_groups++;
    walkAll(graph, visited_nodes, key);
  }

  return num_of_groups;
}

void walkAll(const std::map<int, std::vector<int>> &graph,
             std::set<int> &visited_nodes, int start_node) {
  if (graph.count(start_node)) {
    if (visited_nodes.count(start_node)) {
      return;
    }
    visited_nodes.insert(start_node);
    for (int node : graph.at(start_node)) {
      walkAll(graph, visited_nodes, node);
    }
  }
}

int largestGroup(const std::map<int, std::vector<int>> &graph) {
  int largest = 0;
  std::set<int> visited_nodes;
  std::deque<int> keys;

  for (auto node : graph) {
    keys.push_back(node.first);
  }

  for (auto key : keys) {
    int temp;
    if (visited_nodes.count(key)) {
      continue;
    }
    temp = walkAllCount(graph, visited_nodes, key);
    largest = temp > largest ? temp : largest;
  }

  return largest;
}

int walkAllCount(const std::map<int, std::vector<int>> &graph,
                 std::set<int> &visited_nodes, int start_node) {
  int sum = 0;
  if (graph.count(start_node)) {
    if (visited_nodes.count(start_node)) {
      return sum;
    }
    sum++;
    visited_nodes.insert(start_node);
    for (int node : graph.at(start_node)) {
      sum += walkAllCount(graph, visited_nodes, node);
    }
  }
  return sum;
}

int shortestPath(const std::map<char, std::vector<char>> &graph, char start,
                 char dest) {
  std::set<char> visited;
  return pathLength(graph, visited, start, dest);
}

int pathLength(std::map<char, std::vector<char>> graph, std::set<char> visited,
               char start, char dest) {
  std::queue<std::tuple<char, int>> graph_que;
  graph_que.push(std::make_tuple(start, 0));
  int dist = 0;

  while (true) {
    if (graph_que.empty()) {
      break;
    }
    std::tuple<char, int> current_node = graph_que.front();
    graph_que.pop();
    if (graph.count(std::get<0>(current_node))) {
      if (visited.count(std::get<0>(current_node))) {
        continue;
      }
      visited.insert(std::get<0>(current_node));
      if (std::get<0>(current_node) == dest) {
        return std::get<1>(current_node);
      }

      const std::vector<char> &neighbors = graph.at(std::get<0>(current_node));

      for (char neighbour : neighbors) {
        graph_que.push(
            std::make_tuple(neighbour, std::get<1>(current_node) + 1));
      }
    } else {
      std::cerr << "No \"" << std::get<0>(current_node) << "\" node in graph\n";
      break;
    }
  }
  return -1;
}

bool newIslands(const std::vector<std::vector<char>> &graph_draw,
                 std::set<Point> &visited, Point &start, const Point &size) {
  if (graph_draw[start._y][start._x] == 'w') {
    return false;
  }
  if (visited.count(start)) {
    return false;
  }

  visited.insert(start);
  if (start._x > 0) {
    start._x -= 1;
    newIslands(graph_draw, visited, start, size);
    start._x += 1;
  }
  if (start._x + 1 < size._x) {
    start._x += 1;
    newIslands(graph_draw, visited, start, size);
    start._x -= 1;
  }
  if (start._y > 0) {
    start._y -= 1;
    newIslands(graph_draw, visited, start, size);
    start._y += 1;
  }
  if (start._y + 1 < size._y) {
    start._y += 1;
    newIslands(graph_draw, visited, start, size);
    start._y -= 1;
  }

  return true;
}

int countIslands(const std::vector<std::vector<char>> &graph_draw) {
  std::set<Point> visited;
  const Point size(graph_draw[0].size(), graph_draw.size());
  int sum = 0;
  auto temp = Point(0, 0);
  for (int y = 0; y < size._y; y++) {
    temp._y = y;
    for (int x = 0; x < size._x; x++) {
      temp._x = x;
      sum += newIslands(graph_draw, visited, temp, size);
    }
  }
  return sum;
}
