#include <vector>
#include <iostream>
using namespace std;

class Solution {
    bool func(int ind, int sum, const vector<int>& nums) {
      //base-condition  
        if (sum == 0) return true;
        if (sum < 0 || ind == nums.size()) return false;
      
        bool path1 = func(ind + 1, sum - nums[ind], nums);
        bool path2 = func(ind + 1, sum, nums);
        return path1 || path2;
    }

    bool checkSubsequenceSum(vector<int>& nums, int k) {
        return func(0, k, nums);
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 8;
    cout << (sol.checkSubsequenceSum(nums, k) ? "Yes" : "No") << endl;  // Expected output: Yes

    return 0;
}
