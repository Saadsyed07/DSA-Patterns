#include <bits/stdc++.h>
using namespace std;
vector<int> topKFrequent(vector<int> &nums, int k){
    
    // count the frequency
    unordered_map<int, int> count;
    for (int i : nums){
        count[i]++;
    }

    vector<vector<int>> freq(nums.size() + 1);
    for (auto &entry : count){
        freq[entry.second].push_back(entry.first);
    }

    vector<int> result;
    for (int i = freq.size() - 1; i > 0; i--){
        for (int num : freq[i]){
            result.push_back(num);
            if (result.size() == k)
                return result;
        }
    }
    return {};
}
int main(){
    vector<int> arr = {1, 1, 1, 2, 3, 2};
    vector<int> ans = topKFrequent(arr, 2);
    for (int i : ans){
        cout << i << " ";
    }
    return 0;
}