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
    string s; cin >> s;
    char m = s.back();
    for (int i = (int)s.size() - 2; i >= 0; i--) {
      if (s[i] > m)
        s[i] = min(s[i]-'0'+1, 9) + '0';
      m = min(s[i], m);
    }
    sort(all(s));
    cout << s;
    cout << "\n";
  }
  return 0;
}