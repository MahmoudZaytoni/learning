// 1298. Maximum Candies You Can Get from Boxes

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <climits>
#include <unordered_set>
#include <map>
#define OO 1e9
typedef long long ll;
using namespace std; 


class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {

        vector<bool> visited(status.size());
        int total_candies = 0;

        queue<int> q;
        for (auto &box : initialBoxes) {
            if (status[box])
                q.push(box);
            visited[box] = 1;
        }

        for (int level = 0, sz = q.size(); !q.empty(); level++, sz = q.size()) {
            while (sz--) {
                int cur_box = q.front();
                q.pop();

                total_candies += candies[cur_box];

                for (auto &key : keys[cur_box]) {
                    if (visited[key]&&!status[key]) 
                        q.push(key);
                    status[key] = 1;
                }

                for (auto &containedBox : containedBoxes[cur_box]) {
                    if (status[containedBox])
                        q.push(containedBox);
                    visited[containedBox] = 1;
                }


            }
        }
        return total_candies;
    }
};