#include <bits/stdc++.h>
using namespace std;
int findPairs(vector<int> &nums, int k){
    sort(nums.begin(), nums.end());
    int cnt = 0, i = 0, j = 1;

    while (j < nums.size()){
        if (i == j || nums[j] - nums[i] < k){
            j++;
        }
        else if (nums[j] - nums[i] > k){
            i++;
        }
        else{
            cnt++;
            i++;
            j++;

            // skip duplicates
            while (j < nums.size() && nums[j] == nums[j - 1])
                j++;
        }
    }

    return cnt;
}
int main(){
    vector<int> nums = {3, 1, 4, 1, 5};
    cout << "there are " << findPairs(nums, 2) << " pairs" << endl;
    return 0;
}