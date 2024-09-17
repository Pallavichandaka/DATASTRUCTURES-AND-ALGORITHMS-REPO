#include <iostream>
#include <vector>
using namespace std;

int func(int ind, int k, vector<int>& arr) {
    if (k == 0) return 1;
    if (k < 0 || ind == arr.size()) return 0;

    int path1 = func(ind + 1, k - arr[ind], arr);
    int path2 = func(ind + 1, k, arr);

    return path1 + path2;
}

int countSubsequencesWithSumK(vector<int>& arr, int k) {
    return func(0, k, arr);
}

int main() {
    vector<int> nums1 = {4, 9, 2, 5, 1};
    int k1 = 10;
    cout << "Output: " << countSubsequencesWithSumK(nums1, k1) << endl;
    return 0;
}
