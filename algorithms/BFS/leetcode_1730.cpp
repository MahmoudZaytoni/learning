// Shortest Path to Get FOOD
#include <iostream>
#include <queue>
#include <vector>
#define OO 1e9
using namespace std;


int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

bool isValid(int r, int c, vector<vector<char>> &matrix) {
    if (r < 0 || c < 0 || r >= matrix.size() || c >= matrix[0].size())
        return false;
    if (matrix[r][c] == 'X')
        return false;
    return true;
}


int bfs(vector<vector<char>> &matrix, pair<int,int> start) {
    queue<pair<int,int>> q;

    q.push(start);
    matrix[start.first][start.second] = 'X';
    for (int level = 1, sz = 1; !q.empty(); level++, sz=q.size()) {
        while (sz--) {
            int cr = q.front().first , cc = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = cr + dx[d], nc = cc + dy[d];
                if (!isValid(nr,nc, matrix))
                    continue;
                if (matrix[nr][nc] == '#')
                    return level;
                q.push({nr,nc});
                matrix[nr][nc]='X';
            }
        }
    }
    return -1;
}

int getFood(vector<vector<char>> &matrix) {
    int rows = matrix.size() , cols = matrix[0].size();
    pair<int,int> start;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '*')
                start = {i,j};
        }
    }
    return bfs(matrix, start);
}

int main() 
{
    int t; cin >> t;
    while (t--) {
        int rows, cols; cin >> rows >> cols;
        vector<vector<char>> grid(rows, vector<char>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> grid[i][j];
            }
        }
        cout << getFood(grid) << "\n";
    } 
}


/* 
3
4 5
X X X X X 
X * X O X
X O X # X
X X X X X

5 8
X X X X X X X X 
X * O X O # O X 
X O O X O O X X 
X O O O O # O X 
X X X X X X X X 

2 2
O *
# O
*/