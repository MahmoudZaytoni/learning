#include <iostream>
using namespace std;

string res = "    "; // 4
void all_subsets(int idx) {
  if (idx == res.size()) {
    cout << res << "\n";
    return;
  }

  // try 0 for this idx
  res[idx] = 'a';
  all_subsets(idx+1);

  res[idx] = 'b';
  all_subsets(idx+1);

  res[idx] = 'c';
  all_subsets(idx+1);

  res[idx] = 'd';
  all_subsets(idx+1);

  res[idx] = ' ';
}

int main()
{
  all_subsets(0);
  return 0;
}