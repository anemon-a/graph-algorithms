#include "s21_graph_algorithms.h"

std::vector<int> GraphAlgorithms::DepthFirstSearch(IGraph &graph,
                                                   int start_vertex) {
  std::stack<int> stack;
  std::vector<int> result;
  std::unordered_set<int> visited;
  stack.push(start_vertex);
  while (!stack.empty()) {
    int v_from = stack.top();
    stack.pop();
    if (!visited.count(v_from)) {
      visited.insert(v_from);
      result.push_back(v_from);
      auto neighbours = graph.GetNeighbourVertices(v_from);
      for (auto v_to = neighbours.rbegin(); v_to != neighbours.rend(); v_to++) {
        if (!visited.count(*v_to)) {
          stack.push(*v_to);
        }
      }
    }
  }

  return result;
}

std::vector<int> GraphAlgorithms::BreadthFirstSearch(IGraph &graph,
                                                     int start_vertex) {
  std::queue<int> not_visited;
  std::vector<int> result;
  std::unordered_set<int> visited;
  not_visited.push(start_vertex);
  while (!not_visited.empty()) {
    int v_from = not_visited.front();
    if (!visited.count(v_from)) {
      for (const int &v_to : graph.GetNeighbourVertices(v_from)) {
        if (!visited.count(v_to)) {
          not_visited.push(v_to);
        }
      }
      visited.insert(v_from);
      result.push_back(v_from);
    }
    not_visited.pop();
  }
  return result;
}
