#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;
    int maxSum = INT_MIN;
    int i = 0, j = 0;

    while (j < n) {
        sum += nums[j];

        if (j - i + 1 < k) {
            j++;                      
        } //formed the  window
        
        else if (j - i + 1 == k) {    
            maxSum = max(maxSum, sum);
            sum -= nums[i];              

            j++; //Maintaining the window
            i++;
        }
    }

    return maxSum;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 3;

    cout << "Maximum sum of subarray of size " << k << " is " << maxSubarraySum(nums, k) << endl;

    return 0;
}
