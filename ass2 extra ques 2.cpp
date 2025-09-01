#include <iostream>
#include <string>
using namespace std;

// Function to check if any one substring is a substring of the other two
bool isSplittable(const string& s) {
    int n = s.length();

    // Try all possible splits: S1 = s[0..i-1], S2 = s[i..j-1], S3 = s[j..n-1]
    for (int i = 1; i < n - 1; i++) {           // O(n)
        for (int j = i + 1; j < n; j++) {       // O(n)

            string s1 = s.substr(0, i);         // O(n) in worst case
            string s2 = s.substr(i, j - i);     // O(n)
            string s3 = s.substr(j);            // O(n)

            // Check all 3 conditions:
            // Case 1: s1 is a substring of s2 and s3
            if (s2.find(s1) != string::npos && s3.find(s1) != string::npos)
                return true;

            // Case 2: s2 is a substring of s1 and s3
            if (s1.find(s2) != string::npos && s3.find(s2) != string::npos)
                return true;

            // Case 3: s3 is a substring of s1 and s2
            if (s1.find(s3) != string::npos && s2.find(s3) != string::npos)
                return true;

            // Each find() is O(n), so this whole check is O(n)
        }
    }

    // If no valid split found
    return false;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    if (isSplittable(s)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

/*
====================
?? TIME COMPLEXITY:
- Two nested loops ? O(n^2)
- Inside each iteration:
  - Substring operations: O(n)
  - Find operations: O(n)
- Total per iteration: O(n)
- Total: O(n^3)

====================
?? SPACE COMPLEXITY:
- Temporary strings s1, s2, s3 ? each up to O(n)
- So space used = O(n)

====================

*/

