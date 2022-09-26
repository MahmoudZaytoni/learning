#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    for (auto &it : v) cin >> it;
    
    int i = 0, j = 0, mx_idx, mn_idx;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (n - i <= ans) break;
        int mx = v[i];
        int mn = v[i];
        int j = i;
        while(j < n && (max(mx, v[j]) - min(mn, v[j])) <= 1) {
            j++;
            mn = min(mn, v[j]);
            mx = max(mx, v[j]);
        }
        ans = max(ans, (j - i));
    }
    cout << ans << "\n";
    return 0;
}