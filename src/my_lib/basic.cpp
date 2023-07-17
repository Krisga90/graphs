#include "basic.h"

#include <map>
#include <stack>
#include <vector>

void depthFirstPrint(const std::map<char, std::vector<char>> &graph,
                     char start) {
  std::stack<char> graph_stack;
  graph_stack.push(start);
  std::vector<char> graph_path_order;

  while (true) {
    char current_node = graph_stack.top();
    graph_stack.pop();
    if (graph.count(
            current_node)) // because of at we can change this if to try/catch
    {
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