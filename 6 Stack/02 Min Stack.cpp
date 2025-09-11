#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<long long> s;   
    long long minVal;     

    MinStack() {}

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minVal = val;
        } else {
            if (val < minVal) {
                s.push(2LL * val - minVal);
                minVal = val;
            } else {
                s.push(val);
            }
        }
    }

    void pop() {
        if (s.empty()) return; 
        long long topVal = s.top();
        s.pop();
        if (topVal < minVal) {
            minVal = 2LL * minVal - topVal;
        }
    }

    int top() {
        if (s.empty()) return INT_MIN; 
        long long topVal = s.top();
        if (topVal < minVal) {
            return (int)minVal;
        } else {
            return (int)topVal;
        }
    }

    int getMin() {
        if (s.empty()) return INT_MIN; 
        return (int)minVal;
    }
};

int main() {
    
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << "getMin() -> " << ms.getMin() << '\n'; // -3
    ms.pop();
    cout << "top() -> " << ms.top() << '\n';      // 0
    cout << "getMin() -> " << ms.getMin() << '\n'; // -2

    return 0;
}
