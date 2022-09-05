#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll n, q; cin >> n >> q;
        vector<vector<ll>> arr(1002, vector<ll>(1002)), pref(1002, vector<ll>(1002));
        while (n--) {
            ll h, w; cin >> h >> w;
            arr[h][w] += h * w;
        }
        for (ll i = 1; i <= 1001; i++) {
            for (ll j = 1; j <= 1001; j++) {
                pref[i][j] = arr[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }
        while (q--) {
            ll a,b,c,d;
            cin >> a >> b >> c >> d;
            a++, b++, c--, d--;
            cout << pref[c][d] - pref[a-1][d] - pref[c][b-1] + pref[a-1][b-1] << "\n";
        }
    }
    return 0;
}
