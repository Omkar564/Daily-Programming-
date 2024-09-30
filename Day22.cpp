#include <iostream>
#include <vector>
#include <unordered_map>

int findFirstKTimes(const std::vector<int>& arr, int k) {
    std::unordered_map<int, int> frequency;

    // Count the occurrences of each element
    for (int num : arr) {
        frequency[num]++;
    }

    // Find the first element that appears exactly k times
    for (int num : arr) {
        if (frequency[num] == k) {
            return num;
        }
    }

    // If no such element exists
    return -1;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 2, 3, 4, 2, 3, 5};
    int k = 2;

    int result = findFirstKTimes(arr, k);
    std::cout << "The first element that appears exactly " << k << " times is: " << result << std::endl;

    return 0;
}
