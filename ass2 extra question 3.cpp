#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to check if two strings are anagrams
bool areAnagrams(string str1, string str2) {
    // If lengths are not equal, they can't be anagrams
    if (str1.length() != str2.length()) {
        return false;
    }

    // Sort both strings
    sort(str1.begin(), str1.end());  // O(n log n)
    sort(str2.begin(), str2.end());  // O(n log n)

    // Compare sorted strings
    return str1 == str2;             // O(n)
}

int main() {
    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    if (areAnagrams(str1, str2)) {
        cout << "YES, the strings are anagrams.\n";
    } else {
        cout << "NO, the strings are not anagrams.\n";
    }

    return 0;
}

/*
====================
?? TIME COMPLEXITY:
- Let n = length of the strings (same length)
- Sorting both strings ? O(n log n)
- Comparing strings ? O(n)
- Total = O(n log n)

====================
?? SPACE COMPLEXITY:
- Sorting is done in-place for std::string ? O(1) extra space
- So, space complexity = O(1) auxiliary
- Including input strings: O(n) for each ? total O(n)


*/

