#ifndef VOXELOOP_AVLTREE_HPP
#define VOXELOOP_AVLTREE_HPP

#include "LinkedList.hpp"

typedef struct {
  char key;
  float mvmt;
} AVLData;

struct AVLNode {
  AVLData *value;
  struct AVLNode *left, *right;
  int height;
};

typedef struct AVLNode AVLNode;

class AVLTree {
public:
  AVLTree();

  AVLNode *root;
  AVLNode* addNode(char key, float mvmt, AVLNode* troot);
//  LinkedList <AVLData*> * inorderTraverse(AVLNode* node);
  void flatten(AVLNode* node);

  AVLNode* createNode(char key, float mvmt);

  int max(int a, int b);
  int getBalance(AVLNode* node);
  int height(AVLNode* node);

};

#endif // VOXELOOP_AVLTREE_HPP
