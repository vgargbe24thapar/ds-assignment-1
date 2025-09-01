#include <iostream>
#include <vector>
using namespace std;

// Function to duplicate each occurrence of 2 in-place
void duplicateTwos(vector<int>& arr) {
    int n = arr.size();
    int possibleDups = 0;
    int last = n - 1;

    // First pass: count how many 2s can be duplicated within bounds
    for (int i = 0; i <= last - possibleDups; i++) {
        if (arr[i] == 2) {
            // Edge case: check if duplicating this 2 would exceed bounds
            if (i == last - possibleDups) {
                arr[last] = 2; // Only one copy fits at the end
                last--;
                break;
            }
            possibleDups++;
        }
    }

    // Second pass: work backwards and shift/duplicate 2s
    int i = last - possibleDups;

    for (int j = last; i >= 0; i--) {
        if (arr[i] == 2) {
            arr[j--] = 2;     // First copy of 2
            if (j >= 0) {
                arr[j--] = 2; // Second copy of 2
            }
        } else {
            arr[j--] = arr[i]; // Shift non-2 element
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 4, 5, 2};

    duplicateTwos(arr);

    cout << "Modified array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
====================
?? TIME COMPLEXITY:
- First pass: O(n) — count potential 2s to be duplicated
- Second pass: O(n) — iterate from back and modify in-place
- Total = O(n), where n is the array size

====================
?? SPACE COMPLEXITY:
- No extra data structures used
- Modifications done in-place
- Only a few extra variables ? O(1) space


*/

