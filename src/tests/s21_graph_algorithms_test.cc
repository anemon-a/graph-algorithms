#include "../s21_graph_algorithms.h"

#include <gtest/gtest.h>

TEST(BreadthFirstSearch, GraphTest1) {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/graph1.dot");

  std::vector<int> res1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  auto res2 = alg.BreadthFirstSearch(g, 1);

  ASSERT_EQ(res1.size(), res2.size());
  for (size_t i = 0; i < res1.size(); i++) {
    ASSERT_EQ(res1[i], res2[i]);
  }
}
TEST(BreadthFirstSearch, GraphTest2) {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/graph2.dot");

  std::vector<int> res1 = {6, 5, 7, 4, 8, 3, 9, 2, 10, 1, 11};
  auto res2 = alg.BreadthFirstSearch(g, 6);
  // for (size_t i = 0; i < res1.size(); i++) {
  //   std::cout << res2[i] << ' ';
  // }

  ASSERT_EQ(res1.size(), res2.size());
  for (size_t i = 0; i < res1.size(); i++) {
    ASSERT_EQ(res1[i], res2[i]);
  }
}

TEST(BreadthFirstSearch, DigraphTest1) {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/digraph1.dot");

  std::vector<int> res1 = {2, 4, 5, 1, 3};
  auto res2 = alg.BreadthFirstSearch(g, 2);

  ASSERT_EQ(res1.size(), res2.size());
  for (size_t i = 0; i < res1.size(); i++) {
    ASSERT_EQ(res1[i], res2[i]);
  }
}

TEST(BreadthFirstSearch, DigraphTest2) {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/digraph2.dot");
  std::vector<int> res1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  auto res2 = alg.BreadthFirstSearch(g, 1);

  ASSERT_EQ(res1.size(), res2.size());
  for (size_t i = 0; i < res1.size(); i++) {
    ASSERT_EQ(res1[i], res2[i]);
  }
}

TEST(DepthFirstSearch, GraphTest1) {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/graph1.dot");

  std::vector<int> res1 = {1, 2, 4, 6, 8, 10, 11, 9, 7, 5, 3};
  auto res2 = alg.DepthFirstSearch(g, 1);

  ASSERT_EQ(res1.size(), res2.size());
  for (size_t i = 0; i < res1.size(); i++) {
    ASSERT_EQ(res1[i], res2[i]);
  }
}

TEST(DepthFirstSearch, GraphTest2) {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/graph2.dot");

  std::vector<int> res1 = {6, 5, 4, 3, 2, 1, 11, 10, 9, 8, 7};
  auto res2 = alg.DepthFirstSearch(g, 6);

  ASSERT_EQ(res1.size(), res2.size());
  for (size_t i = 0; i < res1.size(); i++) {
    ASSERT_EQ(res1[i], res2[i]);
  }
}

TEST(DepthFirstSearch, DigraphTest1) {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/digraph1.dot");

  std::vector<int> res1 = {5, 1, 2, 4, 3};
  auto res2 = alg.DepthFirstSearch(g, 5);

  ASSERT_EQ(res1.size(), res2.size());
  for (size_t i = 0; i < res1.size(); i++) {
    ASSERT_EQ(res1[i], res2[i]);
  }
}

TEST(DepthFirstSearch, DigraphTest2) {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/digraph2.dot");
  std::vector<int> res1 = {1, 2, 4, 8, 11, 14, 5, 3, 6, 9, 12, 15, 7, 10, 13};
  auto res2 = alg.DepthFirstSearch(g, 1);

  ASSERT_EQ(res1.size(), res2.size());
  for (size_t i = 0; i < res1.size(); i++) {
    ASSERT_EQ(res1[i], res2[i]);
  }
}
TEST(GetShortestPathBetweenVertices, GraphTest1) {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/graph1.dot");
  auto res = alg.GetShortestPathBetweenVertices(g, 1, 11);
  ASSERT_EQ(res, 12);
}

TEST(GetShortestPathBetweenVertices, GraphTest2) {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/graph2.dot");
  auto res = alg.GetShortestPathBetweenVertices(g, 10, 2);
  ASSERT_EQ(res, 10);
}