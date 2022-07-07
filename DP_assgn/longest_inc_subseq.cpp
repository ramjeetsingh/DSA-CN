#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
        
    int *len = new int[n];
    for (int a = 0; a < n; a++) {
        len[a] = 1;
    }
        
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                len[i] = max(len[i], len[j]+1);
            }
        }
    }
        
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if(len[i] > ans) {
            ans = len[i];
        }
    }
        
    return ans;
}


int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;

        arr.push_back(ele);
    }

   cout << lengthOfLIS(arr);
}
