#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long mid) {
        long long currSum = 0;
        int parts = 1; // at least one subarray
        for (int num : nums) {
            if (currSum + num > mid) {
                parts++;
                currSum = num; // start new subarray
                if (parts > k) return false;
            } else {
                currSum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;    // possible answer
                high = mid - 1; // try smaller
            } else {
                low = mid + 1; // need larger
            }
        }
        return (int)ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {7,2,5,10,8};
    int k = 2;
    cout << s.splitArray(nums, k) << endl;
    return 0;
}
