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

TEST_F(GraphTest, GetCountVertices) {
  ASSERT_EQ(graph0_.GetCountVertices(), 0);
  ASSERT_EQ(graph1_.GetCountVertices(), 11);
  ASSERT_EQ(graph2_.GetCountVertices(), 5);
}
