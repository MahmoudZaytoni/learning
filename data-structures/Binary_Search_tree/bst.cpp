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
public:
  BinarySearchTree(int val) : data(val), left(nullptr), right(nullptr) {
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
        left = new BinarySearchTree(target);
      left->insert(target);
    } else if (data < target) {
      if (!right)
        right = new BinarySearchTree(target);
      right->insert(target);
    }
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
