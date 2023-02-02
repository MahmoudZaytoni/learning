#include <bits/stdc++.h>
using namespace std;

vector<int> arr{10,9,2,5,3,7,101,18};
const int MAX = 2500 + 1;
int memory[MAX];

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

void LIS_V2_Print(int idx) {
  if (idx == arr.size())
    return;
  

  if (idx)  
    cout << arr[idx] << " ";

  int optimal = LIS(idx);
  for (int i = idx + 1; i < (int)arr.size(); i++) {
    if (arr[idx] < arr[i]) {
      if (optimal == 1 + LIS(i)) {
        LIS_V2_Print(i);
        return;
      }
    }
  }
}
class Solution {

public:
    /*
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
    */

    // Code imporvement
    int lengthOfLIS(vector<int>& nums) {
      memset(memory, -1, sizeof(memory));
      arr = nums;

      arr.insert(arr.begin(), INT_MIN);
      LIS_V2_Print(0);
      return LIS(0) - 1;
    }
};
int main(){
  Solution s;
  s.lengthOfLIS(arr);
  return 0;
}