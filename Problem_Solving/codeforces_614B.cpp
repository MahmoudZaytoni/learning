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

bool isBeautiful(string &s, int idx) {
  if (idx == s.size())
    return true;

  if (idx == 0 && s[idx] != '1')
    return false;
  
  if (idx != 0 && s[idx] != '0')
    return false;
  
  return isBeautiful(s, idx+1);
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  //cin >> t;
  s:while (t--) {
    int n; cin >> n;
    int zeros = 0;
    string unBeautiful = "1";
    for (int i = 0; i < n; i++) {
      string str; cin >> str;
      if (str == "0") {
        cout << 0 << "\n";
        goto s;
      }
      if (isBeautiful(str, 0))
        zeros += (int)str.size() - 1;
      else 
        unBeautiful = str;
    }
    cout << unBeautiful << string(zeros, '0') << "\n";

  }
  return 0;
}