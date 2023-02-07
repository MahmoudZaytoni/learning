/****************************************************
 *** Problem Title  : 904. Fruit Into Baskets 
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/fruit-into-baskets/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      int start = 0, end = 0;
      int mx_fruits = 0;
      map<int,int> basket;
      while (end < fruits.size()) {
        basket[fruits[end]]++;
        while (basket.size() > 2) {
          basket[fruits[start]]--;
          if (!basket[fruits[start]])
            basket.erase(fruits[start]);
          start++;
        }
        end++;
        mx_fruits = max(mx_fruits, end - start);
      }
      return mx_fruits;
    }
};

int main()
{
  Solution s;
  vector<int> v{3,3,3,1,2,1,1,2,3,3,4};
  cout << s.totalFruit(v) << "\n";
  return 0;
}