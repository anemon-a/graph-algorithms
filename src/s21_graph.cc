#include "s21_graph.h"

#include "parser.h"

void Graph::LoadGraphFromFile(std::string filename) {
  Parser parser;
  std::ifstream in(filename);

  if (!in.is_open()) {
    throw std::runtime_error("Could not open the file.");
  }
  parser.ParseGraphFromDot(in, *this);
  in.close();
}

void Graph::ExportGraphToDot(std::string filename) {}

int Graph::GetVertex(std::string vertex) const { return vertexes_.at(vertex); }

int Graph::GetEdgeWeight(int vertex_from, int vertex_to) const {
  return adjacency_matrix_[vertex_from][vertex_to];
}

void Graph::AddVertex(std::string vertex) {
  if (!vertexes_.count(vertex)) {
    vertexes_[vertex] = count_vertexes_++;
    std::vector<int> v(count_vertexes_, 0);
    adjacency_matrix_.push_back(v);
    for (size_t i = 0; i != count_vertexes_ - 1; ++i) {
      adjacency_matrix_[i].push_back(0);
    }
  }
}

void Graph::AddEdge(int vertex_from, int vertex_to, int weight) {
  adjacency_matrix_[vertex_from][vertex_to] = weight;
  if (graph_type_ == GraphType::GRAPH) {
    adjacency_matrix_[vertex_to][vertex_from] = weight;
  }
}

int Graph::GetCountVertexes() const { return count_vertexes_; }

void Graph::SetGraphType(GraphType type) { graph_type_ = type; }

void Graph::PrintGraph() const {
  for (size_t i = 0; i != count_vertexes_; ++i) {
    for (size_t j = 0; j != count_vertexes_; ++j) {
      std::cout << adjacency_matrix_[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}
