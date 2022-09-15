#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool cmp(pair<char,int> &a, pair<char,int> &b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

bool cmp2(pair<char,int> &a, pair<char,int> &b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main()
{
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        char start = s[0];
        char end = s.back();

        vector<pair<char,int>> v;
        for (int i = 0; i < s.size(); i++)
            v.push_back({s[i], i+1});
        

        vector<int> ans;
        if (start < end) {
            sort(v.begin(), v.end(), cmp);
            int i = 0;
            while (i < v.size()) {
                if (v[i].first >= start && v[i].first <= end) {
                    ans.push_back(v[i].second);
                }
                i++;
            }
        } else {
            sort(v.begin(), v.end(), cmp2);
            int i = 0;
            while (i < v.size()) {
                if (v[i].first <= start && v[i].first >= end)
                    ans.push_back(v[i].second);
                i++;
            }
        }
        cout << abs(start - end) << " " << ans.size() << "\n";
        for (auto it : ans)
            cout << it << " ";
        cout << "\n";
    }
}