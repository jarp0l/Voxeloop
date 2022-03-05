#ifndef VOXELOOP_LINKEDLIST_HPP
#define VOXELOOP_LINKEDLIST_HPP


template <class T>
struct Node{
  T data;
  struct Node <T> *next;
};

template <class T>
class LinkedList {
public:
  struct Node <T> *head;
  LinkedList(){
    head = nullptr;
  }
  void addData(T data) {
    struct Node <T> *node = newNode(data);
    struct Node <T> *temp = head;

    if (head == nullptr) {
      head = node;
      return;
    }

    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = node;
  }



private:
  struct Node <T>* newNode(T data) {
    auto *node = new struct Node <T>;
    node->data = data;
    node->next = nullptr;
    return node;
  }
};

#endif // VOXELOOP_LINKEDLIST_HPP
