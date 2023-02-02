

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <set>
#include <map>
#include <unordered_set>
#define OO 1e9
using namespace std;

typedef vector<vector<int>> GRAPH;

pair<int,int> BFS(GRAPH &graph, int start) {
    queue<int> q;
    vector<int> len(graph.size(), OO);
    q.push(start);
    len[start] = 0;

    int cur = 0, level = 0, sz = 1;
    for ( level = 0, sz = 1; !q.empty(); level++, sz = q.size()) {
        while (sz--) {
            cur = q.front();
            q.pop();

            for (auto neighbour : graph[cur]) {
                if (len[neighbour] == OO) {
                    q.push(neighbour);
                    len[neighbour] = level + 1;
                }
            }
        }
    }
    return {cur , len[cur]};
}

int treeDiam(GRAPH &graph) {
    pair<int,int> p1 = BFS(graph, 0);
    p1 = BFS(graph, p1.first);
    return p1.second;
}

int main()
{
    int nodes; cin >> nodes;

    GRAPH graph(nodes + 1);

    for (int i = 0; i < nodes - 1; i++) {
        int from, to; cin >> from >> to;
        from--, to--;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    cout << treeDiam(graph) << "\n";
    return 0;
}
