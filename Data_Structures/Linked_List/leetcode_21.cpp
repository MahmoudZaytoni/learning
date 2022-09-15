// 21. Merge Two Sorted Lists
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        
        int val1 = list1->val;
        int val2 = list2->val;
        
        ListNode* ptr = new ListNode();
        if (val1 < val2) {
            ptr = list1;
            list1 = list1->next;
        }
        else {
            ptr = list2;
            list2 = list2->next;
        }
        ListNode* head = ptr;
        ptr = ptr->next;
        while (list1 && list2) {
            val1 = list1->val;
            val2 = list2->val;

            if (val1 < val2) {
                ptr = list1;    
                list1 = list1->next;
            } 
            else {
                ptr = list2;
                list2 = list2->next;
            }
            
            ptr = ptr->next;
        }
        
        return head;
    }
};

class Solution_Recursiv {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};