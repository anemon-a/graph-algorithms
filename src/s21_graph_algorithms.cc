#include "s21_graph_algorithms.h"

std::vector<int> GraphAlgorithms::DepthFirstSearch(IGraph &graph,
                                                   int start_vertex) {
  std::stack<int> stack;
  std::vector<int> result;
  std::unordered_set<int> visited;
  stack.push(start_vertex);
  while (!stack.empty()) {
    int v_from = stack.top();
    stack.pop();
    if (!visited.count(v_from)) {
      visited.insert(v_from);
      result.push_back(v_from);
      auto neighbours = graph.GetNeighbourVertices(v_from);
      for (auto v_to = neighbours.rbegin(); v_to != neighbours.rend(); v_to++) {
        if (!visited.count(*v_to)) {
          stack.push(*v_to);
        }
      }
    }
  }

  return result;
}

std::vector<int> GraphAlgorithms::BreadthFirstSearch(IGraph &graph,
                                                     int start_vertex) {
  std::queue<int> queue;
  std::vector<int> result;
  std::unordered_set<int> visited;
  queue.push(start_vertex);
  while (!queue.empty()) {
    int v_from = queue.front();
    if (!visited.count(v_from)) {
      for (const int &v_to : graph.GetNeighbourVertices(v_from)) {
        if (!visited.count(v_to)) {
          queue.push(v_to);
        }
      }
      visited.insert(v_from);
      result.push_back(v_from);
    }
    queue.pop();
  }
  return result;
}

int GraphAlgorithms::GetShortestPathBetweenVertices(IGraph &graph, int vertex1,
                                                    int vertex2) {
  std::map<int, int> vertex_distance;
  std::unordered_set<int> unvisited;
  for (auto vertex : graph.GetAllVertices()) {
    vertex_distance[vertex] = std::numeric_limits<int>::max();
    unvisited.insert(vertex);
  }
  vertex_distance[vertex1] = 0;
  while (!unvisited.empty()) {
    int min_distance = std::numeric_limits<int>::max();
    int min_distance_vertex = -1;

    for (const auto &[vertex, distance] : vertex_distance) {
      if (distance < min_distance && unvisited.count(vertex)) {
        min_distance = distance;
        min_distance_vertex = vertex;
      }
    }
    unvisited.erase(min_distance_vertex);
    if (min_distance_vertex == -1) break;

    for (const auto &neighbour_vertex :
         graph.GetNeighbourVertices(min_distance_vertex)) {
      int new_distance = min_distance + graph.GetEdgeWeight(min_distance_vertex,
                                                            neighbour_vertex);

      if (new_distance < vertex_distance[neighbour_vertex]) {
        vertex_distance[neighbour_vertex] = new_distance;
      }
    }
  }
  return vertex_distance[vertex2];
}