#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int mid, int r) {
  int len1 = mid - l + 1;
  int len2 = r - mid;

  vector<int> L(len1), R(len2);

  for (int i = 0; i < len1; i++)
    L[i] = v[i + l];
  for (int i = 0; i < len2; i++)
    R[i] = v[i + mid + 1];

  int i = 0, j = 0, k = l;
  while (i < len1 and j < len2) {
    if (L[i] <= R[j])
      v[k++] = L[i++];
    else
      v[k++] = R[j++];
  }

  while (i < len1)
    v[k++] = L[i++];
  
  while (j < len2)
    v[k++] = R[j++];
}

void merge_sort(vector<int> &v, int l, int r) {
  if (l >= r)
    return;
  int mid = (l + r) / 2;
  merge_sort(v, l, mid);
  merge_sort(v, mid+1, r);
  merge(v, l, mid, r);
}

int main()
{
  vector<int> v{2, 1, 10, 15, 8, 9, 0, -2};
  merge_sort(v, 0, (int)v.size() - 1);
  for (auto &x : v)
    cout << x << " ";
  cout << "\n";
  return 0;
}