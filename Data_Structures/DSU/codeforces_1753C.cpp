#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <cstring>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
using namespace std;
typedef long long ll;

class UnionFind {
  vector<int> root;
public:
  UnionFind(int sz) : root(sz)  {
    for (int i = 0; i < sz; i++)
      root[i] = i;
  }

  int find(int x) {
    if (x == root[x])
      return x;
    return root[x] = find(root[x]);
  }

  bool UnionSet(int x, int y) {
    if (y != find(y))
      return false;

    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
      return false;
    root[rootY] = rootX;
    return true;
  }

};

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    UnionFind uf(27);
    vector<int> visited(26);
    vector<int> ans_mp(26, -1);
    for (int i = 0; i < n; i++) {
      if (visited[s[i] - 'a'])
        continue;

      bool flag = false; 
      for (int j = 0; j < 26; j++) {
        if (uf.UnionSet(s[i] - 'a', j)) {
          ans_mp[s[i]-'a'] = j;
          flag = true;
          break;
        }
      }
      if (!flag) {
        for (int j = 0; j < 26; j++) {
          if (j == uf.find(j)) {
            ans_mp[s[i] - 'a'] = j;
            break;
          }
        }
      }
      visited[s[i]-'a'] = 1;
    }
    for (int i = 0; i < n; i++) {
      cout << char(ans_mp[s[i]-'a'] + 'a');
    }
    cout << "\n";
  }
  return 0;
}