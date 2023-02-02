/****************************************************
 *** Problem Number : 72
 *** Diffculty      : Hard
 *** URL            : https://leetcode.com/problems/edit-distance/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 500 + 1;
int memory[MAX][MAX];

class Solution {
  string str1, str2;
  int mn(int idx1, int idx2) {
    if (idx1 >= str1.size()) // base case
      return str2.size() - idx2;
    if (idx2 >= str2.size()) // base case
      return str1.size() - idx1;

    auto &ret = memory[idx1][idx2];
    if (ret != -1) return ret;

    if (str1[idx1] == str2[idx2])
      return ret = mn(idx1 + 1, idx2 + 1);
    
    int change = 1 + mn(idx1 + 1, idx2 + 1);
    int delete_ = 1 +  mn(idx1 + 1, idx2);
    int insert = 1 + mn(idx1, idx2 + 1);

    return ret = min(change, min(delete_, insert));
  }

  void print_edit(int i, int j) {
    if (i == str1.size() && j == str2.size()) 
      return;
    
    if (i == str1.size()) {
      cout << "In" << str1 << " insert at the end " << str2.substr(j) << "\n";
      return;
    }

    if (j == str2.size()) {
      cout << "In" << str1 << " delete the last" << (int)str1.size() - i << " letters "   << str1.substr(i) << "\n";
      return;
    }

    if (str1[i] == str2[j]){
      print_edit(i+1,j+1);
      return;
    }

    int optimal = mn(i,j);

    int delete_ = 1 + mn(i+1,j);
    int insert = 1 + mn(i, j+1);

    if (optimal == delete_) {
      cout << "In " << str1 << " delete original idx " << i << " letter " << str1[i] << "\n";
      print_edit(i + 1, j);
    } else if (optimal == insert) {
      cout << "In " << str1 << " insert at original idx " << i << " letter " << str2[j] << "\n";
      print_edit(i,j+1);
    } else {
      cout << "In " << str1 << " change letter at original idx " << i << " letter " << str1[i] << " to letter " << str2[j] << "\n";
      print_edit(i+1, j+1);
    }
  }

public:
    int minDistance(string word1, string word2) {
        memset(memory, -1, sizeof(memory));
        str1 = word1, str2 = word2;
        print_edit(0,0);
        return mn(0,0);
    }
};

int main()
{
  Solution s;
  cout << s.minDistance("intention", "execution") << "\n";
  return 0;
}