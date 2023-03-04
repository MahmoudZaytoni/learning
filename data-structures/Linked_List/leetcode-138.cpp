/****************************************************
 *** Problem Number : 138. Copy List with Random Pointer
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/copy-list-with-random-pointer/description/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
      unordered_map<Node*, int> list_idx;
      unordered_map<int, Node*> idx_list;

      Node* copyOriginal = head; 
      Node* headCopy = new Node(0); // dummy
      Node* ptr = headCopy;

      int idx = 0;
      while (head) {
        list_idx[head] = idx;
        ptr->next = new Node(head->val);
        ptr = ptr->next;
        idx_list[idx++] = ptr;
        head = head->next;
      }

      list_idx[nullptr] = idx;
      idx_list[idx] = nullptr;

      head = copyOriginal;
      ptr = headCopy->next;
      while (head) {
        Node* random = head->random;
        int random_idx = list_idx[random];
        ptr->random = idx_list[random_idx];
        head = head->next;
        ptr = ptr->next;
      }
      return headCopy->next;
    }
};