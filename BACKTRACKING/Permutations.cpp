class Solution {
public:
    void recurPermute(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, vector<bool>& freq) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;  // Add the current permutation to the result
        }
         // Recursively try each element
        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                freq[i] = true;
                ds.push_back(nums[i]);
              
                
                recurPermute(nums, ds, ans, freq);// Continue building the permutation
                 
                ds.pop_back();   // Backtrack: Undo the choice
                freq[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> freq(nums.size(), false);

        recurPermute(nums, ds, ans, freq);

        return ans;
    }
};
