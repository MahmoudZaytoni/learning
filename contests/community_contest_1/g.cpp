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
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  int t = 1;
  //cin >> t;
  while (t--) { 
    ll a, b, c; cin >> a >> b >> c;
    cout << ((a + c - 1)/ c) * ((b + c - 1) / c) << "\n";
  } 
  return 0;
}