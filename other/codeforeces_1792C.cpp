// D. Friends and the Restaurant
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n), c(n);
        for (auto &it : a) cin >> it;
        for (auto &it: b) cin >> it;
        for (int i = 0; i < n; i++) {
            c[i] = b[i] - a[i];
        }
        sort(c.begin(), c.end());
        int st = 0, en = n - 1, ans = 0;
        while (st < en) {
            if (c[st] + c[en] >= 0)
                en--, ans++;
            st++;
        }
        cout << "ans: " << ans << "\n";
    }
    return 0;
}