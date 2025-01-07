#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0); 
        auto isVowel = [](char c) 
        {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        for (int i = 0; i < n; i++) {
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                prefix[i + 1] = prefix[i] + 1;
            } else {
                prefix[i + 1] = prefix[i];
            }
        }
        vector<int> result;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            result.push_back(prefix[r + 1] - prefix[l]);
        }

        return result;
    }
};