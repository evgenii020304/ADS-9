// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <stdlib.h>
#include <iostream>
using namespace std;

template<typename T>
class bst {
 public:
  struct Node {
    T value;
    int count;
    Node* left;
    Node* right;
  };

 private:
  Node* root;
  Node* addNode(Node*, T);
  void printTree(Node*)const;
  int heightTree(Node*);
  int searchNode(Node*, T);
  void delTree(Node*);
  Node* delNode(Node*, T);
  Node* copyNode(Node*, Node*);

 public:
  bst();
  ~bst();	
  bst(const bst<T>& temp);
  void add(T);
  void print();
  int  height();
  int  search(T);
  void clear();
  void remove(int value);
};

template<typename T>
typename bst<T>::Node* bst<T>::addNode(Node* root, T value) {
  if (root == nullptr) {
    root = new Node;
    root->value = value;
    root->left = root->right = nullptr;
    root->count = 1;
  } else  if (root->value > value) {
    root->left = addNode(root->left, value);
  }	else if (root->value < value) {
    root->right = addNode(root->right, value);
  } else {
    root->count++;
  }
  return(root);
}

template<typename T>
void bst<T>::printTree(Node*) const {
  if (root == nullptr) {
    return;
  }
  printTree(root->left);
  for (int i = 0; root->count; i++) {
    std::cout << root->value << " ";
  }
  printTree(root->right);
}

template<typename T>
int bst<T>::heightTree(Node* root) {
  if (root == nullptr) {
    return 0;
  } else {
    return 1 + max(heightTree(root->left), heightTree(root->right));
  }
}

template<typename T>
int bst<T>::searchNode(Node* root, T value) {
  if (root == nullptr) {
    return 0;
  } else  if (root->value > value) {
    return searchNode(root->left, value);
	} else if (root->value < value) {
    return searchNode(root->right, value);
  } else {
    return root->count;
  }
}

template<typename T>
void bst<T>::delTree(Node*) {
  if (root == nullptr) {
    return;
  }
  else {
    delTree(root->left);
    delTree(root->right);
    delete root;
    root = nullptr;
  }
}

template<typename T>
typename bst<T>::Node* bst<T>::delNode(Node* root, T value) {
  Node* p, * v;
  if (root == nullptr) {
    return root;
  } else  if (value < root->value) {
    root = delNode(root->left);
  } else if (value > root->value) {
    root = delNode(root->right);
	} else {
    p = root;
    if (root->right == nullptr) {
      root = root->left;
    } else if (root->left == nullptr) {
			root = root->right;
    } else {
      v = root->left;
      if (v->right) {
        while (v->right->right) {
          v = v->right;
        }
        root->value = v->right->value;
        root->count = v->right->count;
        p = v->right;
        v->right = v->right->left;
      } else {
        root->value = v->value;
        root->count = v->count;
        p = v;
        root->left = root->left->left;
      }
    }
    delete p;
  }
  return root;
}

template<typename T>
typename bst<T>::Node* bst<T>::copyNode(Node* root, Node* temp) {
  if (temp != nullptr) {
    root = new Node;
    root->value = temp->value;
    root->count = temp->count;
    root->left = root->right = nullptr;
    root->left = copyNode(root->left, temp->left);
    root->right = copyNode(root->right, temp->right);
  }
  return root;
}

template<typename T>
bst<T>::bst() : root(nullptr){}

template<typename T> 
bst<T>:: ~bst() {
  if (root) {
    delTree(root);
  }
  root = nullptr;
}

template<typename T>
bst<T>::bst(const bst<T>& temp) {
  root = new Node;
  root->value = temp.root->value;
  root->count = temp.root->count;
  root->left = root->right = nullptr;
  root->left = copyNode(root->left, temp.root->left);
  root->right = copyNode(root->right, temp.root->right);
}

template<typename T>
void bst<T>::add(T value) {
  root = addNode(root, value);
}

template<typename T>
void bst<T>::print() {
  printTree(root);
}

template<typename T>
int bst<T>::height() {
  return heightTree(root);
}

template<typename T>
int bst<T>::search(T value) {
  return searchNode(root, value);
}

template<typename T>
void bst<T>::clear() {
  if (root) {
    delTrre(root);
    root = nullptr;
  }
}

template<typename T>
void bst<T>::remove(int value) {
  if (root) {
    root = delNode(root, value);
  }
}

#endif  // INCLUDE_BST_H_
