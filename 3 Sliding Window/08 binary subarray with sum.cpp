#include <bits/stdc++.h>
using namespace std;
int numSubarraysWithSum(vector<int> &nums, int goal){
    int ans = 0, sum = 0;
    unordered_map<int, int> freq;
    freq[0] = 1;

    for (int num : nums){

        sum += num;
        if (freq.find(sum - goal) != freq.end()){
            ans += freq[sum - goal];
        }
        freq[sum]++;
    }
    return ans;
}

int main(){

    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << numSubarraysWithSum(nums, goal);
    return 0;
}