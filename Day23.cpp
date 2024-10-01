#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(const vector<int>& arr, int k) {
    vector<int> result;      // To store the maximums of each window
    deque<int> dq;          // To store indices of useful elements

    for (int i = 0; i < arr.size(); i++) {
        // Remove indices that are out of the current window
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Remove elements that are less than the current element
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }

        // Add the current element's index to the deque
        dq.push_back(i);

        // If the window has reached size k, add the maximum to the result
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    vector<int> maxValues = maxSlidingWindow(arr, k);

    cout << "Sliding window maximums: ";
    for (int val : maxValues) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
