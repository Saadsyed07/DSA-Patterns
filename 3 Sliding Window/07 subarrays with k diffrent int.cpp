#include <bits/stdc++.h>
using namespace std;
int subArrayWithK(vector<int> &nums, int k){
    int ans = 0, left = 0, right = 0;
    unordered_map<int, int> freq;

    while (right < nums.size()){
        freq[nums[right]]++;

        while (freq.size() > k){
            freq[nums[left]]--;
            if (freq[nums[left]] == 0)
                freq.erase(nums[left]);
            left++;
        }

        ans += right - left + 1;
        right++;
    }
    return ans;
}

int subarraysWithKDistinct(vector<int> &nums, int k){
    return subArrayWithK(nums, k) - subArrayWithK(nums, k - 1);
}

int main(){
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << subarraysWithKDistinct(nums, k);
    return 0;
}