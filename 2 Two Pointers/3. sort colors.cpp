#include<bits/stdc++.h>
using namespace std;
    // in single pass with dutch national flag algorithm 
    vector<int> sortColors(vector<int>& arr){

        int low = 0 , mid = 0, high = arr.size() - 1;

        while(mid <= high){

            // handling 0's 
            if(arr[mid] == 0){
                swap(arr[mid] , arr[low]);
                low++;mid++;
            }
            // handeling 1's 
            else if(arr[mid] == 1){
                mid++;
            }
            // handeling 2's
            else{
                swap(arr[mid] , arr[high]);
                high--;
            }
        }
        return arr;
    }
  
int main(){
    vector<int> arr = {2,0,2,1,1,0};
    sortColors(arr);

    for(int el : arr){
        cout<<el<<" ";
    }
return 0;
}   