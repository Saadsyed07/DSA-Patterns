#include<bits/stdc++.h>
using namespace std;
  
bool containDuplicates(vector<int>&nums){
    unordered_set<int>set;
    for(int i = 0; i<nums.size(); i++){
        if(set.count(nums[i])){
            return true;
        }
        set.insert(i);
    }
    return false;
}
int main(){

vector<int> arr{1,1,3,2,3,4};
 cout << (containDuplicates(arr) ? "true" : "false") << endl;

return 0;
}