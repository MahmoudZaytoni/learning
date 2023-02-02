// Title : open the lock
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <map>
#define OO 1e9
using namespace std; 

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        if (start == target)
            return 0;
        queue<string> q;
        q.push(start);
        map<string,bool> mp;
        for (auto str : deadends) {
            mp[str] = true;
        }
        if (mp[start])
            return -1;
        mp[start] = true;
        for (int level = 0, sz = q.size(); !q.empty(); level++, sz = q.size()) {
            while (sz--) {
                string cur = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 2; j++) {
                        string s = cur;
                        if (j == 0) {
                            s[i] = ((s[i]-'0' + 1) % 10) + '0';
                        } else {
                            s[i] = (((s[i]-'0' - 1) + 10) % 10) + '0';
                        }
                        if (mp[s])
                            continue;
                        if (s == target)
                            return level + 1;
                        mp[s] = true;
                        q.push(s);
                    }
                }
            }
        }
        return -1;
    }
};