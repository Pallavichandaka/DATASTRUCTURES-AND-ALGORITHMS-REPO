#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void func(int ind, vector<int>& list, int sum, vector<int>& candidates, vector<vector<int>>& ans) {
        if (sum == 0) {
            ans.push_back(list);
            return;
        }
        if (sum < 0 || ind == candidates.size()) return;

        list.push_back(candidates[ind]);
        func(ind, list, sum - candidates[ind], candidates, ans);

        list.pop_back();
        func(ind + 1, list, sum, candidates, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> list;
        func(0, list, target, candidates, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    
    vector<int> candidates = {2, 3, 5, 4};
    int target = 7;
    vector<vector<int>> result = sol.combinationSum(candidates, target);
    
    cout << "Combinations that sum to " << target << ":" << endl;
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
