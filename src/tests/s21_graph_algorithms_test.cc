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

TEST(GetShortestPathBetweenVertices, DigraphTest1) {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/digraph1.dot");
  auto res = alg.GetShortestPathBetweenVertices(g, 5, 4);
  ASSERT_EQ(res, 10);
}

TEST(GetShortestPathBetweenVertices, DigraphTest2) {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/digraph2.dot");
  auto res = alg.GetShortestPathBetweenVertices(g, 15, 12);
  ASSERT_EQ(res, alg.infinity);
}

TEST(GetShortestPathsBetweenAllVertices, GraphTest1) {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/graph1.dot");
  std::vector<std::vector<int>> res1 = {{0, 3, 4, 5, 9, 6, 11, 9, 15, 10, 12},
                                        {3, 0, 7, 2, 12, 3, 14, 6, 14, 7, 9},
                                        {4, 7, 0, 9, 5, 10, 7, 13, 11, 14, 16},
                                        {5, 2, 9, 0, 14, 1, 16, 4, 12, 5, 7},
                                        {9, 12, 5, 14, 0, 15, 2, 14, 6, 13, 11},
                                        {6, 3, 10, 1, 15, 0, 15, 3, 11, 4, 6},
                                        {11, 14, 7, 16, 2, 15, 0, 12, 4, 11, 9},
                                        {9, 6, 13, 4, 14, 3, 12, 0, 8, 1, 3},
                                        {15, 14, 11, 12, 6, 11, 4, 8, 0, 7, 5},
                                        {10, 7, 14, 5, 13, 4, 11, 1, 7, 0, 2},
                                        {12, 9, 16, 7, 11, 6, 9, 3, 5, 2, 0}};

  auto res2 = alg.GetShortestPathsBetweenAllVertices(g);

  ASSERT_EQ(res1.size(), res2.size());
  for (size_t i = 0; i < res1.size(); i++) {
    for (size_t j = 0; j < res1[0].size(); j++) {
      ASSERT_EQ(res1[i][j], res2[i][j].value());
    }
  }
}

TEST(GetShortestPathsBetweenAllVertices, GraphTest2) {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/graph2.dot");
  std::vector<std::vector<int>> res1 = {{0, 1, 3, 6, 10, 11, 9, 8, 11, 9, 5},
                                        {1, 0, 2, 5, 9, 10, 8, 7, 10, 10, 6},
                                        {3, 2, 0, 3, 7, 8, 6, 5, 8, 10, 8},
                                        {6, 5, 3, 0, 4, 5, 3, 2, 5, 7, 11},
                                        {10, 9, 7, 4, 0, 5, 7, 6, 9, 11, 15},
                                        {11, 10, 8, 5, 5, 0, 2, 3, 6, 8, 12},
                                        {9, 8, 6, 3, 7, 2, 0, 1, 4, 6, 10},
                                        {8, 7, 5, 2, 6, 3, 1, 0, 3, 5, 9},
                                        {11, 10, 8, 5, 9, 6, 4, 3, 0, 2, 6},
                                        {9, 10, 10, 7, 11, 8, 6, 5, 2, 0, 4},
                                        {5, 6, 8, 11, 15, 12, 10, 9, 6, 4, 0}};

  auto res2 = alg.GetShortestPathsBetweenAllVertices(g);

  ASSERT_EQ(res1.size(), res2.size());
  for (size_t i = 0; i < res1.size(); i++) {
    for (size_t j = 0; j < res1[0].size(); j++) {
      ASSERT_EQ(res1[i][j], res2[i][j].value());
    }
  }
}

TEST(GetShortestPathsBetweenAllVertices, DigraphTest1) {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/digraph1.dot");
  std::vector<std::vector<int>> res1 = {{0, 5, 6, 6, 9},
                                        {8, 0, 14, 1, 4},
                                        {9, 14, 0, 2, 5},
                                        {7, 12, 13, 0, 3},
                                        {4, 9, 10, 10, 0}};

  auto res2 = alg.GetShortestPathsBetweenAllVertices(g);

  ASSERT_EQ(res1.size(), res2.size());
  for (size_t i = 0; i < res1.size(); i++) {
    for (size_t j = 0; j < res1[0].size(); j++) {
      ASSERT_EQ(res1[i][j], res2[i][j].value());
    }
  }
}

TEST(GetShortestPathsBetweenAllVertices, DigraphTest2) {
  Graph g;
  GraphAlgorithms alg;
  g.LoadGraphFromFile("dots/digraph2.dot");
  std::vector<std::vector<int>> res1 = {
      {0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5},
      {0, 0, 0, 1, 1, 0, 0, 2, 0, 0, 3, 0, 0, 4, 0},
      {0, 0, 0, 0, 0, 1, 1, 0, 2, 2, 0, 3, 3, 0, 4},
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 3, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 3, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 3},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

  auto res2 = alg.GetShortestPathsBetweenAllVertices(g);

  ASSERT_EQ(res1.size(), res2.size());
  for (size_t i = 0; i < res1.size(); i++) {
    for (size_t j = 0; j < res1[0].size(); j++) {
      ASSERT_EQ(res1[i][j], res2[i][j].value_or(0));
    }
  }
}
