#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(const string& s) {
    unordered_map<char, int> charIndexMap;
    int maxLength = 0;
    int start = 0;

    for (int i = 0; i < s.length(); i++) {
        if (charIndexMap.find(s[i]) != charIndexMap.end() && charIndexMap[s[i]] >= start) {
            start = charIndexMap[s[i]] + 1;
        }
        charIndexMap[s[i]] = i;
        maxLength = max(maxLength, i - start + 1);
    }

    return maxLength;
}

int main() {
    string S = "abcabcbb";
    cout << "Length of the longest substring without repeating characters: " 
         << lengthOfLongestSubstring(S) << endl;
    return 0;
}
