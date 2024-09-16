#include<bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int i = 0; 
    for (int j = 0; j < nums.size(); ++j) {
        if (nums[j] != val) {
            nums[i] = nums[j]; 
            ++i;  
        }
    }
    return i;  
}

int main() {
    vector<int> nums = {3, 2, 2, 3, 4, 3, 5, 3};
    int val = 3;
    int newLength = removeElement(nums, val);

    cout << "Array after removing " << val << ":\n";
    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    cout << "New length of the array: " << newLength << endl;
    
    return 0;
}
