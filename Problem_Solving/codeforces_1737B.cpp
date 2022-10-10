// B. Ela's Fitness and the Luxury Number
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

ll count(ll n) {
  if (n == 1)
    return 1;
     
  ll sqr = sqrt(n);
  ll ans = sqr * 3;
  if (sqr * (sqr + 1) > n)
    ans--;
  if (sqr * (sqr + 2) > n)
    ans--;
  return ans;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    ll l, r; cin >> l >> r;
    cout << count(r) - count(l-1) << "\n";
  }
  return 0;
}