// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <iostream>
class Tree {
 public:
  struct Node {
    char value;
    std::vector<Node*> child;
  };
  std::vector<std::vector<char>> list;

 private:
  Node* root;
  Node* addNode(Node*, std::vector<char>, char, std::vector<char>);
     
 public:
  Tree(std::vector<char>);
};
Tree :: Tree(std::vector<char> val) {
  std::vector<char> ps;
  root = new Node();
  root->value = '*';
  root->child.resize(val.size(), nullptr);
  for (auto i = 0; i < root->child.size(); i++)
	  root->child[i]=addNode(root->child[i], val, val[i], ps);
}
Tree :: Node* Tree :: addNode(Node* node, std::vector<char> vec, char vNode, std::vector<char> ps) {
  std::vector<char> vec_1;
  for (auto y = 0; y < vec.size(); y++) {
	  if (vec[y] != vNode)
      vec_1.push_back(vec[y]);
  }
  node = new Node;
  node->value = vNode;
  node->child.resize(vec_1.size(), nullptr);
  ps.push_back(vNode);
  if (vec_1.size() > 0) {
    for (auto i = 0; i < vec_1.size(); i++)
      node->child[i] = addNode(node->child[i], vec_1, vec_1[i], ps);
  } else {
    list.push_back(ps);
  }
  return node;
}
#endif  // INCLUDE_TREE_H_
