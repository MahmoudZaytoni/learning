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

void sol() {
  int n; cin >> n;
  if (n == 1) {
    cout << "0\n0\n0\n";
    return;
  }

  if (n % 2 == 0) {
    cout << -1 << "\n";
    return;
  }

  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++)
    a[i] = i;
  
  int k = 0;
  for (int i = n - 1; i >= n / 2; i--) {
    b[i] = k;
    k += 2;
  }
  k = 1;
  for (int i = n / 2 - 1; i >= 0; i--) {
    b[i] = k;
    k += 2;
  }

  for (int i = 0; i < n; i++)
    c[i] = (a[i] + b[i]) % n;

  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << "\n";
  for (int j = 0; j < n; j++)
    cout << b[j] << " ";
  cout << "\n";
  for (int k = 0; k < n; k++)
    cout << c[k] << " ";
  cout << "\n";
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  sol();
  return 0;
}