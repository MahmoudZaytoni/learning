/****************************************************
 *** Problem Number : 698. Partition to K Equal Sum Subsets
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
*****************************************************/
// Don't Try this TLE Code 
// This is Just For learning backtraking
#include <bits/stdc++.h>
using namespace std;

int k;
int partition_sum;
vector<int> numbers;

// part of Backtrack State
vector<int> cur_partition_sum;

vector<vector<int>> partition_values;


bool try_partition(int idx) { // O(k^N) time
  if (idx == numbers.size())
    return true;

  for (int p = 0; p < k; p++) {
    if (cur_partition_sum[p] + numbers[idx] > partition_sum)
      continue;
    
    cur_partition_sum[p] += numbers[idx];
    partition_values[p].push_back(numbers[idx]);

    if (try_partition(idx + 1))
      return true;
    
    cur_partition_sum[p] -= numbers[idx];
    partition_values[p].pop_back();
  }
  return false;
}


void partition_ksubsets_equalsum(const vector<int> &numbers_, int k_) {
	cout << "*********************\n";
	int sum = accumulate(numbers_.begin(), numbers_.end(), 0);
	if (sum % k_ != 0 || (int)numbers_.size() < k_) {
		cout << "Impossible1\n";
		return;
	}

	numbers = numbers_;
	k = k_;
	partition_sum = sum / k;
	cur_partition_sum = vector<int>(k, 0);
	partition_values = vector<vector<int>>(k);

	if (try_partition(0)) {
		for (int partition = 0; partition < k; ++partition) {
			cout << "Partition #" << partition + 1 << ": ";
			for (int j = 0; j < (int) partition_values[partition].size(); ++j)
				cout << partition_values[partition][j] << " ";
			cout << "\n";
		}
	} else
		cout << "Impossible2\n";
}
class Solution {
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % k != 0 || (int)nums.size() < k)
      return false;

    numbers = nums;
    ::k = k;
    partition_sum = sum / k;  
    cur_partition_sum = vector<int>(k);
    partition_values = vector<vector<int>>(k);
    
    return try_partition(0);
  }
};

int main()
{
	partition_ksubsets_equalsum( { 10 }, 2);
	partition_ksubsets_equalsum( { 6 }, 1);
	partition_ksubsets_equalsum( { 5, 5 }, 2);
	partition_ksubsets_equalsum( { 2, 1, 4, 5, 6 }, 3);
	partition_ksubsets_equalsum( { 4, 3, 2, 3, 5, 2, 1 }, 4);
	partition_ksubsets_equalsum( { 1, 2, 3, 4 }, 4);
	partition_ksubsets_equalsum( { 1739, 5391, 8247, 236, 5581, 11, 938, 58, 1884, 823, 686, 1760, 6498, 6513, 6316, 2867 }, 6);
	partition_ksubsets_equalsum( { 10, 5, 5, 4, 3, 6, 6, 7, 6, 8, 6, 3, 4, 5, 3, 7 }, 8);
  return 0;
}