#include "../s21_graph.h"

#include <gtest/gtest.h>

TEST(Constructor, default_constructor) { Graph g; }

// Тесты AddEdge, Add vertices, GetEdgeWeight и др. с нулевым графом

class GraphTest : public testing::Test {
 protected:
  GraphTest() {
    graph1_.LoadGraphFromFile("dots/graph0.dot");
    graph2_.LoadGraphFromFile("dots/digraph0.dot");
  }
  Graph graph0_;
  Graph graph1_;
  Graph graph2_;
};

TEST_F(GraphTest, ZeroGraphTest) { ASSERT_EQ(graph0_.GetVertexCount(), 0); }

TEST_F(GraphTest, GraphTest) {
  const std::vector<std::vector<size_t>> g1 = {
      {0, 2, 3, 0, 0, 0}, {2, 0, 0, 1, 0, 3}, {3, 0, 0, 0, 4, 5},
      {0, 1, 0, 0, 0, 0}, {0, 0, 4, 0, 0, 2}, {0, 3, 5, 0, 2, 0}};
  auto g2 = graph1_.GetAdjacencyMatrix();

  ASSERT_EQ(graph1_.GetVertexCount(), g1.size());
  for (size_t i = 0; i < graph1_.GetVertexCount(); i++) {
    for (size_t j = 0; j < graph1_.GetVertexCount(); j++) {
      ASSERT_EQ(g1[i][j], g2[i][j]);
    }
  }
}

TEST_F(GraphTest, DigraphTest) {
  const std::vector<std::vector<int>> g1 = {{0, 1, 1, 0, 0},
                                            {0, 0, 0, 1, 0},
                                            {
                                                0,
                                                0,
                                                0,
                                                1,
                                                0,
                                            },
                                            {0, 0, 0, 0, 1},
                                            {0, 0, 0, 0, 0}};
  auto g2 = graph2_.GetAdjacencyMatrix();

  ASSERT_EQ(graph2_.GetVertexCount(), g1.size());
  for (size_t i = 0; i < graph2_.GetVertexCount(); i++) {
    for (size_t j = 0; j < graph2_.GetVertexCount(); j++) {
      ASSERT_EQ(g1[i][j], g2[i][j]);
    }
  }
}

TEST_F(GraphTest, GetNeighbourVertices_Graph) {
  std::vector<int> neigbours_v1 = {2, 3};
  auto res_v1 = graph1_.GetNeighbourVertices(1);
  for (size_t i = 0; i < res_v1.size(); i++) {
    ASSERT_EQ(neigbours_v1[i], res_v1[i]);
  }

  std::vector<int> neigbours_v6 = {2, 3, 5};
  auto res_v6 = graph1_.GetNeighbourVertices(6);
  for (size_t i = 0; i < res_v1.size(); i++) {
    ASSERT_EQ(neigbours_v1[i], res_v1[i]);
  }
}

TEST_F(GraphTest, GetNeighbourVertices_Digraph) {
  std::vector<int> neigbours_v1 = {2, 3};
  auto res_v1 = graph2_.GetNeighbourVertices(1);
  for (size_t i = 0; i < res_v1.size(); i++) {
    ASSERT_EQ(neigbours_v1[i], res_v1[i]);
  }

  std::vector<int> neigbours_v5 = {1};
  auto res_v6 = graph2_.GetNeighbourVertices(5);
  for (size_t i = 0; i < res_v1.size(); i++) {
    ASSERT_EQ(neigbours_v1[i], res_v1[i]);
  }
}

TEST_F(GraphTest, GetAllVertices_Graph) {
  std::vector<int> res_v1 = {1, 2, 3, 4, 5, 6};
  auto res_v2 = graph1_.GetAllVertices();
  for (size_t i = 0; i < res_v1.size(); i++) {
    ASSERT_EQ(res_v1[i], res_v2[i]);
  }
}

TEST_F(GraphTest, GetAllVertices_Digraph) {
  std::vector<int> res_v1 = {1, 2, 3, 4, 5};
  auto res_v2 = graph2_.GetAllVertices();
  for (size_t i = 0; i < res_v1.size(); i++) {
    ASSERT_EQ(res_v1[i], res_v2[i]);
  }
}