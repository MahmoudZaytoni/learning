#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <queue>
#define OO 1e9
using namespace std;

typedef vector<vector<int>> GRAPH;



vector<int> Bfs(GRAPH &adjList, int start) {
    vector<int> len(adjList.size() , OO);
    queue<pair<int,int>> q;
    q.push({start, 0});
    len[0] = 0;

    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        int cur = p.first, level = p.second;
        for (int neighbour : adjList[cur]) {
            if (len[neighbour] != OO) {
                q.push({neighbour, level + 1});
                len[neighbour] = level + 1;
            }
        }
    }
    return len;
}

vector<int> Bfs_v2(GRAPH &adjList, int start) {
    vector<int> len(adjList.size(), OO);
    queue<int> q;
    q.push(start);
    len[start] = 0;

    for (int level = 0, sz = 1; !q.empty(); level++, sz = q.size()) {
        while (sz--) {
            int cur = q.front();
            q.pop();
            for (int neighbour : adjList[cur]) {
                if (len[neighbour] != OO) {
                    q.push(neighbour);
                    len[neighbour] = level + 1;;
                }
            }
        }
    }
    return len;
}

int main() 
{

    return 0;
}