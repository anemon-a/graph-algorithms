#include "../s21_graph_algorithms.h"

int main() {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/graph2.dot");
  g.PrintGraph();
  auto res = alg.GetLeastSpanningTree(g);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[0].size(); j++) {
      std::cout << res[i][j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}