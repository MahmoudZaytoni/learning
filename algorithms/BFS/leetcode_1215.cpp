// Steping Number
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <climits>
#include <map>
#define OO 1e9
typedef long long ll;
using namespace std; 


class Solution {
    ll nextStepping(ll num, ll low, ll high) {
        int last_digit = num % 10;
        
        if (last_digit == 9)
            return -1;

        ll next = (num * 10) + (last_digit+1);

        if (next <= high)
            return next;

        return -1;
    }

    ll prevStepping(ll num, ll low, ll high) {
        int last_digit = num % 10;
        
        if (last_digit == 0)
            return -1;

        ll prev =  num * 10 + (last_digit-1);
        if (prev <= high)
            return prev;

        return -1;
    }

    vector<int> bfs(ll low, ll high) {
        vector<int> result;
        queue<ll> q;
        for (int i = 1; i <= 9; i++) {
            q.push(i);
        }

        for (int level = 0, sz=q.size(); !q.empty(); level++, sz = q.size()) {
            while (sz--) {
                ll cur = q.front();
                q.pop();

                ll next = nextStepping(cur, low, high);
                ll prev = prevStepping(cur, low, high);

                if (cur >= low && cur <= high)
                    result.push_back(cur);

                if (next != -1) {
                    q.push(next);
                }

                if (prev != -1) 
                    q.push(prev);
            }
        }
        return result;
    }
public:
    vector<int> countSteppingNumbers(ll low, ll high) {
        vector<int> result;
        result = bfs(low,high);
        if (0 == low)
            result.push_back(0);
        sort(result.begin(), result.end());
        return result;
    }
};

int main()
{
    ll low, high; cin >> low >> high;
    Solution s;
    vector<int> ans;
    ans = s.countSteppingNumbers(low,high);
    for (auto &item : ans)
        cout << item << " ";
    cout << "\n";
    return 0;
}