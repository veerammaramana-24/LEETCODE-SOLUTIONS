#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int total = 0;
        for (int num : nums)
        {
          total = (total + num) % p;
        }
        if (total == 0) return 0;
        unordered_map<int, int> prefix;
        prefix[0] = -1;  
        int prefixSum = 0, minlength = n;
        for (int i = 0; i < n; i++) 
        {
            prefixSum = (prefixSum + nums[i]) % p;
            int result = (prefixSum - total + p) % p;
            if (prefix.find(result) != prefix.end()) {
               minlength = min(minlength, i - prefix[result]);
            }
            prefix[prefixSum] = i;
        }
        return minlength == n ? -1 : minlength;
    }
};