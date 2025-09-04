#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid;

        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[start] <= nums[mid]) { // left part is sorted
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else
                    start = mid + 1;
            } else { // right part is sorted
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1;
                } else
                    end = mid - 1;
            }
        }
        return -1;
    }
};  
int main(){
    Solution s;
     vector<int> nums = {4,5,6,7,0,1,2}; 
     int  target = 0;
    cout<<"target is present at index: "<<s.search(nums,target);

return 0;
}