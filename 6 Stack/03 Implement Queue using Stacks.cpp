// #include <bits/stdc++.h>
// using namespace std;

// class MyQueue {
// public:
//     stack<int> s1;
//     stack<int> s2;

//     MyQueue() {}
//     void push(int val) {
//         // Move everything from s1 -> s2
//         while (!s1.empty()) {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         // Push new value
//         s1.push(val);
//         // Move everything back to s1
//         while (!s2.empty()) {
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }

//     int pop() {
//         int ans = s1.top();
//         s1.pop();
//         return ans;
//     }

//     int peek() {
//         return s1.top();
//     }

//     bool empty() {
//         return s1.empty();
//     }
// };


//efficient version  all functions amortized O(1).

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {}

    // Push in O(1)
    void push(int val) {
        s1.push(val);
    }

    // Pop in amortized O(1)
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ans = s2.top();
        s2.pop();
        return ans;
    }

    // Peek in amortized O(1)
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front: " << q.peek() << "\n"; // 1
    cout << "Pop: " << q.pop() << "\n";   // 1
    cout << "Front after pop: " << q.peek() << "\n"; // 2

    cout << (q.empty() ? "Queue is empty\n" : "Queue is not empty\n");

    q.pop();
    q.pop();
    cout << (q.empty() ? "Queue is empty\n" : "Queue is not empty\n");

    return 0;
}
