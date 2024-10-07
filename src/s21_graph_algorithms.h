#ifndef S21_GRAPH_ALGORITHMS_H_
#define S21_GRAPH_ALGORITHMS_H_

#include <limits>
#include <map>
#include <optional>
#include <queue>
#include <stack>
#include <unordered_set>

#include "s21_graph.h"

class GraphAlgorithms {
 public:
  GraphAlgorithms() = default;
  ~GraphAlgorithms() = default;
  std::vector<Vertex> DepthFirstSearch(IGraph &graph,
                                       const Vertex &start_vertex);  // stack
  std::vector<Vertex> BreadthFirstSearch(IGraph &graph,
                                         const Vertex &start_vertex);  // queue
  int GetShortestPathBetweenVertices(IGraph &graph, const Vertex &vertex1,
                                     const Vertex &vertex2);
  std::vector<std::vector<std::optional<int>>>
  GetShortestPathsBetweenAllVertices(IGraph &graph);

  const int infinity = std::numeric_limits<int>::max();
};

#endif  // S21_GRAPH_ALGORITHMS_H_
