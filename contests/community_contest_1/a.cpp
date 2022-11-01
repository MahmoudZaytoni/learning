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
#ifndef ONLINE_JUDGE
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

   
    
    vector<int> ith, jth;
    for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) {
        while (a[i] != b[i]) {
          ith.push_back(i + 1);
          a[i]--;
        }
      } else if (b[i] > a[i]) {
        while (a[i] != b[i]) {
          jth.push_back(i + 1);
          a[i]++;
        }
      }
    }
    if (sz(jth) == sz(ith)) {
      cout << sz(jth) << "\n";
      for (int i = 0; i < sz(ith); i++) {
        cout << ith[i] << " " << jth[i] << "\n";
      }
    }
    else {
      cout << -1 << "\n";
    }
  }
  return 0;
}