#include "s21_graph_algorithms.h"

std::vector<int> GraphAlgorithms::DepthFirstSearch(Graph &graph,
                                                   int start_vertex) {
  std::stack<int> stack;
  std::set<int> visited;
  stack.push(start_vertex);
  while (stack.size()) {
    int v_from = stack.top();
    if (!visited.count(v_from)) {
      visited.insert(v_from);
      for (size_t v_to = graph.GetCountVertexes()-1; v_to >= 0; v_to--) {
        if (v_from != v_to) {
          if (graph.GetEdgeWeight(v_from, v_to) && !visited.count(v_to)) {
            stack.push(v_to);
          }
        }
      }
    }
    stack.pop();
  }

  return  std::vector<int>(visited.cbegin, visited.cend);
}

// std::vector<int> GraphAlgorithms::BreadthFirstSearch(Graph &graph,
//                                                      int start_vertex) {
//   std::vector<int> result;
//   std::queue<int> unvisited;
//   std::unordered_set<int> need_visit;
//   unvisited.push(start_vertex);
//   need_visit.insert(start_vertex);
//   while (unvisited.size() != 0) {
//     int v_from = unvisited.front();
//     for (size_t v_to = 0; v_to != graph.GetCountVertexes(); v_to++) {
//       if (v_from != v_to) {
//         if (graph.GetEdgeWeight(v_from, v_to) && !need_visit.count(v_to)) {
//           unvisited.push(v_to);
//           need_visit.insert(v_to);
//         }
//       }
//     }
//     result.push_back(v_from);
//     unvisited.pop();
//   }
//   return result;
// }

std::vector<int> GraphAlgorithms::BreadthFirstSearch(Graph &graph,
                                                     int start_vertex) {
  std::queue<int> unvisited;
  std::set<int> visited;
  unvisited.push(start_vertex);
  while (unvisited.size()) {
    int v_from = unvisited.front();
    if (!visited.count(v_from)) {
      // стоит ли создать метод чтобы возращал первый элемент графа и последний элемент графа, может быть с помощью итераторов итераторы
      for (size_t v_to = 0; v_to != graph.GetCountVertexes(); v_to++) {
        if (v_from != v_to) {
          if (graph.GetEdgeWeight(v_from, v_to)) {
            unvisited.push(v_to);
          }
        }
      }
    }
    visited.insert(v_from);
    unvisited.pop();
  }
  return std::vector<int>(visited.cbegin, visited.cend);
}
