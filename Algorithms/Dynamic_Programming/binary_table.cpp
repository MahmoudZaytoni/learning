#include <iostream>
using namespace std;

string res = "    "; // length 4
// Generate all possible subsets of length of the string
void all_subsets(int idx) {
  if (idx == res.size()) {
    cout << res << "\n";
    return;
  }

  // try 0 for this idx
  res[idx] = '0';
  all_subsets(idx+1);

  res[idx] = '1';
  all_subsets(idx+1);

  res[idx] = ' ';
}

int main()
{
  all_subsets(0);
  return 0;
}