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
  //cin >> t;
  while (t--) {
    string s; cin >> s;
    vector<int> freq(26);
    for (auto c : s) freq[c-'a']++;
    int cnt = 0;
    for (int i = 0; i < 26; i++)
      if (freq[i] & 1) cnt++;
    if (cnt <= 1 || cnt & 1)
      cout << "First\n";
    else 
      cout << "Second\n";
  }
  return 0;
}