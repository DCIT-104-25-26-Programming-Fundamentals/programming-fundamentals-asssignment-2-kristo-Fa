// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

using namespace std;

int getSum(const vector<int>& nums) {
    int total = 0;
    for (int i = 0; i < nums.size(); i++) {
        total += nums[i];
    }
    return total;
}

double getAverage(const vector<int>& nums) {
    int total = 0;
    for (int i = 0; i < nums.size(); i++) {
        total += nums[i];
    }
    return (double)total / nums.size();
}

int getMax(const vector<int>& nums) {
    int maximum = nums;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > maximum) {
            maximum = nums[i];
        }
    }
    return maximum;
}

int getMin(const vector<int>& nums) {
    int minimum = nums;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < minimum) {
            minimum = nums[i];
        }
    }
    return minimum;
}

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int temp;
        cout << "Enter number " << (i + 1) << ": ";
        cin >> temp;
        numbers.push_back(temp);
    }

    cout << endl << "Results:" << endl;
    cout << "Sum:     " << getSum(numbers) << endl;
    cout << "Average: " << getAverage(numbers) << endl;
    cout << "Maximum: " << getMax(numbers) << endl;
    cout << "Minimum: " << getMin(numbers) << endl;

    return 0;
}
