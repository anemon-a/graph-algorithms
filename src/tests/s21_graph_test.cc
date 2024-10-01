#include "../s21_graph.h"

#include <gtest/gtest.h>

TEST(Constructor, default_constructor) { Graph g; }

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

TEST_F(GraphTest, VertexCountTest) {
  ASSERT_EQ(graph0_.GetVertexCount(), 0);
  ASSERT_EQ(graph1_.GetVertexCount(), 6);
  ASSERT_EQ(graph2_.GetVertexCount(), 5);
}

TEST_F(GraphTest, AdjacencyMatrixTest) {
  const std::vector<std::vector<int>> g1 = {
      {0, 2, 3, 0, 0, 0}, {2, 0, 0, 1, 0, 3}, {3, 0, 0, 0, 4, 5},
      {0, 1, 0, 0, 0, 0}, {0, 0, 4, 0, 0, 2}, {0, 3, 5, 0, 2, 0}};
  auto g2 = graph1_.GetAdjacencyMatrix();
  for (int i = 0; i < graph1_.GetVertexCount(); i++) {
    for (int j = 0; j < graph1_.GetVertexCount(); j++) {
      ASSERT_EQ(g1[i][j], g2[i][j]);
    }
  }

  const std::vector<std::vector<int>> dg1 = {{0, 5, 6, 0, 0},
                                             {0, 0, 0, 1, 0},
                                             {
                                                 0,
                                                 0,
                                                 0,
                                                 2,
                                                 0,
                                             },
                                             {0, 0, 0, 0, 3},
                                             {4, 0, 0, 0, 0}};
  auto dg2 = graph2_.GetAdjacencyMatrix();
  for (int i = 0; i < graph2_.GetVertexCount(); i++) {
    for (int j = 0; j < graph2_.GetVertexCount(); j++) {
      ASSERT_EQ(dg1[i][j], dg2[i][j]);
    }
  }
}