
#include <iostream>

#include "s21_graph.h"
#include "s21_graph_algorithms.h"

int main() {
  Graph g;
  g.LoadGraphFromFile("graph.dot");
  g.PrintGraph();
  GraphAlgorithms a;

  std::cout << '\n';

  for (const auto v : a.BreadthFirstSearch(g, 2)) {
    std::cout << v << ' ';
  }
  std::cout << '\n';
  for (const auto v : a.DepthFirstSearch(g, 2)) {
    std::cout << v << ' ';
  }
  return 0;
}