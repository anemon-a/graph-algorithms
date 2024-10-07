#include "s21_graph_algorithms.h"

#include <optional>

std::vector<Vertex> GraphAlgorithms::DepthFirstSearch(
    IGraph &graph, const Vertex &start_vertex) {
  std::stack<Vertex> stack;
  std::vector<Vertex> result;
  std::unordered_set<Vertex> visited;
  stack.push(start_vertex);
  while (!stack.empty()) {
    Vertex v_from = stack.top();
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

std::vector<Vertex> GraphAlgorithms::BreadthFirstSearch(
    IGraph &graph, const Vertex &start_vertex) {
  std::queue<Vertex> queue;
  std::vector<Vertex> result;
  std::unordered_set<Vertex> visited;
  queue.push(start_vertex);
  while (!queue.empty()) {
    Vertex v_from = queue.front();
    if (!visited.count(v_from)) {
      for (const auto &v_to : graph.GetNeighbourVertices(v_from)) {
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

int GraphAlgorithms::GetShortestPathBetweenVertices(IGraph &graph,
                                                    const Vertex &vertex1,
                                                    const Vertex &vertex2) {
  std::map<Vertex, int> vertex_distance;
  std::unordered_set<Vertex> unvisited;
  for (const auto &vertex : graph.GetAllVertices()) {
    vertex_distance[vertex] = infinity;
    unvisited.insert(vertex);
  }
  vertex_distance[vertex1] = 0;
  while (!unvisited.empty()) {
    int min_distance = infinity;
    Vertex min_distance_vertex = -1;

    for (const auto &[vertex, distance] : vertex_distance) {
      if (distance < min_distance && unvisited.count(vertex)) {
        min_distance = distance;
        min_distance_vertex = vertex;
      }
    }
    unvisited.erase(min_distance_vertex);
    if (min_distance_vertex == Vertex(-1)) break;

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

std::vector<std::vector<std::optional<int>>>
GraphAlgorithms::GetShortestPathsBetweenAllVertices(IGraph &graph) {
  int vertex_count = graph.GetVertexCount();
  const auto &vertices = graph.GetAllVertices();
  std::vector<std::vector<std::optional<int>>> shortest_paths(
      vertex_count,
      std::vector<std::optional<int>>(vertex_count, std::nullopt));

  int i = 0, j = 0, weight = 0;
  for (const auto &v_from : vertices) {
    j = 0;
    for (const auto &v_to : vertices) {
      if (i == j) {
        shortest_paths[i][j] = 0;
      } else if ((weight = graph.GetEdgeWeight(v_from, v_to))) {
        shortest_paths[i][j] = weight;
      }
      j++;
    }
    i++;
  }
  for (int k = 0; k < vertex_count; ++k) {
    for (int i = 0; i < vertex_count; ++i) {
      for (int j = 0; j < vertex_count; ++j) {
        if (shortest_paths[i][k].has_value() &&
            shortest_paths[k][j].has_value())
          if (!shortest_paths[i][j].has_value() ||
              shortest_paths[i][j].value() > (shortest_paths[i][k].value() +
                                              shortest_paths[k][j].value())) {
            shortest_paths[i][j] =
                shortest_paths[i][k].value() + shortest_paths[k][j].value();
          }
      }
    }
  }
  return shortest_paths;
}
