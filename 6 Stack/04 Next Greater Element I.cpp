#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2){
        unordered_map<int, int> mpp;
        stack<int> s;

        for (int i = nums2.size() - 1; i >= 0; i--){
            while (!s.empty() && s.top() <= nums2[i]){
                s.pop();
            }
            if (s.empty()){
                mpp[nums2[i]] = -1;
            }
            else{
                mpp[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
    vector<int> ans = s.nextGreaterElement(nums1, nums2);
    for (int num : ans){
        cout << num << " ";
    }

    return 0;
}