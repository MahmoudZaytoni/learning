#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int start, int mid, int end) {
  vector<int> a;
  int i = start, j = mid + 1;
  int n = end;
  for (int k = start; k <= end; k++) {
    if (i > mid)
      a.push_back(v[j++]);
    else if (j > end)
      a.push_back(v[i++]);
    else if (v[i] < v[j])
      a.push_back(v[i++]);
    else if (v[j] < v[i])
      a.push_back(v[j++]);
  }
  for (int i = start, j = 0; i <= end; i++, j++)
    v[i] = a[j];
}

void merge_sort(vector<int> &v, int start, int end) {
  if (start == end)
    return;
  int mid = (start + end) / 2;
  merge_sort(v, start, mid);
  merge_sort(v, mid + 1, end);
    
  merge(v, start, mid, end);
}

int main()
{
  vector<int> v{5, 8, 2, 0, 100, 95};
  merge_sort(v, 0, (int)v.size() - 1);
  for (auto &x : v)
    cout << x << " ";
  cout << endl;
  return 0;
}