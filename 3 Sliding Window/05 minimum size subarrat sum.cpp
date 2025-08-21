#include <bits/stdc++.h>
using namespace std;

    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, miniLength = INT_MAX, left = 0, right = 0;

        while (right < nums.size()) {

            sum = sum + nums[right];
            if (sum >= target) {

                miniLength = min(miniLength, right - left + 1);
                while (sum >= target) {
                    sum -= nums[left];
                    miniLength = min(miniLength, right - left + 1);
                    left++;
                }
            }
            right++;
        }
        return miniLength == INT_MAX  ? 0 : miniLength;
    }

int main()
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << minSubArrayLen(target, nums);
    return 0;
}