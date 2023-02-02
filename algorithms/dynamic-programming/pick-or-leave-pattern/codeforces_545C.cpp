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

int n;
const int MAX = 1e5 + 5;
pair<int,int> tree[MAX];
int dp[MAX][2];

int maxSeqment(int idx, int left, int prv) {
  if (idx == n)
    return 0;
  if (idx == n - 1)
    return 1;

  int &ret = dp[idx][left];
  if (~ret) return ret;
  ret = 0;

  int choice1 = 0, choice2 = 0; // 1- left, 2- right

  int pos = tree[idx].first, height = tree[idx].second;
  if (pos - height > prv)
    choice1 = 1 + maxSeqment(idx + 1, 0, pos);
  //else
  //  choice1 = maxSeqment(idx + 1, 0, pos);
  
  if (idx + 1 < n && pos + height < tree[idx+1].first)
    choice2 = 1 + maxSeqment(idx + 1, 1, pos + height);

  return ret = max(choice1, choice2);
}



int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, h; cin >> x >> h;
    tree[i] = make_pair(x, h);
  }
  memset(dp, -1, sizeof(dp));
  cout <<  maxSeqment(0, 0, -2e9) << "\n";
  return 0;
}