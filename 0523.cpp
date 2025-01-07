#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> good;
        good[0] = -1; 
        int sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (k != 0) 
            {
                sum %= k;
            }
            if (good.find(sum) != good.end())
            {
                if (i - good[sum] > 1)
                {
                    return true;
                }
            } 
            else 
            {
                good[sum] = i;
            }
        }
        
        return false;
    }
};
