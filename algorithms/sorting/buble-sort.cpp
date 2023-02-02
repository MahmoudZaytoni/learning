#include <bits/stdc++.h>
using namespace std;


int main()
{
  vector<int> v{2, 1, 10, 15, 8, 9, 0, -2};

  int n = v.size();
  for (int i = 0; i < n; i++) {
    bool swapped = false;
    for (int j = 0; j < n - 1 - i; j++) {
      if (v[j] > v[j+1]) {
        swap(v[j], v[j+1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }

  for (auto &x : v)
    cout << x << " ";
  cout << "\n";
  return 0;
}