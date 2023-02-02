#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
using namespace std;
const int MAX_SIZE = 1e9;
int dx[8] = {1,0,0,-1,1,1,-1,-1};
int dy[8] = {0,1,-1,0,1,-1,1,-1};

bool isValid(int r, int c) {
    if (r < 0 || c < 0 || r >= MAX_SIZE || c >= MAX_SIZE)
        return false;
    return true;
}

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    map<pair<int,int>,int> mp;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int r, from, to; cin >> r >> from >> to;
        for (;from<=to; from++)
            mp[{r,from}] = 1;
    }

    queue<pair<int,int>> q;
    q.push({a,b});
    mp[{a,b}]=0;
    int level = 0;
    bool ok = 0;
    for (int sz=1; !q.empty(); level++, sz = q.size()) {
        while (sz--) {
            pair<int,int> cur = q.front();
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nr = cur.first + dx[i], nc = cur.second + dy[i];
                if (!isValid(nr,nc) || mp[{nr,nc}] == 0)
                    continue;
                if (nr == c && nc == d) {
                    ok = 1;
                    goto s;
                }
                q.push({nr,nc});
                mp[{nr,nc}]=0;
            }
        }
    }
    s:
    if (ok) 
        cout << level + 1 << "\n";
    else 
        cout << -1 << "\n";
    return 0;
}