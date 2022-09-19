#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <climits>
#include <cstring>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
using namespace std;
typedef long long ll;

vector<int> arr{10,9,2,5,3,7,101,18};
const int MAX = 2500 + 1;
// int memory[MAX][MAX];
// int LIS_V1(int idx, int prev_idx = 0) {
//   if (idx == arr.size())
//     return 0;

//   auto &ret = memory[idx][prev_idx];
//   if (ret != -1)
//     return ret;

//   int choice1 = LIS_V1(idx + 1, prev_idx); // leave it
//   int choice2 = 0;
//   if (prev_idx >= arr.size() || arr[idx] > arr[prev_idx]) // can pick it
//     choice2 = 1 + LIS_V1(idx+1, idx);

//   return ret = max(choice1, choice2);
// }


int memory[MAX];
class Solution {
  int LIS(int idx) {
    if (idx == arr.size())
      return 0;

    auto &ret = memory[idx];
    if (ret != -1)
      return ret;
    
    ret = 0;
    for (int i = idx + 1; i < (int)arr.size(); i++)
      if (arr[idx] < arr[i])
        ret = max(ret, LIS(i));
    ret += 1;
    return ret;
  }


public:
    int lengthOfLIS(vector<int>& nums) {
        memset(memory, -1, sizeof(memory));
        arr = nums;

        int ret = 0;
        for (int j = 0; j < nums.size(); j++) {
          int start = LIS(j);
          ret = max(ret, start);
        }

        return ret;
    }

    // Code imporvement
    int lengthOfLIS(vector<int>& nums) {
      memset(memory, -1, sizeof(memory));
      arr = nums;

      arr.insert(arr.begin(), INT_MIN);
      return LIS(0) - 1;
    }
};

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(memory, -1, sizeof(memory));
  // cout << LIS_V1(0, arr.size());

  return 0;
}