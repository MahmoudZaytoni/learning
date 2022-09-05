// 365. Water and Jug Problem

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#define OO 1e9
using namespace std; 

class Solution {
    typedef unordered_map<int,unordered_set<int>> HASHSET;
    bool process(int o, int &j1,int &j2,int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int sum = 0;
        if (o == 1) {
            j1 = jug1Capacity;
        } else if (o == 2) {
            j2 = jug2Capacity;
        } else if (o == 3) {
            j1 = 0;
        } else if (o == 4) {
            j2 = 0;
        } else if (o == 5) {
            int mn = min(jug1Capacity - j1,j2);
            j1 += mn;
            j2 -= mn;
        } else if (o == 6) {
            int mn = min(jug2Capacity-j2, j1);
            j2 += mn;
            j1 -= mn;
        }
        sum = j1 + j2;
        return sum == targetCapacity;
    }


public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        queue<pair<int,int>> q;
        q.push({jug1Capacity,jug2Capacity});
        HASHSET st;
        for (int level = 0, sz = 1; !q.empty(); level++, sz = q.size()) {
            while(sz--) {
                pair<int,int> cur = q.front();
                q.pop();
                for (int i = 1; i < 7; i++) {
                    int j1 = cur.first;
                    int j2 = cur.second;
                    if (process(i,j1,j2,jug1Capacity,jug2Capacity,targetCapacity))
                        return true;
                    int mn = min(j1,j2), mx = max(j1,j2);
                    if (st[mn].count(mx))
                        continue;
                    st[mn].insert({mn,mx});
                    q.push({j1,j2});
                }
            }
        }
        return false;
    }
};

int main()
{
    int t; cin >> t;
    while (t--) {
        Solution s;
        int j1, j2, target;
        cin >> j1 >> j2 >> target;
        cout << "\n" << s.canMeasureWater(j1,j2,target) << "\n";
    }
    return 0;
}

/*
8
1 2 3
3 4 5
4 3 5
2 6 5
3 5 7
15 20 100
21 29 15
100 118 39
*/