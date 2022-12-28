#include <bits/stdc++.h>
using namespace std;

int make_pivot(vector<int> &v, int start, int end) {
  int mid = start + (end - start ) / 2;
  int pivot = v[mid];

  int counter = 0;
  for (int i = start; i <= end; i++) 
    if (v[i] < pivot)
      counter++;
  
  int pivot_idx = start + counter;
  swap(v[pivot_idx], v[mid]);

  int i = start, j = end;
  while (i < pivot_idx && pivot_idx < j) {
    while (v[i] < pivot)
      i++;
    while (v[j] > pivot)
      j--;
    if (i < pivot_idx && pivot_idx < j) {
      swap(v[i], v[j]);
    }

    i++, j--;
  }
  return pivot_idx;
}


int partition(vector<int> &v, int p, int r) {
  int x = v[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (v[j] <= x) {
      i++;
      swap(v[i], v[j]);
    }
  }
  swap(v[i+1], v[r]);
  return i + 1;
}
void quicksort(vector<int> &v, int start, int end) {
  if (start >= end)
    return;
  
  //int pivot_idx = make_pivot(v, start, end);
  int pivot_idx = partition(v, start, end);
  quicksort(v, start, pivot_idx-1);
  quicksort(v, pivot_idx+1, end);

}



int main()
{
  vector<int> v{5, 8, 2, 0, 100, 95};
  quicksort(v, 0, (int)v.size() - 1);
  for (auto &x : v)
    cout << x << " ";
  cout << endl;
  return 0;
}