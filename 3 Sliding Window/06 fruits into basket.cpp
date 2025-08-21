#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits){
    int ans = 0, left = 0;
    unordered_map<int, int> count;

    for (int right = 0; right < fruits.size(); right++){

        count[fruits[right]]++;

        // erase if more than 2 types
        while (count.size() > 2){
            count[fruits[left]]--;
            if (count[fruits[left]] == 0){
                count.erase(fruits[left]);
            }
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}
int main(){
    vector<int> fruits = {1, 2, 3, 2, 2};
    cout << "the number of fruits we can collect is: " << totalFruit(fruits);
    return 0;
}