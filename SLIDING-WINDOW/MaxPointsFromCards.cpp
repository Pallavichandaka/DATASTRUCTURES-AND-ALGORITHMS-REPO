//using constant sliding window
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardScore, int k) {
        int n = cardScore.size();
        int lsum = 0, rsum = 0, maxSum = 0;
        int rindex = n - 1;

        for (int i = 0; i < k; i++) {
            lsum += cardScore[i];
        }
        maxSum = lsum;

        for (int i = k - 1; i >= 0; i--) {
            lsum -= cardScore[i];        
            rsum += cardScore[rindex];  
            rindex--;
            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum;
    }
};

int main() {
    Solution solution;
    vector<int> cardScore = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    int result = solution.maxScore(cardScore, k);
    cout << "Maximum score: " << result << endl;

    return 0;
}
