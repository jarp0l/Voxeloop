#include "Tree.hpp"

Tree::Tree() {
  root = nullptr;
}

TreeNode* Tree::addNode(char key, float mvmt, TreeNode* troot) {
  if (troot == nullptr) {
    TreeNode* node = createNode(key, mvmt);
    troot = node;
    return troot;
  }

  if (troot->value->mvmt < mvmt) {
    troot->left = addNode(key, mvmt, troot->left);
  } else {
    troot->right = addNode(key, mvmt, troot->right);
  }
  return troot;
}

void Tree::flatten(TreeNode* node) {
  if (node == nullptr || (node->left == nullptr && node->right == nullptr)) {
    return;
  }

  if (node->left != nullptr) {
    flatten(node->left);

    TreeNode* tmpRight = node->right;
    node->right = node->left;
    node->left = nullptr;

    TreeNode* tmp = node->right;
    while (tmp->right != nullptr) {
      tmp = tmp->right;
    }
    tmp->right = tmpRight;
  }

  flatten(node->right);
}

TreeNode* Tree::createNode(char key, float mvmt) {
  auto *node = new TreeNode;
  node->value = new TreeData;
  node->value->key = key;
  node->value->mvmt = mvmt;
  node->left = nullptr;
  node->right = nullptr;
  return node;
}



