#include <iostream>
#include <vector>
using namespace std;

int Bsearch(vector<int>& nums, int target) {
    int l = 0, r = (int)nums.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] > target)
            r = mid - 1;
        else if (nums[mid] < target)
            l = mid + 1;
        else
            return mid;
    }
    return -1;
}

int BS_First(vector<int>& nums, int target) {
    int start = 0, end = (int)nums.size() - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] < target)
            start = mid + 1;
        else if (nums[mid] > target)
            end = mid - 1;
        else 
            start = mid;
    }
    if (start < 0 || start >= (int)nums.size())
        return -1;
    return (nums[start] == target ? start : -1);
}

int BS_First(vector<int>& nums, int target) {
    int start = 0, end = (int)nums.size() - 1, position = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] < target)
            start = mid + 1;
        else if (nums[mid] > target)
            end = mid - 1;
        else 
            end = mid - 1, position = mid;
    }
    return position;
}

int BS_Last(vector<int>& nums, int target) {
    int start = 0, end = (int)nums.size() - 1;
    while (start < end) {
        int mid = start + (end - start + 1) / 2;
        if (nums[mid] < target)
            start = mid + 1;
        else if (nums[mid] > target)
            end = mid - 1;
        else 
            start = mid;
    }
    if (start < 0 || start >= (int)nums.size())
            return -1;
    return (nums[start] == target ? start : -1);
}


int BS_Last(vector<int>& nums, int target) {
    int start = 0, end = (int)nums.size() - 1, position;
    while (start <= end) {
        int mid = start + (end - start ) / 2;
        if (nums[mid] < target)
            start = mid + 1;
        else if (nums[mid] > target)
            end = mid - 1;
        else 
            start = mid + 1, position = mid;
    }
    return position;
}

int main()
{
	    

	return 0;
}
