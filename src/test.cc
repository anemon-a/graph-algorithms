
#include "s21_graph.h"

int main() {
  Graph g;
  g.LoadGraphFromFile("graph.dot");
  g.PrintGraph();
  return 0;
}