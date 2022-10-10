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
  string s; cin >> s;
  string pre, rest;
  int n = s.find('2');
  if (n != -1) {
    pre = s.substr(0, n);
    s = s.substr(n);
  }
  for (int i = 0; i < (int)s.length(); i++) {
    if (s[i] == '2' || s[i] == '0' && n != -1)
      rest.push_back(s[i]);
    else
      pre.push_back(s[i]);
  }
  sort(all(pre));
  cout << pre << rest << "\n";
  return 0;
}