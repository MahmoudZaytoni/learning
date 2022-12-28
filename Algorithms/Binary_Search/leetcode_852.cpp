/****************************************************
 *** Problem Number : 852
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/peak-index-in-a-mountain-array/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 1, high = (int)arr.size() - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1] )
                return mid;
            else if (arr[mid-1] > arr[mid])
                high = mid - 1;
            else if (arr[mid-1] < arr[mid])
                low = mid + 1;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> v{3,5,3,2,0};
    cout << s.peakIndexInMountainArray(v) << endl;
    return 0;
}