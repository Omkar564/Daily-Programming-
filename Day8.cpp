#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    // Step 1: Use a stringstream to split the string into words
    stringstream ss(s);
    string word;
    vector<string> words;
    
    // Step 2: Extract words and store them in a vector
    while (ss >> word) {
        words.push_back(word);
    }
    
    // Step 3: Reverse the vector of words
    reverse(words.begin(), words.end());
    
    // Step 4: Join the words back into a single string
    string result;
    for (size_t i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i != words.size() - 1) {
            result += " ";
        }
    }
    
    return result;
}

int main() {
    string s = "the sky is blue";
    cout << reverseWords(s) << endl;  // Output: "blue is sky the"
    return 0;
}
