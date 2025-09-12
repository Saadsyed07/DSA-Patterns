#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;
            while (!s.empty() && s.top() <= nums[idx]) {
                s.pop();
            }
            if (!s.empty()) {
                ans[idx] = s.top();
            }
            s.push(nums[idx]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> result = sol.nextGreaterElements(nums);

    cout << "Next Greater Elements in Circular Array: ";
    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}
