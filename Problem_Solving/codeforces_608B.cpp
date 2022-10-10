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
  string a, b; cin >> a >> b;
  int sz1 = sz(a), sz2 = sz(b);
  ll ans = 0;
  vector<int> pref(b.size()+1);

  for (int i = 0; i < b.size(); i++) 
    pref[i+1] = (b[i]-'0') + pref[i];
  
  for (int i = 0; i < sz1; i++) {
    if (a[i] == '0')
      ans += pref[sz2 - sz1 + i + 1] - pref[i];
    else
      ans += abs(pref[sz2 - sz1 + i + 1] - pref[i] - (sz2 - sz1 + 1));
  }
  cout << ans << "\n";
  return 0;
}