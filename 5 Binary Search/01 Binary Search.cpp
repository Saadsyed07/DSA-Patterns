#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int search(vector<int> &nums, int target){

        int start = 0, end = nums.size() - 1;
        while (start <= end){
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                start = start + 1;
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    cout << s.search(arr, 6);
    return 0;
}