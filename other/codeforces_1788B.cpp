#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
using namespace std;

#ifndef ONLINE_JUDGE
    #include "/home/mahmoud/Desktop/debug.hpp"
#else
    #define debug(...)
    #define debug_itr(...)
    #define debug_bits(...)
#endif

typedef long long ll;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        bool flag = true;
        int x = 0, y = 0;
        int z = 1;
        while (n) {
            int d = n % 10;
            if (d % 2) {
                if (flag) {
                    x += ((d + 1) / 2) * z;
                    y += (d / 2) * z; 
                } else { 
                    y += ((d + 1) / 2) * z;
                    x += (d / 2) * z; 
                }
                flag ^= 1;
                debug(x, y);
            } else {
                x += (d/2) * z;
                y += (d/2) * z;
            }
            z *= 10;
            n /= 10;
       }
        cout << x << " " << y << "\n";

    }
    return 0;
}
