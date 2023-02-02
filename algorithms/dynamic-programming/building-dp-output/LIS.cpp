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
int memory[MAX][MAX];
int LIS_V1(int idx, int prev_idx = 0) {
  if (idx == arr.size())
    return 0;

  auto &ret = memory[idx][prev_idx];
  if (ret != -1)
    return ret;

  int choice1 = LIS_V1(idx + 1, prev_idx); // leave it
  int choice2 = 0;
  if (prev_idx >= arr.size() || arr[idx] > arr[prev_idx]) // can pick it
    choice2 = 1 + LIS_V1(idx+1, idx);

  return ret = max(choice1, choice2);
}

void LIS_print(int idx, int prev_idx) {
  if (idx == arr.size())
    return;
  

	// Compute optimal and see which path generated it
  int optimal = LIS_V1(idx, prev_idx);

  int choice1 = LIS_V1(idx + 1, prev_idx); // leave it
  int choice2 = 0;
  if (prev_idx >= arr.size() || arr[idx] > arr[prev_idx]) // can pick it
    choice2 = 1 + LIS_V1(idx+1, idx);
  

  if (optimal == choice1)
    LIS_print(idx+1, prev_idx);
  else {
    cout << arr[idx] << " ";
    LIS_print(idx+1, idx);
  }
}


int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(memory, -1, sizeof(memory));
  
  LIS_print(0, arr.size());

  return 0;
}