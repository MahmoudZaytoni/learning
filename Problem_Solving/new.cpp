#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <cstring>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n;
int a[N], b[N], cnt[N];

bool sol(int i, int j) {
  if (i == n && j == n)
    return true;
  if (i == n + 1)
    return false;
  if (i < n && j < n && a[i] == b[j])
    return sol(i+1, j+1);
  if (j && b[j] == b[j-1] && cnt[b[j]]) {
    cnt[b[j]]--;
    return sol(i, j+1);
  }
  cnt[a[i]]++;
  return sol(i+1, j);
}
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]] = 0;
    }
    for (int j = 0; j < n; j++)
      cin >> b[j];
    cout << ((sol(0,0)) ? "YES\n" : "NO\n");
  }
  return 0;
}