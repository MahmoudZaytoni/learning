// 773. Sliding Puzzle
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <set>
#include <map>
#include <unordered_set>
#define OO 1e9

using namespace std; 


// This is a bit Complex Solution 
// See simpler solution down there 
class Solution {
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};

    bool isValid(int r, int c, vector<vector<int>> &board) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size())
            return false;
        return true;
    }

    pair<int,int> get_index(int item, vector<vector<int>> &v) {
        int rows = v.size(), cols = v[0].size();

        for (int i = 0; i < rows; i++) 
            for (int j= 0; j < cols; j++) 
                if (v[i][j] == item)
                    return {i,j};
        return {-1,-1};
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> target({{1,2,3},{4,5,0}});
        if (board == target)
            return 0;
        
        set<vector<vector<int>>> visited;
        queue<vector<vector<int>>> q;
        q.push(board);

        for (int level = 0, sz = 1; !q.empty(); sz = q.size(), level++) {
            while (sz--) {
                vector<vector<int>> cur_board = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    pair<int,int> cur = get_index(0,cur_board);
                    int nr = cur.first + dx[d], nc = cur.second + dy[d];



                    if (!isValid(nr,nc, cur_board))
                        continue;

                    swap(cur_board[nr][nc], cur_board[cur.first][cur.second]);

                    if (cur_board == target)
                        return level + 1;

                    if (visited.count(cur_board)) {
                        swap(cur_board[nr][nc], cur_board[cur.first][cur.second]);
                        continue;
                    }
                    
                    q.push(cur_board);
                    visited.insert(cur_board);
                    swap(cur_board[nr][nc], cur_board[cur.first][cur.second]);
                }
            }
        }
        return -1;
    }
};

class Solution2 {
    string target = "123450";
    // For each idx [0 - 5]: list which indices it can swap with them
    vector<vector<int>> dir{{1,3}, {0, 2, 4}, {1, 5}, {0,4}, {1, 3, 5}, {4,2}};
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for (int i = 0; i < board.size(); i++) 
            for (int j= 0; j < board[0].size(); j++) 
                start += board[i][j] + '0';

        if (start == target)
            return 0;
        
        queue<string> q;
        q.push(start);

        unordered_set<string> visited;
        visited.insert(start);

        for (int level = 0, sz = 1; !q.empty(); sz = q.size(), level++) {
            while (sz--) {
                string cur = q.front();
                q.pop();

                int idx = cur.find('0');

                for (auto idx2 : dir[idx]) {
                    swap(cur[idx], cur[idx2]);

                    if (cur == target)
                        return level+1;

                    if (visited.insert(cur).second)
                        q.push(cur);
                    
                    
                    swap(cur[idx], cur[idx2]);                    
                }
            }
        }
        return -1;
    }
};


int main()
{
    
    return 0;
}