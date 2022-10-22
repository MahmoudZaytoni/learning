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

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    set<int> st;
    for (int i = 0; i < n; i++)
      st.insert(v[i]);
    if (n == 1) {
      cout << 1 << "\n";
      continue;
    }
    if (st.size() == 1 && n != 1) {
      cout << 0 << "\n";
      continue;
    }
    cout << st.size() << "\n";
  }
  return 0;
}