#include "Tree.hpp"

Tree::Tree() { root = nullptr; }

TreeNode *Tree::addNode(char key, float mvmt, TreeNode *troot) {
  if (troot == nullptr) {
    TreeNode *node = createNode(key, mvmt);
    troot = node;
    return troot;
  }

  if (troot->value->mvmt <= mvmt) {
    troot->left = addNode(key, mvmt, troot->left);
    troot->left->prev = troot;
  } else {
    troot->right = addNode(key, mvmt, troot->right);
    troot->right->prev = troot;
  }
  return troot;
}

void Tree::flatten(TreeNode *node) {
  if (node == nullptr || (node->left == nullptr && node->right == nullptr)) {
    return;
  }

  if (node->left != nullptr) {
    flatten(node->left);
    node->left->prev = node->prev;
    node->prev->right = node->left;

    TreeNode *tmp = node->left;
    while (tmp->right != nullptr) {
      tmp = tmp->right;
    }
    tmp->right = node;
    node->prev = tmp;
    node->left = nullptr;
  }

  flatten(node->right);
}

TreeNode *Tree::createNode(char key, float mvmt) {
  auto *node = new TreeNode;
  node->value = new TreeData;
  node->value->key = key;
  node->value->mvmt = mvmt;
  node->left = nullptr;
  node->right = nullptr;
  node->prev = nullptr;
  return node;
}
