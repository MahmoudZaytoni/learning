/****************************************************
 *** Problem Number : 703. Kth Largest Element in a Stream
 *** Diffculty      : Easy
 *** URL            : https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    //priority_queue<int> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
      this->k = k;
      sort(nums.rbegin(), nums.rend());
      for (int i = 0; i < min(k, (int)nums.size()); i++)
        pq.push(nums[i]);
    }
    
    int add(int val) {
      if (k > pq.size())
        pq.push(val);
      else if (val > pq.top()) {
        pq.pop();
        pq.push(val);
      }
      return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */