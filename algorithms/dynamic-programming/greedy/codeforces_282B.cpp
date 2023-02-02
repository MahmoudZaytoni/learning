// B. Painting Eggs
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
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) 
    cin >> a[i] >> b[i];
  
  int s1 = 0, s2 = 0;
  string ans = "";
  for (int i = 0; i < n; i++) {
    s1 += a[i];
    char c = 'A';
    if (abs(s1 - s2) > 500) {
      s1 -= a[i];
      s2 += b[i];
      c = 'G';
    }
    ans += c;
  }
  cout << ans << "\n";
  return 0;
}