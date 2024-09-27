#include "parser.h"

void Parser::ParseGraphFromDot(std::ifstream& in, IGraph& graph) {
  std::string line;
  while (std::getline(in, line) && line != "}") {
    size_t pos = 0;
    if (line.find("digraph") != std::string::npos) {
      graph.SetGraphType(IGraph::GraphType::DIGRAPH);
    } else if (line.find("graph") != std::string::npos) {
      graph.SetGraphType(IGraph::GraphType::GRAPH);
    }
    if (((pos = line.find("->")) != std::string::npos) ||
        ((pos = line.find("--")) != std::string::npos)) {
      std::string v_from, v_to, sep, label;
      int weight = 1;
      std::stringstream ss(line);

      ss >> v_from >> sep >> v_to >> label;
      graph.AddVertex(v_from);
      graph.AddVertex(v_to);

      if ((pos = label.find("label=")) != std::string::npos) {
        weight = std::stoi(label.substr(label.find('=') + 2));
      }
      graph.AddEdge(graph.GetVertex(v_from), graph.GetVertex(v_to), weight);
    }
  }
}

// void Parser::WriteGraphToDot(std::ofstream& out, const IGraph& graph) {}
