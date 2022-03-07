#ifndef VOXELOOP_TREE_HPP
#define VOXELOOP_TREE_HPP

#include "LinkedList.hpp"

typedef struct {
  char key;
  float mvmt;
} TreeData;

struct TreeNode {
  TreeData *value;
  struct TreeNode *left, *right;
};

typedef struct TreeNode TreeNode;

class Tree {
public:
  Tree();

  TreeNode *root;
  TreeNode *addNode(char key, float mvmt, TreeNode *troot);
  void flatten(TreeNode *node);

  TreeNode *createNode(char key, float mvmt);
};

#endif // VOXELOOP_AVLTREE_HPP
