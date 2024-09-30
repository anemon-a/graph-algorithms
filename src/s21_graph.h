#ifndef S21_GRAPH_H_
#define S21_GRAPH_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class IGraph {
 public:
  enum class GraphType { GRAPH, DIGRAPH };
  virtual int GetCountVertices() const = 0;
  virtual int GetEdgeWeight(int vertex_from, int vertex_to) const = 0;
  virtual void AddEdge(int vertex_from, int vertex_to, int weight) = 0;
  virtual void SetGraphType(GraphType type) = 0;
  virtual const std::vector<int> GetNeighbourVertices(int vertex) const = 0;
};

class Graph : public IGraph {
 public:
  Graph() : graph_type_(GraphType::GRAPH), vertex_count_(0) {};
  void LoadGraphFromFile(std::string filename);
  // void ExportGraphToDot(std::string filename);
  void PrintGraph() const;

  void SetGraphType(GraphType type) override;
  void AddEdge(int vertex_from, int vertex_to, int weight) override;

  int GetCountVertices() const override;
  int GetEdgeWeight(int vertex_from, int vertex_to) const override;
  const std::vector<int> GetNeighbourVertices(int vertex) const override;

 private:
  int GetVertexIndex(int vertex) const;
  void AddVertex(int vertex);

  GraphType graph_type_;
  size_t vertex_count_;
  std::unordered_map<int, int> vertex_index_;
  std::vector<std::vector<int>> adjacency_matrix_;
};

#endif  // S21_GRAPH_H_
