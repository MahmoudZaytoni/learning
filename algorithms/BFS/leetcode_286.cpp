
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <map>
#define OO 1e9
using namespace std; 

class Solution {
    bool Valid(int r, int c, vector<vector<int>> &rooms) {
        if (r < 0 || c < 0 || r >= rooms.size() || c >= rooms[0].size()) 
            return false;
        if (rooms[r][c] != 2147483647 )
            return false;
        return true;
    }

    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};

public:
    // (-1, wall) , (0, A gate) , (inf, empyt)
    void wallsAndGates(vector<vector<int>> &rooms) {
        queue<pair<int,int>> q;
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[0].size(); j++) {
                if (rooms[i][j] == 0)
                    q.push({i,j});
            }
        }

        for (int level = 0, sz = q.size(); !q.empty(); level++, sz=q.size()) {
            while (sz--) {
                pair<int,int> cur = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int cr = cur.first, cc = cur.second;
                    int nr = cr + dx[i], nc = cc + dy[i];

                    if (!Valid(nr,nc,rooms))
                        continue;
                    rooms[nr][nc] = level + 1;
                    q.push({nr, nc});
                }
            }
        }

    }
};

int main() 
{
    vector<vector<int>> v(4, vector<int>(4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> v[i][j];
        }
    }
    Solution s;
    s.wallsAndGates(v);
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}

/*
2147483647  -1  0  2147483647
2147483647 2147483647 2147483647  -1
2147483647  -1 2147483647  -1
0  -1 2147483647 2147483647 
*/