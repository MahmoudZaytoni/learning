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
    int n; cin >> n;
    int a1; cin >> a1;
    int x;
    for (int i = 1; i < n; i++)
      cin >> x;
    if (a1 != 1)  
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}