#include<bits/stdc++.h>
using namespace std;

   vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());//sort array
        for (int i = 0; i < nums.size(); i++) {

            //skiping duplicates for first element
            if (i > 0 && nums[i] == nums[i - 1])continue;

            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum > 0) k--;
                else if (sum < 0) j++;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;k--;
                    
                    //skiping duplicates for second element
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    //skiping duplicates for third element
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum(nums);
    for(auto &entry : ans){
        for(auto el : entry){
            cout<<el<<" ";
        }
        cout<<endl;
    }
return 0;
}