#include "s21_graph_algorithms.h"

std::vector<int> GraphAlgorithms::DepthFirstSearch(Graph &graph,
                                                   int start_vertex) {
  std::vector<int> result;
  std::stack<int> stack;

  return result;
}

std::vector<int> GraphAlgorithms::BreadthFirstSearch(Graph &graph,
                                                     int start_vertex) {
  std::vector<int> result;
  std::queue<int> unvisited;
  std::unordered_set<int> need_visit;
  unvisited.push(start_vertex);
  need_visit.insert(start_vertex);
  while (unvisited.size() != 0) {
    int v_from = unvisited.front();
    for (size_t v_to = 0; v_to != graph.GetCountVertexes(); v_to++) {
      if (v_from != v_to) {
        if (graph.GetEdgeWeight(v_from, v_to) && !need_visit.count(v_to)) {
          unvisited.push(v_to);
          need_visit.insert(v_to);
        }
      }
    }
    result.push_back(v_from);
    unvisited.pop();
  }
  return result;
}
