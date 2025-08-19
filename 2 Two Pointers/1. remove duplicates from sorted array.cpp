#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr){
    int i = 0;
    for (int j = 1; j < arr.size(); j++){
        if (arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

int main(){
    //     Input: nums = [1,1,2]
    // Output: 2, nums = [1,2,_]
    vector<int> arr = {1, 1, 1, 2, 3, 3, 3, 4, 5, 5, 5};
    cout << "Number of unique elements in the array is: " << removeDuplicates(arr) << endl;

    return 0;
}