#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums){
    unordered_set<int> mpp(nums.begin(), nums.end());
    int longest = 0;
    for (int num : mpp){
        if (mpp.find(num - 1) == mpp.end()){
            int length = 1;

            while (mpp.find(num + length) != mpp.end()){
                length++;
            }
            longest = max(longest, length);
        }
    }
    return longest;
}
int main(){
    vector<int>arr = {50,40,4,3,2,1};
    cout<<longestConsecutive(arr);


    return 0;
}