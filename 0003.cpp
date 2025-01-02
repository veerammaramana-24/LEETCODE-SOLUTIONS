class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0, j = 0, ans = 0;
        unordered_map<char, int> freq;
        while (j < n) {
            freq[s[j]]++;
            while (freq[s[j]] > 1) {
                freq[s[i]]--;
                if (freq[s[i]] == 0) {
                    freq.erase(s[i]);
                }
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        
        return ans;
    }
};