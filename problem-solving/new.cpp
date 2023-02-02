#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>

using namespace std;

// Returns the slope between points p1 and p2.
// If p1 and p2 have the same x-coordinate, returns INT_MAX.
double slope(vector<int>& p1, vector<int>& p2) {
  if (p1[0] == p2[0]) return INT_MAX;
  return (p1[1] - p2[1]) * 1.0 / (p1[0] - p2[0]);
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
      int n = points.size();
      if (n < 3) return n;

      int max_points = 0;
      for (int i = 0; i < n; i++) {
        map<double, int> counts;
        int duplicate_points = 1;
        for (int j = i + 1; j < n; j++) {
          double s = slope(points[i], points[j]);
          if (s == INT_MAX) {
            duplicate_points++;
          } else {
            counts[s]++;
          }
        }
        for (auto& p : counts) {
          max_points = max(max_points, p.second+1);
        }
        max_points = max(max_points, duplicate_points);
      }
      return max_points;
    }
};