#ifndef S21_GRAPH_H_
#define S21_GRAPH_H_

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class IGraph {
 public:
  enum class GraphType { GRAPH, DIGRAPH };
  virtual int GetVertex(std::string vertex) const = 0;
  virtual void AddVertex(std::string vertex) = 0;
  virtual int GetEdgeWeight(int vertex_from, int vertex_to) const = 0;
  virtual void AddEdge(int vertex_from, int vertex_to, int weight) = 0;
  virtual void SetGraphType(GraphType type) = 0;
  virtual int GetCountVertices() const = 0;
  virtual std::vector<int> GetNeighboursVertex(int vertex) const = 0;
};

class Graph : IGraph {
 public:
  Graph() : count_vertices_(0), adjacency_matrix_(0) {};
  void LoadGraphFromFile(std::string filename);
  void ExportGraphToDot(std::string filename);
  void PrintGraph() const;

  void SetGraphType(GraphType type) override;
  void AddVertex(std::string vertex) override;
  void AddEdge(int vertex_from, int vertex_to, int weight) override;

  int GetCountVertices() const override;
  int GetVertex(std::string vertex) const override;
  int GetEdgeWeight(int vertex_from, int vertex_to) const override;

 private:
  GraphType graph_type_;
  size_t count_vertices_;
  std::map<std::string, int> vertices_;
  std::vector<std::vector<int>> adjacency_matrix_;
};

#endif  // S21_GRAPH_H_
