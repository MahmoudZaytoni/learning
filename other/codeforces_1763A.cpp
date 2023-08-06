#include <iostream>
#include <algorithm>
#include <vector>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
using namespace std;
typedef long long ll;

int main() 
{
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    int o = 0, a = *max_element(all(v));
    for (int i = 0; i < n; i++) {
      a &= v[i];
      o |= v[i];
    }
    cout << o - a << "\n";
  }
  return 0;
}
