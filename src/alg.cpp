// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::vector<char> nullvc;
  if (n > tree.list.size())
    return nullvc;
  else
    return tree.list[n - 1];
}
