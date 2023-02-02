#include <bits/stdc++.h>
using namespace std;

const int MAX = 500;
int memory[MAX][MAX];

int lengthOfLIS(vector<int> &nums) {
  int n = nums.size();
  memset(memory, -1, sizeof(memory));

  for (int i = n - 1; i >= 0; i--) {
    for (int prev = 0; prev <= i; prev++) {
      if (prev == i)
        prev = n;
      
      if (i == n - 1) {
        if (prev == n || nums[prev] < nums[i])
          memory[i][prev] = 1;
        else
          memory[i][prev] = 0;
      } else {
        int choice1 = memory[i + 1][prev];
        int choice2 = 0;

        if (prev == n || nums[prev] < nums[i])
          choice2 = 1 + memory[i + 1][prev];

        memory[i][prev] = max(choice1, choice2);
      }
    }
  }
  
  return memory[0][n];
}

int main()
{

  return 0;
}