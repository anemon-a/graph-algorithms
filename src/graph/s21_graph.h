#ifndef S21_GRAPH_H_
#define S21_GRAPH_H_

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

#include "s21_graph_interface.h"

namespace s21 {

class Graph : public IGraph {
 public:
  friend class GraphTest;
  Graph() : graph_type_(GraphType::kGraph), vertex_count_(0) {};

  void LoadGraphFromFile(std::string filename);
  // void ExportGraphToDot(std::string filename);
  void PrintGraph() const;

  void AddEdge(const Vertex& vertex_from, const Vertex& vertex_to,
               int weight) override;

  size_t GetVertexCount() const override;
  int GetEdgeWeight(const Vertex& vertex_from,
                    const Vertex& vertex_to) const override;
  const std::vector<Vertex> GetNeighbourVertices(
      const Vertex& vertex) const override;
  const std::vector<Vertex> GetAllVertices() const override;

  const std::vector<std::vector<int>>& GetAdjacencyMatrix()
      const;  // Для тестов

 private:
  void SetGraphType(GraphType type);
  void AddVertex(const Vertex& vertex);
  int GetIndex(const Vertex& vertex) const;

  GraphType graph_type_;
  size_t vertex_count_;
  std::map<Vertex, int> vertex_index_map_;
  std::vector<std::vector<int>> adjacency_matrix_;
};

std::string VertexToString(const Vertex& vertex);

}  // namespace s21

#endif  // S21_GRAPH_H_
