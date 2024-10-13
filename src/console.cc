#include "console.h"

int Console::Run() {
  while (true) {
    std::cout << messages.at(ConsoleMessage::kMenu);
    switch (InputItem()) {
      case MenuItem::kQuit: {
        std::cout << "Exit.\n";
        return 0;
        break;
      }
      case MenuItem::kLoadGraph: {
        std::cout << "Loading the graph from file.\n";
        std::cout << "Input filename: ";
        std::string filename;
        std::cin >> filename;
        try {
          graph_.LoadGraphFromFile(filename);
        } catch (const std::exception& e) {
          std::cerr << e.what() << '\n';
        }
        break;
      }
      case MenuItem::kBFS: {
        std::cout << "Breadth First Search.\n";
        std::vector<Vertex> result;
        try {
          result = graph_algorithms_.BreadthFirstSearch(
              graph_,
              InputVertex());  // если вершина нет, то должно быть исключение,
                               // нужно проверить как алгоритм работает на
                               // неправильной вершине
          for (const auto& v : result) {
            PrintVertex(v);
          }
        } catch (const std::exception& e) {
          std::cerr << e.what() << '\n';
        }
        break;
      }
      case MenuItem::kDFS: {
        std::cout << "Depth First Search.\n";
        std::vector<Vertex> result;
        try {
          result = graph_algorithms_.DepthFirstSearch(
              graph_,
              InputVertex());  // если вершина нет, то должно быть исключение,
                               // нужно проверить как алгоритм работает на
                               // неправильной вершине
          for (const auto& v : result) {
            PrintVertex(v);
          }
        } catch (const std::exception& e) {
          std::cerr << e.what() << '\n';
        }
        break;
      }
      case MenuItem::kDeikstra: {
        break;
      }
      case MenuItem::kAllVertices: {
        break;
      }
      case MenuItem::kMinTree: {
        break;
      }
      case MenuItem::kSalesman: {
        break;
      }
      default:
        std::cout << "Input between 0 and 7";
        break;
    }
  }
}

MenuItem Console::InputItem() {
  std::string choice;
  std::cout << "Enter the menu item from 1 to 7. To exit, press 0: ";
  std::cin >> choice;
  if (!IsDigit(choice)) {
    throw std::invalid_argument("Invalid input");
  }
  return static_cast<MenuItem>(stoi(choice));
}

Vertex Console::InputVertex() {
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

void Console::PrintVertex(const Vertex& vertex) {
  std::visit([](auto&& arg) { std::cout << arg << ' '; }, vertex);
}

bool Console::IsDigit(const std::string& input) {
  for (char ch : input) {
    if (!std::isdigit(ch)) {
      return false;
    }
  }
  return true;
}
