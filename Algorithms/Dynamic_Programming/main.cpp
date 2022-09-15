#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
using namespace std;
typedef long long ll;

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin >> s;
  int i = 0, j = (int)s.size() - 1;
  while (i <= j) {
    if (s[i] == '?' && s[j] == '?') {
      s[i] = s[j] = 'a';
    } else if (s[i] == '?') {
      s[i] = s[j];
    } else if (s[j] == '?'){
      s[j] = s[i];
    } else if (s[i] != s[j]) {
      cout << -1 << "\n";
      goto s;
    }
    i++, j--;
  }
  cout << s << "\n";
  s:
  return 0;
}