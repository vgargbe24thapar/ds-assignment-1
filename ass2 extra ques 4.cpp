#include <iostream>
#include <vector>
using namespace std;

// Function to sort the array using Dutch National Flag Algorithm
void sort012(vector<int>& arr) {
    int low = 0;               // Boundary for 0s
    int mid = 0;               // Current element to process
    int high = arr.size() - 1; // Boundary for 2s

    // Traverse the array and partition into 0s, 1s, and 2s
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);  // Put 0 to the left region
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;  // Leave 1s in the middle
        } else { // arr[mid] == 2
            swap(arr[mid], arr[high]); // Put 2 to the right region
            high--;
        }
    }
}

int main() {
    vector<int> arr = {0, 2, 1, 2, 0, 1, 2, 0, 1};

    sort012(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
====================
?? TIME COMPLEXITY:
- We process each element at most once.
- So total time = O(n), where n is the size of the array

====================
?? SPACE COMPLEXITY:
- No extra space is used except a few variables ? O(1)
- The sorting is done in-place


*/

