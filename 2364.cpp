#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long totalPairs = (long long)n * (n - 1) / 2;
        unordered_map<int, int> freq;
        long long goodPairs = 0;

        for (int i = 0; i < n; ++i) {
            int value = i - nums[i];
            if (freq.count(value)) {
                goodPairs += freq[value];
            }
            freq[value]++;
        }

        return totalPairs - goodPairs;
    }
};