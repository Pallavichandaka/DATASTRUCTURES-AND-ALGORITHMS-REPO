#include <vector>
#include <iostream>
using namespace std;

class Solution {
    bool func(int ind, int currSum, const vector<int>& nums, int k) {
        if (currSum == k) return true;
        if (currSum > k || ind == nums.size()) return false;
        
        bool path1 = func(ind + 1, currSum + nums[ind], nums, k);
        bool path2 = func(ind + 1, currSum, nums, k);
        
        return path1 || path2;
    }

public:
    bool checkSubsequenceSum(vector<int>& nums, int k) {
        return func(0, 0, nums, k);
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 8;
    cout << (sol.checkSubsequenceSum(nums, k) ? "Yes" : "No") << endl;

    return 0;
}

