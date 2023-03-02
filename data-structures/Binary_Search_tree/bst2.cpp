#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>

using namespace std;

class BinarySearchTree {
  int data;
  BinarySearchTree *left;
  BinarySearchTree *right;
  BinarySearchTree *parent;
public:
  BinarySearchTree(int val, BinarySearchTree* parent = nullptr) : data(val), left(nullptr), right(nullptr) {
  }

  	void print_inorder() {
      if (left)
        left->print_inorder();
      cout << data << " ";
      if (right)
        right->print_inorder();
    }


  void insert(int target) {
    if (data > target) {
      if (!left)
        left = new BinarySearchTree(target, this);
      left->insert(target);
    } else if (data < target) {
      if (!right)
        right = new BinarySearchTree(target, this);
      right->insert(target);
      right->parent = this;
    }
  }

  BinarySearchTree* find(int target) {
    if (target == data)
      return this; 

    if (data > target) {
      if (!left)
        return nullptr;
      left->find(target);
    }

    if (!right)
      return nullptr;
    return right->find(target);
  }

  int min_value() {
    BinarySearchTree* cur = this;
    while (cur && cur->left)
      cur = cur->left;
    return cur->data;
  }

  pair<bool, int> successor(int target) {
    BinarySearchTree *child = find(target);
    if (!child)
      return {false, -1};
    if (child->right)
      return {true, child->right->min_value()};
    
    BinarySearchTree* parent = child->parent;
    while (parent && parent->right == child)
      child = parent, parent = child->parent;
    
    if (parent)
      return {true, parent->data};
    return {false, -1};
  }

  bool search(int target) {
    if (target == data)
      return true;
    if (target < data)
      return left && left->search(target);
    return right && right->search(target);
  }
  
  bool search_iterative(int target) {
    BinarySearchTree *cur = this;
    while (cur) {
      if (cur->data > target)
        cur = cur->left;
      else if (cur->data < target)
        cur = cur->right;
      else
        return true;
    }
    return false;
  }
};

int main() {
  cout << boolalpha << "\n";
	BinarySearchTree tree(50);
	tree.insert(20);
	tree.insert(45);
	tree.insert(70);
	tree.insert(73);
	tree.insert(35);
	tree.insert(15);
	tree.insert(60);

	tree.print_inorder();

	cout << "bye\n";
  cout << tree.search(100) << tree.search_iterative(100);
	return 0;
}
