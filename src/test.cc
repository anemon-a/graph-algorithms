
#include <iostream>

#include "s21_graph_algorithms.h"

int main() {
  Graph g;
  g.LoadGraphFromFile("graph.dot");
  g.PrintGraph();
  GraphAlgorithms a;
  auto vector = a.BreadthFirstSearch(g, 1);
  for (const auto& v : vector) {
    std::cout << v << ' ';
  }
  return 0;
}