#include <bits/stdc++.h>
using namespace std;
double findMaxAverage(vector<int> &nums, int k){
    double sum = 0;

    for (int i = 0; i < k; i++){
        sum += nums[i];
    }

    double maxAvg = sum / k;

    int i = 0;
    for (int j = k; j < nums.size(); j++){
        sum += nums[j] - nums[i];
        i++;
        double currAvg = sum / k;
        maxAvg = max(maxAvg, currAvg);
    }
    return maxAvg;
}

int main(){
    vector<int> nums = {1,12,-5,-6,50,3}; int k = 4;
    // maximum avg => 51/4 = 12.75 from subarray 12,-5,-6,50
    cout<<"max average : "<<findMaxAverage(nums,k);

    return 0;
}