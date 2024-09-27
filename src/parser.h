#ifndef PARSER_H_
#define PARSER_H_

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#include "s21_graph.h"

class Parser {
 public:
  Parser() = default;
  void ParseGraphFromDot(std::ifstream& in, IGraph& graph);
  // void WriteGraphToDot(std::ofstream& out, const IGraph& graph);
};

#endif  // PARSER_H_
