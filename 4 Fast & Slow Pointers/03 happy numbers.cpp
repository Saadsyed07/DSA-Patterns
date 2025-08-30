#include <bits/stdc++.h>
using namespace std;

int numberSquare(int n){
    int num = 0;

    while (n != 0){
        num += (n % 10) * (n % 10);
        n /= 10;
    }
    return num;
}

bool isHappy(int n){
    int slow, fast;
    slow = fast = n;

    do{
        slow = numberSquare(slow);               // moves +1
        fast = numberSquare(numberSquare(fast)); // moves +2
    } while (slow != fast);

    return (slow == 1);
}
int main(){
    cout << isHappy(19);
    return 0;
}