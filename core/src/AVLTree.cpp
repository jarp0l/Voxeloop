#include "AVLTree.hpp"

AVLTree::AVLTree() {
  root = nullptr;

}

AVLNode* AVLTree::addNode(char key, float mvmt, AVLNode* troot) {
  if (troot == nullptr) {
    AVLNode* node = createNode(key, mvmt);
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

//LinkedList<AVLData *>* AVLTree::inorderTraverse(AVLNode* node) {
//  auto *list = new LinkedList <AVLData*>;
//
//  if (node->left != nullptr)
//    list->addData(inorderTraverse(node->left)->head->data);
//  //      inorder(node->left);
//  list->addData(node->value);
//  if (node->right != nullptr)
//    list->addData(inorderTraverse(node->right)->head->data);
//  //      inorder(node->right);
////  return traverseList;
//  return list;
//
////  return  traverseList;
//}

void AVLTree::flatten(AVLNode* node) {
  if (node == nullptr || (node->left == nullptr && node->right == nullptr)) {
    return;
  }

  if (node->left != nullptr) {
    flatten(node->left);

    AVLNode* tmpRight = node->right;
    node->right = node->left;
    node->left = nullptr;

    AVLNode* tmp = node->right;
    while (tmp->right != nullptr) {
      tmp = tmp->right;
    }
    tmp->right = tmpRight;
  }

  flatten(node->right);
}

AVLNode* AVLTree::createNode(char key, float mvmt) {
  auto *node = new AVLNode;
  node->value = new AVLData;
  node->value->key = key;
  node->value->mvmt = mvmt;
  node->left = nullptr;
  node->right = nullptr;
  node->height = 0;
  return node;
}

int AVLTree::max(int a, int b) { return a>b?a:b; }

int AVLTree::getBalance(AVLNode *node) {
  if (node == nullptr) return 0;
  return height(node->left) - height(node->right);
}

int AVLTree::height(AVLNode *node) {
  if (node == nullptr) return 0;
  return 1 + max(height(node->left), height(node->right));
}


