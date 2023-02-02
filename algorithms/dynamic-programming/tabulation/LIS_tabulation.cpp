#include <bits/stdc++.h>
using namespace std;

const int MAX = 500;
int memory[MAX];

int lengthOfLIS(vector<int> &nums) {
  nums.insert(nums.end(), INT_MAX);

  memory[0] = 1;

  for (int i = 1; i < (int)nums.size(); i++) {
    auto &ret = memory[i];
    ret = 1;
    for (int j = i - 1; j >= 0; j++)
      if (nums[j] < nums[i])
        ret = max(ret, 1 + memory[j]);
  }
  return memory[nums.size() - 1] - 1;
}

int main()
{

  return 0;
}