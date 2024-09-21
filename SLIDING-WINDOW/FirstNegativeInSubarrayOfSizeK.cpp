#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> return_ans(vector<int>& arr, int k) {
    int l = 0, r = 0;
    list<int> temp_store; 
    vector<int> final_ans; 

    while (r < arr.size()) {
        if (arr[r] < 0) {
            temp_store.push_back(r);
        }
        else{
            //No action needed for non-negative numbers
        }
        if (r - l + 1 != k) {
            r++;
        } 
        else if (r - l + 1 == k) {
            // If there are no negative numbers in the list, add 0 to the result
            if (temp_store.empty()) {
                final_ans.push_back(0);
            } 
            // Otherwise, the first element in the list is the first negative number
            else {
                final_ans.push_back(arr[temp_store.front()]);
                
                
                // If the element at the left pointer is the same as the one at the front of the list, remove it from the list
                if (arr[l] == arr[temp_store.front()]) {
                    temp_store.pop_front();
                }
                r++;
                l++;
            }
        }
    }

    return final_ans;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    vector<int> result = return_ans(arr, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
