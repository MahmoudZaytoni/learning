#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <map>
#define OO 1e9
using namespace std; 

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        q.push(start);
        vector<bool> visited(1001);
        for (int level = 0, sz = 1; !q.empty(); ++level, sz = q.size()) {
            while (sz--) {
                int cur = q.front();
                q.pop();
                visited[start] = 1;
                for (int i = 0; i < nums.size(); i++) {
                    for (int o = 0; o < 3; o++) {
                        int x = cur;
                        if (o == 0) {
                            x += nums[i];
                        } else if (o == 1) {
                            x -= nums[i];
                        } else {
                            x ^= nums[i];
                        }
                        
                        if (x == goal)
                            return level + 1;
                        
                        
                        if (x >= 0 && x <= 1000 && !visited[x]) {
                            q.push(x);
                            visited[x] = true;
                        }
                        
                        
                            
                    }
                }
            }
        }
        return -1;
    }
};