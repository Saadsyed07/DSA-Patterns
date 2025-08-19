#include <bits/stdc++.h>
using namespace std;

vector<int> movesZero(vector<int> &arr){
    int i = 0;
    for (int j = i + 1; j < arr.size(); j++){

        while (arr[i] != 0){
            i++;
        }

        if (arr[j] != 0){
            arr[i] = arr[j];
            arr[j] = 0;
            i++;
        }
    }
    return arr;
}

int main(){

    vector<int> arr = {0, 1, 0, 3, 12};
    vector<int> ans = movesZero(arr);
    for (int el : ans){
        cout << el << " ";
    }
    return 0;
}