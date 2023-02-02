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

int cnt = 0;
bool found = false;
void get_all_subsets(string n, string &s, int idx = 0) {
  if (idx == s.size()) {
    cnt++;
    if (n == s) {
      cout << cnt - 1 << "\n";
      found = true;
    }
    return;
  }
  s[idx] = '4';
  get_all_subsets(n, s, idx+1);
  s[idx] = '7';
  get_all_subsets(n, s, idx+1);
  s[idx] = ' ';
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string n; cin >> n;
  for (int i = 0; i < 11; i++) {
    string s(i, ' ');
    get_all_subsets(n, s,0);
    if (found)
      break;
  } 
  return 0;
}