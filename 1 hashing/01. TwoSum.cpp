#include<bits/stdc++.h>
using namespace std;
  
vector<int> twoSum(vector<int>&arr , int tar){
       unordered_map<int,int> m;

    for (int  i = 0; i < arr.size(); i++)
    {
        int first = arr[i];
        int second = tar - first;
        if(m.find(second) != m.end()){
            return{m[second],i} ;
        }
        m[first] = i;
    }
    return {};
}
int main(){
    vector<int>arr= {2,7,11,15};
    int tar = 9;
   vector<int> ans = twoSum(arr,tar);
 
    for(auto it : ans){
        cout<<it <<" ";
    }

return 0;
}