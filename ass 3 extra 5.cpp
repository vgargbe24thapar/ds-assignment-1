#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isSortable(vector<int>& A) {
    stack<int> S;
    vector<int> B;
    int expected = 1;
    int N = A.size();
    
    for (int i = 0; i < N; ++i) {
        S.push(A[i]);
        while (!S.empty() && S.top() == expected) {
            B.push_back(S.top());
            S.pop();
            expected++;
        }
    }

    // After processing A, check if remaining stack can be popped in order
    while (!S.empty() && S.top() == expected) {
        B.push_back(S.top());
        S.pop();
        expected++;
    }

    return (B.size() == N);
}

int main() {
    vector<int> A = {4, 1, 2, 3}; // Example input
    if (isSortable(A)) {
        cout << "Yes, array A can be sorted into B using stack operations.\n";
    } else {
        cout << "No, it's not possible to sort array A into B using stack operations.\n";
    }
    return 0;
}

/*
Time Complexity: O(n) - Each element is pushed and popped at most once.
Space Complexity: O(n) - Stack and B may hold up to n elements.
*/

