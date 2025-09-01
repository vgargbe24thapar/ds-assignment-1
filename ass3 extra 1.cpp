#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nearestSmallerElements(const vector<int>& A) {
    stack<int> s;
    vector<int> result;
    for (int x : A) {
        while (!s.empty() && s.top() >= x) s.pop();
        result.push_back(s.empty() ? -1 : s.top());
        s.push(x);
    }
    return result;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> res = nearestSmallerElements(A);
    for (int x : res) cout << x << " ";
    return 0;
}
//Time Complexity: O(n)
//Space Complexity: O(n)
