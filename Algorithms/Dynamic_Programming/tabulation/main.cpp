/****************************************************
 *** Problem Number : 
 *** Diffculty      : 
 *** URL            : 
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int memory[MAX];
int LIS(vector<int> &v) {
  v.insert(v.end(), INT_MAX);
  memory[0] = 1;
  for (int i = 1; i < (int)v.size(); i++) {
    auto &ret = memory[i];
    ret = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (v[i] > v[j])
        ret = max(ret, 1 + memory[j]);
    }
  }
  return memory[(int)v.size() - 1] - 1;
}


int main()
{

  return 0;
}