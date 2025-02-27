class Solution {
public:
   int robLinear(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);  // DP array to store max money at each house
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];  // The last element stores the max money we can rob
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // Case 1: Exclude last house (rob from index 0 to n-2)
        vector<int> case1(nums.begin(), nums.end() - 1);
        // Case 2: Exclude first house (rob from index 1 to n-1)
        vector<int> case2(nums.begin() + 1, nums.end());

        return max(robLinear(case1), robLinear(case2));
    }
};