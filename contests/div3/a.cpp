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


map<char, int> mp;
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  mp['S'] = -1;
  mp['M'] = 1;
  mp['L'] = 2;
  while (t--) {
    string a, b;
    cin >> a >> b;
    char x = a.back(), y = b.back();
    int l1 = sz(a) - 1 , l2 = sz(b) - 1;

    l1 = (l1 * mp[x]), l2 = (l2 * mp[y]);
    if (x != y)
      cout << ((mp[x] < mp[y]) ? '<' : (mp[x] > mp[y]) ? '>' : '=');
    else 
      cout << ((l1 < l2) ? '<' : (l1 > l2) ? '>' : '=');
    cout << "\n";
  }
  return 0;
}