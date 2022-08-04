#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void insertion_sort(vector<int>& nums) {
    int n = (int)nums.size();
    for (int i = 1; i < n; i++) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key)
            nums[j + 1] = nums[j], j--;
        nums[j + 1] = key;
    }
}
// my Version
void insertion_sort_v2(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        int j = i - 1;
        while (j >= 0 && nums[i] > nums[j]) j--;
        swap(nums[i], nums[++j]);
        i = j;
    }
}

// Dr, mostafa version
void insertion_sort_v3(vector<int>& nums) {
    for (int i = 1; i < (int)nums.size(); i++) {
        for (int j = i; j - 1 >= 0 && nums[j] < nums[j-1]; j--)
            swap(nums[j], nums[j - 1]);
    }
}

void selection_sort(vector<int>& nums) {
    int n = (int)nums.size();
    for (int i = 0; i < n - 1; i++) {
        int mn_indx = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[mn_indx])
                mn_indx = j;
        }
        swap(nums[i], nums[mn_indx]);
    }
}


void count_sort(vector<int>& nums) {
    int mx_element = nums[0];
    for (int i = 1; i < nums.size(); i++)
        if (nums[i] > mx_element)
            mx_element = nums[i];

    vector<int> count(mx_element+1);
    for (int i = 0; i < nums.size(); i++)
        count[nums[i]] += 1;

    int idx = 0;
    for (int i = 0; i <= mx_element; i++) 
        for (int j = 0; j < count[i]; j++, idx++)
            nums[idx] = i;
}

// Leet Code 912 
// used for negative and positive values
void count_sort_v2(vector<int>& nums) {
    const int SHIFT = 50000;
    int sz = (int)nums.size();
    for (int i = 0; i < sz; i++)
        nums[i] += SHIFT;

    int mx_element = nums[0];
    for (int i = 1; i < sz; i++)
        if (nums[i] > mx_element)
            mx_element = nums[i];

    vector<int> count(mx_element + 1);
    for (int i = 0; i < sz; i++)
        count[nums[i]] += 1;

    int idx = 0;
    for (int i = 0; i <= mx_element; i++)
        for (int j = 0; j < count[i]; j++, idx++)
            nums[idx] = i - SHIFT; 
}
// Leet Code 912
// used for negative and positive values and Big values who's max diffrent is small

void count_sort_v3(vector<int>& nums) {
    int sz = (int)nums.size();
    int mx_element = nums[0], mn_element = nums[0];

    for (int i = 1; i < sz; i++) {
        if (nums[i] > mx_element)
            mx_element = nums[i];
        if (nums[i] < mn_element)
            mn_element = nums[i];
    }

    int new_max = mx_element - mn_element;
    vector<int> count(new_max + 1);
    for (int i = 0; i < sz; i++)
        count[nums[i] - mn_element] += 1;

    int idx = 0;
    for (int i = 0; i <= new_max; i++)
        for (int j = 0; j < count[i]; j++, idx++)
            nums[idx] = i + mn_element;
}

// sort only by first char
const int LETTERS_SZ = 26;
void count_sort_strings(vector<string>& Array) {
    int size = Array.size();
    //const int LETTERS_SZ = 26;
    vector<vector<string>> letter_to_strings(LETTERS_SZ);
    for (int i = 0; i < size; i++) 
        letter_to_strings[Array[i][0] - 'a'].push_back(Array[i]);

    int idx = 0;
    for (int letter = 0; letter < LETTERS_SZ; letter++)
        for (int str_idx = 0; str_idx < letter_to_strings[letter].size(); str_idx++, idx++)
            Array[idx] = letter_to_strings[letter][str_idx];
}

int id(const string& str) {
    int fst = str[0] - 'a';
    int snd = str[1] - 'a';
    // imagine it like flatter array
    return fst * LETTERS_SZ + snd;
}

// sort only by first 2 characters
void count_sort_strings_v2(vector<string>& Array) {
    int size = Array.size();
    int range = LETTERS_SZ * LETTERS_SZ;

    vector<vector<string>> letter_to_strings(range+1);
    
    for (int i = 0; i < size; i++)
        letter_to_strings[id(Array[i])].push_back(Array[i]);

    int idx = 0;
    for (int letter = 0; letter < range; letter++)
        for (int str_idx = 0; str_idx < letter_to_strings[letter].size(); str_idx++, idx++)
            Array[idx] = letter_to_strings[letter][str_idx];
}

int main()
{
    vector<int> v{-1, -10, -20, -200, 1, 5, 2, 29, 10, 10, 0 };
    //insertion_sort(v);
    //insertion_sort_v2(v);
    //insertion_sort_v3(v);
    //selection_sort(v);
    //count_sort(v);     // ONLY Positive Values
    //count_sort_v2(v);
    count_sort_v3(v);

    for (auto it : v) cout << it << " ";
    return 0;
}