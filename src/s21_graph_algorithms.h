#ifndef S21_GRAPH_ALGORITHMS_H_
#define S21_GRAPH_ALGORITHMS_H_

#include "s21_graph.h"


class GraphAlgorithms {
  public:
  std::vector<int> DepthFirstSearch(IGraph &graph, int start_vertex); // stack
  std::vector<int> BreadthFirstSearch(IGraph &graph, int start_vertex); // queue

  
};

#endif // S21_GRAPH_ALGORITHMS_H_