#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<long long> st;
    long long minElement;

public:
    void push(int x) {
        if (st.empty()) {
            st.push(x);
            minElement = x;
        } else if (x >= minElement) {
            st.push(x);
        } else {
            st.push(2LL * x - minElement); // Encode
            minElement = x;
        }
    }

    void pop() {
        if (st.empty()) return;
        if (st.top() >= minElement) {
            st.pop();
        } else {
            minElement = 2LL * minElement - st.top(); // Decode previous min
            st.pop();
        }
    }

    int top() {
        if (st.empty()) return -1;
        if (st.top() >= minElement) return st.top();
        return minElement; // Encoded value, actual top is minElement
    }

    int getMin() {
        if (st.empty()) return -1;
        return minElement;
    }
};

int main() {
    MinStack s;
    s.push(5);
    s.push(3);
    s.push(7);
    cout << "Min: " << s.getMin() << endl; // 3
    s.pop();
    cout << "Min: " << s.getMin() << endl; // 3
    s.pop();
    cout << "Min: " << s.getMin() << endl; // 5
    return 0;
}

