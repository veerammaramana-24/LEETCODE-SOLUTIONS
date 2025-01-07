#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t)
    {
        if (s.length() < t.length()) return "";
        
        unordered_map<char, int> t_count;  
        unordered_map<char, int> window_count; 
        for (char c : t) 
        {
            t_count[c]++;
        }
        
        int left = 0, right = 0;
        int required = t_count.size();
        int formed = 0; 
        int min_len = INT_MAX;
        int min_left = 0; 
        while (right < s.length())
        {
            char c = s[right];
            window_count[c]++;
            if (t_count.find(c) != t_count.end() && window_count[c] == t_count    [c]) {
                formed++;
            }
            while (left <= right && formed == required)
            {
                char c_left = s[left];
                if (right - left + 1 < min_len)
                {
                    min_len = right - left + 1;
                    min_left = left;
                }
                window_count[c_left]--;
                if (t_count.find(c_left) != t_count.end() && window_count[c_left] < t_count[c_left]) {
                    formed--;
                }
                left++;
            }
            
            right++;
        }
        
        return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
    }
};
