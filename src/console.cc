#include "console.h"

int s21::Console::Run() {
  while (true) {
    std::cout << messages.at(ConsoleMessage::kMenu);
    try {
      switch (InputItem()) {
        case MenuItem::kQuit: {
          std::cout << "Exit.\n";
          return 0;
        }
        case MenuItem::kLoadGraph: {
          RunLoadGraph();
          break;
        }
        case MenuItem::kBFS: {
          RunBFS();
          break;
        }
        case MenuItem::kDFS: {
          RunDFS();
          break;
        }
        case MenuItem::kDeikstra: {
          RunDeikstra();
          break;
        }
        case MenuItem::kAllVertices: {
          RunFindPaths();
          break;
        }
        case MenuItem::kMinTree: {
          RunMinTree();
          break;
        }
        case MenuItem::kSalesman: {
          RunSalesman();
          break;
        }
        default:
          std::cout << "Input between 0 and 7";
          break;
      }
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
  }
}

void s21::Console::RunLoadGraph() {
  std::cout << "Loading the graph from file.\n";
  std::cout << "Input filename: ";
  std::string filename;
  std::cin >> filename;
  graph_.LoadGraphFromFile(filename);
  std::cout << "The graph is loaded.\n";
}

void s21::Console::RunBFS() {
  std::cout << "Breadth First Search.\n";
  std::vector<Vertex> result;
  Vertex v = InputVertex();
  result = graph_algorithms_.BreadthFirstSearch(graph_, v);
  std::cout << "Result: ";
  for (const auto& v : result) {
    std::cout << VertexToString(v) << ' ';
  }
}

void s21::Console::RunDFS() {
  std::cout << "Depth First Search.\n";
  std::vector<Vertex> result;
  Vertex v = InputVertex();
  result = graph_algorithms_.DepthFirstSearch(graph_, v);
  std::cout << "Result: ";
  for (const auto& v : result) {
    std::cout << VertexToString(v) << ' ';
  }
}

void s21::Console::RunDeikstra() {
  std::cout << "Search for the shortest path between two vertices.\n";
  int result;
  Vertex v1 = InputVertex();
  Vertex v2 = InputVertex();
  result = graph_algorithms_.GetShortestPathBetweenVertices(graph_, v1, v2);
  std::cout << "The shortest path between " + VertexToString(v1) + " " +
                   VertexToString(v2) + ": ";
  std::cout << result;
}

void s21::Console::RunFindPaths() {
  std::cout << "Search for the shortest path between all vertices.\n";
  std::vector<std::vector<std::optional<int>>> result =
      graph_algorithms_.GetShortestPathsBetweenAllVertices(graph_);
  std::cout << "The shortest paths between all vertices:\n";
  for (const auto& row : result) {
    for (const auto& v : row) {
      if (v.has_value())
        std::cout << v.value() << " ";
      else
        std::cout << "∞ ";
    }
    std::cout << std::endl;
  }
}

void s21::Console::RunMinTree() {
  std::cout << "Search for the minimum spanning tree in the graph.\n";
  std::vector<std::vector<int>> result =
      graph_algorithms_.GetLeastSpanningTree(graph_);
  std::cout << "The minimum spanning tree:\n";
  for (const auto& row : result) {
    for (const auto& v : row) {
      std::cout << v.value() << " ";
    }
    std::cout << std::endl;
  }
}

void s21::Console::RunSalesman() {
  std::cout << "Solving the traveling salesman problem.\n";
  // std::vector<std::vector<int>> result = graph_algorithms_.(graph_);
  // std::cout << "Result:\n";
  // for (const auto& row : result) {
  //   for (const auto& v : row) {
  //     std::cout << v.value() << " ";
  //   }
  //   std::cout << std::endl;
  // }
}

s21::MenuItem s21::Console::InputItem() {
  std::string choice;
  std::cout << "Enter the menu item from 1 to 7. To exit, press 0: ";
  std::cin >> choice;
  if (!IsDigit(choice)) {
    throw std::invalid_argument("Invalid input");
  }
  return static_cast<MenuItem>(stoi(choice));
}

Vertex s21::Console::InputVertex() {
  Vertex vertex;
  std::string input;
  std::cout << "Enter the vertex: ";

  if (std::cin >> input; IsDigit(input)) {
    vertex = stoi(input);
  } else {
    vertex = input;
  }
  return vertex;
}

bool s21::Console::IsDigit(const std::string& input) {
  for (char ch : input) {
    if (!std::isdigit(ch)) {
      return false;
    }
  }
  return true;
}
