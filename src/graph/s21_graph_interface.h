#ifndef S21_GRAPH_INTERFACE_H_
#define S21_GRAPH_INTERFACE_H_

#include <stdexcept>
#include <string>
#include <variant>
#include <vector>

using Vertex = std::variant<int, std::string>;

namespace s21 {

class IGraph {
 public:
  enum class GraphType { kGraph, kDigraph };

  virtual size_t GetVertexCount() const = 0;
  virtual int GetEdgeWeight(const Vertex& vertex_from,
                            const Vertex& vertex_to) const = 0;

  virtual void AddEdge(const Vertex& vertex_from, const Vertex& vertex_to,
                       int weight) = 0;

  virtual const std::vector<Vertex> GetNeighbourVertices(
      const Vertex& vertex) const = 0;
  virtual const std::vector<Vertex> GetAllVertices() const = 0;
};
}  // namespace s21

#endif  // S21_GRAPH_INTERFACE_H_
