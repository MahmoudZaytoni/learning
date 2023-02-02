#include <iostream>
#include <queue>
#include <vector>
#define OO 1e9
using namespace std;




class Solution {
    typedef vector<vector<int>> GRAPH;

    void add_directed_edge(GRAPH &graph, int from , int to)  {
        graph[from].push_back(to);
    }

    bool bfs(vector<int>& arr, vector<bool> &visited ,int start) {
        int size = (int)arr.size();
        queue<int> q;
        q.push(start);
        for (int level = 0, sz = 1; !q.empty(); level++, sz = q.size()) {
            while (sz--) {
                int idx = q.front();
                q.pop();

                if (idx < 0 || idx >= size || visited[idx])
                    continue;
                if (arr[idx] == 0)
                    return true;

                int value = arr[idx];
                visited[idx] = true;
                
                if (value + idx < size) {
                    q.push(value+idx);
                }
                if (idx - value >= 0) 
                    q.push(idx - value);

            }
        }
        return false;
    }

public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size());
        return bfs(arr,visited,start);
    }
};

int main()
{
    vector<int> arr{4,2,3,0,3,1,2}; int start = 5;
    Solution s;
    cout << s.canReach(arr,start) << "\n";
    return 0;
}