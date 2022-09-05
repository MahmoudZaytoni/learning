// Shortest Path with Alternating Colors
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <map>
#define OO 1e9
using namespace std; 


class Solution {
    struct edge {
        int to;
        bool color; // 0 = red , blue = 1;

        edge(int to, bool color) : to(to), color(color) {
        }
    };
    typedef vector<vector<edge>> GRAPH; 

    void add_directed_edge(GRAPH &graph, int from ,int to, bool color) {
        graph[from].push_back({to,color});
    }

    void bfs(GRAPH &graph, int start, vector<int> &ans) {
        queue<edge> q;
        vector<vector<int>> visited(graph.size(), vector<int>(2,OO));

        ans[start] = 0;
        q.push({start,0});
        q.push({start,1});
        visited[0][1] = visited[0][0] = 1;
        
        for (int level = 1, sz = q.size(); !q.empty(); level++, sz = q.size()) {
            while (sz--) {
                edge cur = q.front();
                q.pop();

                for (int i = 0; i < graph[cur.to].size(); i++) {
                    edge e = graph[cur.to][i];
                    if (e.color != cur.color && visited[e.to][e.color] == OO) {
                        q.push(e);
                        visited[e.to][e.color] = level;
                        if (ans[e.to] == -1) {
                            ans[e.to] = level;
                        }
                    }
                }
            }
        }
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        GRAPH graph(n);

        for (auto &e : redEdges)
            add_directed_edge(graph,e[0], e[1], 0);
        for (auto &e : blueEdges)
            add_directed_edge(graph,e[0],e[1],1);

        vector<int> len(n,-1);
        bfs(graph,0,len);
        return len;
    }
};