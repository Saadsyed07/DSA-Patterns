#include<bits/stdc++.h>
using namespace std;

    pair<int,int> twoSum(vector<int>& arr, int target){

        int left = 0, right = arr.size()-1 ;
        pair<int,int>ans;

        while(left < right){

            if(arr[left] + arr[right] > target){
                right--;
            }else if (arr[left] + arr[right] < target){
                left++;
            }
            else{
                ans.first = left;
                ans.second = right;
                return ans; 
            }
        }
        return {-1,-1};
    }
  
int main(){
vector<int> arr = {2,3,4};
int target = 61;
pair<int,int> ans = twoSum(arr,target);
cout<<ans.first<<" "<<ans.second;
return 0;
}