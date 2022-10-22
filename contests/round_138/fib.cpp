#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
  if (n <= 1)
    return 1;
  return fib(n - 1) + fib(n - 2);
}

int main()
{
  for (int i = 1; i < 60; i++)
    cout << i << " " << fib(i) << "\n";

}