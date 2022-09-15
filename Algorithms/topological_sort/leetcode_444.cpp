// 444. Sequence Reconstruction
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
    typedef unordered_map<int, vector<int>> GRAPH;

    void add_directed_edge(GRAPH &graph, int from, int to) {
        graph[from].push_back(to);
    }

    vector<int> topSort(GRAPH &adjList) {
        unordered_map<int,int> indegree;

        for (auto &neighbours : adjList)
            for (int neighbour : neighbours.second)
                indegree[neighbour]++;

        queue<int> ready;
        for (auto &node : adjList)
            if (!indegree.count(node.first) == 0)
                ready.push(node.first);

        vector<int> ordering;
        while (!ready.empty()) {
            if (ready.size() > 1)
                return vector<int>();
            
            int cur = ready.front();
            ready.pop();
            ordering.push_back(cur);

            for (int j : adjList[cur])
                if (--indegree[j] == 0)
                    ready.push(j);
        }
        if (ordering.size() != adjList.size())
            return vector<int>();
        return ordering;
    }
public:
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        GRAPH graph(org.size());

        for (int i = 0; i < seqs.size(); i++)
            for (int j = 1; j < seqs[i].size(); j++)
                add_directed_edge(graph, seqs[i][j-1], seqs[i][j]);

        // special handling for a single value: add them to the graph with no neighbors
		for (auto &seq : seqs) {
			if (seq.size() == 1 && graph.count(seq[0]) == 0)
				graph[seq[0]] = vector<int>();
		}
        vector<int> ordering = topSort(graph);
        return ordering == org;
    }
};



int main()
{
    
    return 0;
}