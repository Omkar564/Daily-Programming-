#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    // Sort the array of strings
    sort(strs.begin(), strs.end());

    // Compare the first and the last strings (as they are most different)
    string first = strs[0];
    string last = strs[strs.size() - 1];
    int i = 0;
    while (i < first.size() && first[i] == last[i]) {
        i++;
    }
    
    // The common prefix will be the part of the first string from 0 to i
    return first.substr(0, i);
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    string result = longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}
