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
  int n, k, l, r, sall, sk; cin >> n >> k >> l >> r >> sall >> sk;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++)
    v[i] = l;

  int sum = l * n;
  sall -= sum;
  int sumk = k * l;
  int leftk = sk - sumk;
  while (leftk) {
    for (int i = 1; i <= k && leftk; i++) {
      v[i]++;
      leftk--;
      sall--;
    }
  }
  while (sall) {
    for (int i = k + 1; i <= n && sall; i++) {
      v[i]++;
      sall--;
    }
  }
  for (int i = 1; i <= n; i++)
    cout << v[i] << " ";
  cout << "\n";
   

  
  cout << "\n";
  return 0;
}