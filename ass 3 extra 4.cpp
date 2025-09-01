#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> s; // stores indices of temperatures in decreasing order

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
            int prevIndex = s.top();
            s.pop();
            answer[prevIndex] = i - prevIndex;
        }
        s.push(i);
    }

    return answer;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temperatures);

    for (int x : result) cout << x << " ";
    return 0;
}

/*
Time Complexity: O(n) - Each index is pushed and popped at most once from the stack.
Space Complexity: O(n) - Stack stores indices and the result array has size n.
*/

