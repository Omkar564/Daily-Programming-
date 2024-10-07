#include <iostream>
#include <vector>

using namespace std;

// Function to compute the n-th Fibonacci number
int fibonacci(int n) {
    // Create a vector to store Fibonacci numbers up to n
    vector<int> fib(n + 1);

    // Base cases
    fib[0] = 0;
    if (n > 0) {
        fib[1] = 1;
    }

    // Build the Fibonacci sequence from the bottom up
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Return the n-th Fibonacci number
    return fib[n];
}

int main() {
    int n;
    cout << "Enter a non-negative integer (0 ≤ n ≤ 1000): ";
    cin >> n;

    // Check if the input is within the specified range
    if (n < 0 || n > 1000) {
        cout << "Please enter a valid integer within the range." << endl;
        return 1;
    }

    // Calculate and display the n-th Fibonacci number
    int result = fibonacci(n);
    cout << "F(" << n << ") = " << result << endl;

    return 0;
}
