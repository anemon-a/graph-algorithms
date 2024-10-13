#include "s21_graph.h"

void Graph::LoadGraphFromFile(std::string filename) {
  std::ifstream in(filename);
  std::string line;

  if (!in.is_open()) {
    throw std::runtime_error("Could not open the file.");
  }

  while (std::getline(in, line) && line != "}") {
    size_t pos = 0;
    if (line.find("digraph") != std::string::npos) {
      SetGraphType(IGraph::GraphType::kDigraph);
    } else if (line.find("graph") != std::string::npos) {
      SetGraphType(IGraph::GraphType::kGraph);
    }
    if (((pos = line.find("->")) != std::string::npos) ||
        ((pos = line.find("--")) != std::string::npos)) {
      std::string v1, v2, sep, label;
      Vertex v_from, v_to;
      int weight = 1;
      std::stringstream ss(line);

      ss >> v1 >> sep >> v2 >> label;
      if (isdigit(v1[0])) {
        v_from = std::stoi(v1);
      } else {
        v_from = v1;
      }

      if (isdigit(v2[0])) {
        v_to = std::stoi(v2);
      } else {
        v_to = v2;
      }

      if ((pos = label.find("label=")) != std::string::npos) {
        weight = std::stoi(label.substr(label.find('=') + 2));
      }
      AddEdge(v_from, v_to, weight);
    }
  }
  in.close();
}

// void Graph::ExportGraphToDot(std::string filename) {}

const std::vector<std::vector<int>>& Graph::GetAdjacencyMatrix() const {
  return adjacency_matrix_;
}

size_t Graph::GetVertexCount() const { return vertex_count_; }

int Graph::GetVertexIndex(const Vertex& vertex) const {
  return vertex_index_.at(vertex);
}

int Graph::GetEdgeWeight(const Vertex& vertex_from,
                         const Vertex& vertex_to) const {
  return adjacency_matrix_[GetVertexIndex(vertex_from)]
                          [GetVertexIndex(vertex_to)];
}

const std::vector<Vertex> Graph::GetNeighbourVertices(
    const Vertex& vertex) const {
  std::vector<Vertex> neighbours;
  for (const auto& [v, i] : vertex_index_) {
    if (GetEdgeWeight(vertex, v)) {
      neighbours.push_back(v);
    }
  }
  return neighbours;
}

const std::vector<Vertex> Graph::GetAllVertices() const {
  std::vector<Vertex> vertices;
  for (const auto& [v, i] : vertex_index_) {
    vertices.push_back(v);
  }
  return vertices;
}

void Graph::AddVertex(const Vertex& vertex) {
  if (!vertex_index_.count(vertex)) {
    vertex_index_[vertex] = vertex_count_++;
    std::vector<int> v(vertex_count_, 0);
    adjacency_matrix_.push_back(v);
    for (size_t i = 0; i != vertex_count_ - 1; ++i) {
      adjacency_matrix_[i].push_back(0);
    }
  }
}

void Graph::AddEdge(const Vertex& vertex_from, const Vertex& vertex_to,
                    int weight) {
  AddVertex(vertex_from);
  AddVertex(vertex_to);
  adjacency_matrix_[GetVertexIndex(vertex_from)][GetVertexIndex(vertex_to)] =
      weight;
  if (graph_type_ == GraphType::kGraph) {
    adjacency_matrix_[GetVertexIndex(vertex_to)][GetVertexIndex(vertex_from)] =
        weight;
  }
}

void Graph::SetGraphType(GraphType type) { graph_type_ = type; }

void Graph::PrintGraph() const {
  for (size_t i = 0; i != vertex_count_; ++i) {
    for (size_t j = 0; j != vertex_count_; ++j) {
      std::cout << adjacency_matrix_[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}
