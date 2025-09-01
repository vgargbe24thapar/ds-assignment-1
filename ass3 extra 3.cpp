#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s; // stores indices

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> res = nextGreaterElement(arr);

    for (int x : res) cout << x << " ";
    return 0;
}

/*
Time Complexity: O(n) - Each element is pushed and popped at most once.
Space Complexity: O(n) - Stack and result array store up to n elements.
*/

