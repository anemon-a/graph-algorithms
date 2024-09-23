#ifndef S21_GRAPH_ALGORITHMS_H_
#define S21_GRAPH_ALGORITHMS_H_

#include <queue>
#include <stack>
#include <unordered_set>

#include "s21_graph.h"

class GraphAlgorithms {
 public:
  std::vector<int> DepthFirstSearch(Graph &graph, int start_vertex);  // stack
  std::vector<int> BreadthFirstSearch(Graph &graph,
                                      int start_vertex);  // queue
};

#endif  // S21_GRAPH_ALGORITHMS_H_