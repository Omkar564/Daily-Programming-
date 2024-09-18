#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// Function to group anagrams
std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> anagramMap;

    for (const std::string& str : strs) {
        std::string sortedStr = str;
        std::sort(sortedStr.begin(), sortedStr.end());
        anagramMap[sortedStr].push_back(str);
    }

    std::vector<std::vector<std::string>> result;
    for (const auto& entry : anagramMap) {
        result.push_back(entry.second);
    }

    return result;
}

int main() {
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> groupedAnagrams = groupAnagrams(strs);

    std::cout << "[";
    for (size_t i = 0; i < groupedAnagrams.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < groupedAnagrams[i].size(); ++j) {
            std::cout << "\"" << groupedAnagrams[i][j] << "\"";
            if (j < groupedAnagrams[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        if (i < groupedAnagrams.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
