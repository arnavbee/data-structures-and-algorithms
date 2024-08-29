#include <unordered_set>
#include <string>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string str) {
        // If the input string is empty, return 0 as there's no substring to evaluate.
        if (str.size() == 0)
            return 0;

        std::unordered_set<char> set; // This set will store the characters in the current window (substring) without duplicates.
        int maxans = 0;               // This variable will store the maximum length of a substring found so far.
        int i = 0;                    // 'i' will be the starting index of the current window (substring).
        int j = 0;                    // 'j' will be the ending index of the current window (substring).

        // We use a while loop to move 'j' across the string.
        while (j < str.length()) {
            // If the character at 'j' is not already in the set, it's not a duplicate.
            if (set.find(str[j]) == set.end()) {
                set.insert(str[j]); // Add the character to the set.
                
                // Update the maximum length of the substring. 
                // 'j - i + 1' is the current length of the window (substring).
                maxans = std::max(maxans, j - i + 1);
                
                // Move 'j' to the next character to expand the window.
                j++;
            } else {
                // If the character at 'j' is already in the set, it's a duplicate.
                // We need to shrink the window by removing the character at 'i' from the set
                // and moving 'i' forward.
                set.erase(str[i]);
                i++; // Move the starting index 'i' to the right.
            }
        }

        // Return the maximum length of the substring without repeating characters.
        return maxans;
    }
};