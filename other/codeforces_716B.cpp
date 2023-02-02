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

bool can(vector<int> &freq, int cnt) {
  for (int i = 0; i < freq.size(); i++) {
    if (freq[i] == 1)
      cnt++;
  }
  return cnt == 26;
}

void fill(int i, vector<int> &freq, string &s) {
  for (int start = 0; start < 26; start++) {
    if (freq[start] == 0) {
      while(s[i] != '?')
        i++;
      s[i] = start + 'A';
    }
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '?')
      s[i] = 'A';
  }
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  //cin >> t;
  while (t--) {
    string s; cin >> s;
    if (sz(s) < 26) {
      cout << -1 << "\n";
      return 0;
    }

    vector<int> freq(26 + 1, 0);
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
      if (s[i] == '?')
        cnt++;
      else
        freq[s[i] - 'A']++;
    }
    int i = 0, j = 25;
    bool ok = false;
    while (j < sz(s)) {
      if (can(freq, cnt)) {
        ok = true;
        break;
      }
      if (s[i] == '?')
        cnt--;
      else 
        freq[s[i] - 'A']--; 

      i++;
      j++;
      if (j < sz(s)) {
        if (s[j] == '?')
          cnt++;
        else 
          freq[s[j] - 'A']++;
      }
    }
    if (ok) {
      fill(i, freq, s);
      cout << s << "\n";
    } else 
      cout << -1 << "\n";
  }
  return 0;
}