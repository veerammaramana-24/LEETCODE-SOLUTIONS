#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0 || s.empty()) return 0;

        unordered_map<char, int> charCount; // Frequency of characters in the current window
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.size(); ++right) {
            charCount[s[right]]++;

            // If there are more than k distinct characters, shrink the window
            while (charCount.size() > k) {
                charCount[s[left]]--;
                if (charCount[s[left]] == 0) {
                    charCount.erase(s[left]);
                }
                left++;
            }

            // Update the maximum length of the window
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
