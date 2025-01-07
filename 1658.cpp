#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total_sum = 0;
        for (int num : nums) 
        {
            total_sum += num;
        }
        if (x > total_sum)
        {
            return -1;
        }
        int target = total_sum - x;
        int current_sum = 0;
        int i = 0;
        int max_len = -1;
        for (int j = 0; j < nums.size(); j++)
        {
            current_sum += nums[j];
            while (current_sum > target && i <= j) {
                current_sum -= nums[i];
                i++;
            }
            if (current_sum == target) {
                max_len = max(max_len, j - i + 1);
            }
        }
        return max_len == -1 ? -1 : nums.size() - max_len;
    }
};
