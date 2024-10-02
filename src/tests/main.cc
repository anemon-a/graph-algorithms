#include "../s21_graph_algorithms.h"

int main() {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/graph1.dot");
  auto res = alg.GetShortestPathBetweenVertices(g, 1, 2);
  // std::cout << res;
  return 0;
}