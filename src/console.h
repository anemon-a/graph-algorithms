#ifndef CONSOLE_H_
#define CONSOLE_H_

#include "graph/s21_graph.h"
#include "graph_algorithms/s21_graph_algorithms.h"

enum class ConsoleMessage {
  kMenu = 0,
};
enum class MenuItem {
  kQuit = 0,
  kLoadGraph,
  kBFS,
  kDFS,
  kDeikstra,
  kAllVertices,
  kMinTree,
  kSalesman
};

const std::map<ConsoleMessage, std::string> messages = {
    {ConsoleMessage::kMenu,
     "\n--------------MENU--------------\n"
     "1. Download the graph from the file.\n"
     "2. Traversing the graph in width.\n"
     "3. Traversing the graph in depth.\n"
     "4. Search for the shortest path between arbitrary two vertices.\n"
     "5. Find the shortest paths between all pairs of vertices in the graph.\n"
     "6. Search for the minimum spanning tree in the graph.\n"
     "7. Solving the traveling salesman problem.\n"
     "--------------------------------\n\n"}};

class Console {
 public:
  int Run();
  MenuItem InputItem();
  Vertex InputVertex();
  void PrintVertex(const Vertex& vertex);

 private:
  bool IsDigit(const std::string& input);

  Graph graph_;
  GraphAlgorithms graph_algorithms_;
};

#endif  // CONSOLE_H_
