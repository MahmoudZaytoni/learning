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
    string a, b; cin >> a >> b;
    bool sub = false, sameletters = true;
    int sz1 = sz(a), sz2 = sz(b);
    if (sz1 >= sz2) {
      int j = 0; 
      for (int i = 0; i < sz1; i++) {
        if (a[i] == b[j])
          j++;
      }
      if (j == sz2)
        sub = true;
    }

    vector<int> freq(26);
    for (char c : a)
      freq[c-'a']++;
    
    for (int i = 0; i < sz2; i++) {
      int x = --freq[b[i]-'a'];
      if (x < 0)
        sameletters = false;
    }

    if (sub)
      cout << "automaton\n";
    else if (sameletters && sz1 == sz2)
      cout << "array\n";
    else if (sameletters)
      cout << "both\n";
    else {
      cout << "need tree\n";
    }
  }
  return 0;
}