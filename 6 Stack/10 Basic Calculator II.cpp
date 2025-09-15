#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {
    stack<long long> st;
    long long num = 0;
    char op = '+';  // previous operator
    
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0');  // build number
        }

        // If operator OR last character
        if ((!isdigit(c) && !isspace(c)) || i == s.size() - 1) {
            if (op == '+') st.push(num);
            else if (op == '-') st.push(-num);
            else if (op == '*') {
                long long t = st.top(); st.pop();
                st.push(t * num);
            }
            else if (op == '/') {
                long long t = st.top(); st.pop();
                st.push(t / num);
            }

            op = c;   // update operator
            num = 0;  // reset number
        }
    }

    // Sum all values in stack
    long long total = 0;
    while (!st.empty()) {
        total += st.top();
        st.pop();
    }
    return (int)total;
}

int main() {
    cout << calculate("3+2*2") << endl;     // 7
    cout << calculate(" 3/2 ") << endl;     // 1
    cout << calculate(" 3+5 / 2 ") << endl; // 5
}
