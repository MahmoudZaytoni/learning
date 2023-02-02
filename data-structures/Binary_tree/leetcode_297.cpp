/****************************************************
 *** Problem Number : 297. Serialize and Deserialize Binary Tree
 *** Diffculty      : Hard
 *** URL            : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

string toStr(int n) {
	// Convert integer to string
	ostringstream oss;
	oss << n;
	return oss.str();
}

int toInt(string n) {
  istringstream iss(n);
  int num;
  iss >> num;
  return num;
}

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      if (!root)
        return "()";
      string repr = "(" + toStr(root->val);
      if (root->left)
        repr += serialize(root->left);
      else
        repr += "()";
      
      if (root->right)
        repr += serialize(root->right);
      else
        repr += "()";
      repr += ")";
      return repr;
    }

    // Decodes your encoded data to tree.
    //(123(2()())(3))
    TreeNode* deserialize(string data) {
      if (data == "()")
        return NULL;
      int st = 1;
      while (data[st] != '(')
        st++;
      
      TreeNode* root = new TreeNode(toInt(data.substr(1, st-1)));
      int end = st + 1;
      stack<char> s;
      s.push(data[st]);
      while (!s.empty()) {
        if (data[end] == '(')
          s.push(data[end]);
        else if (data[end] == ')')
          s.pop();
        end++;
      }
      if (end > st + 2)
        root->left = deserialize(data.substr(st, end - st));
      
      st = end;
      end = st+1;
      s.push(data[st]);
      while (!s.empty()) {
        if (data[end] == '(')
          s.push(data[end]);
        else if (data[end] == ')')
          s.pop();
        end++;
      }

      if (end > st + 2)
        root->right = deserialize(data.substr(st, end - st));
      return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
int main()
{
  Codec c;
  
  cout << c.serialize(c.deserialize("(1(2()())(3()()))")) << "\n";
  cout << c.serialize(c.deserialize("()")) << "\n";

}