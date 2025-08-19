#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &arr, int k){
    int prefixSum = 0, count = 0;
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    for (int i = 0; i< arr.size(); i++){
        prefixSum = prefixSum + arr[i];
        int remove = prefixSum - k;
        count += mpp[remove];
        mpp[prefixSum]++;
    }
    return count;
}
int main(){
    vector<int> arr = {1,1,1};
    cout << subarraySum(arr, 2);
    return 0;
}