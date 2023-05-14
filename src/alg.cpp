// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::string word;
  std::ifstream text(filename);
  BST<std::string>* tree = new BST<std::string>;
  char str = ' ';
  while (!text.eof()) {
    while (str < 65 && (!text.eof())) {
      text.get(str);
    }
    while (str >= 65 && (!text.eof())) {
      if (str >= 65 && str <= 90) {
        word += str;
      }
      if (str >= 97 && str <= 122) {
        word += str;
      }
      text.get(str);
    }
    for (int i = 0; i < word.length(); i++) {
      if (word[i] >= 65 && word[i] <= 90)
        word[i] += 32;
    }
    (*tree).add(word);
    word = "";
  }
  return *tree;
}
