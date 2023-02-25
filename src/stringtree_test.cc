#include <gtest/gtest.h>
#include <string>

#include "stringtree.h"

using namespace std;
using namespace StringTree;

// Instantiate, check 
TEST(StringTreeTest, TreeNewDestroy) {
  Tree<uint> *t = new Tree<uint>();
  delete t;
}

TEST(StringTreeTest, NodeNewDestroy) {
  Node<uint> *t = new Node<uint>('h');

  t->deleteAll();
}


TEST(StringTreeTest, NodeAddFind) {
  Node<uint> *t = new Node<uint>('m', 13);
  t->add('g',7);
  t->add('n',14);
  t->add('x',24);
  t->add('b',2);
  Node<uint> *te = t->add('e',5);
  t->add('t',20);

  EXPECT_TRUE(t->find('a') == nullptr);
  EXPECT_TRUE(t->find('c') == nullptr);
  EXPECT_TRUE(t->find('z') == nullptr);
  
  EXPECT_TRUE(t->find('m') != nullptr);
  EXPECT_TRUE(t->find('e') != nullptr);
  EXPECT_TRUE(t->find('t') != nullptr);

  EXPECT_EQ(t->find('m')->value, 13);
  EXPECT_EQ(t->find('e')->value, 5);
  EXPECT_EQ(t->find('t')->value, 20);

  EXPECT_EQ(t->add('m',13), t);
  EXPECT_EQ(t->add('e',5), te);

  t->deleteAll();
}

TEST(StringTreeTest, SetGet) {
  Tree<uint> *t = new Tree<uint>();

  t->set("twenty five",25);

  t->set("twenty four",24);
  t->set("one",1);
  t->set("fifteen",15);
  t->set("six",6);
  t->set("forty two",42);

  EXPECT_EQ(t->get("forty two"), 42);

  // t->clear("forty two");

  // EXPECT_EQ(t->get("forty two"), 0);

  delete t;
}
