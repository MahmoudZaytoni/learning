#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
using namespace std;
typedef long long ll;


// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
private:
    unordered_map<int,Employee*> id_to_emp;
public:
    int dfs(int id) {
        Employee *emp = id_to_emp[id];
        int result = emp->importance;
        for (auto &subEmp : emp->subordinates)
            result += dfs(subEmp);
        return result;
    }
    
    
    int getImportance(vector<Employee*> employees, int id) {
        for (auto &emp : employees) {
            id_to_emp[emp->id] = emp;
        }

        return dfs(id);
    }
};


