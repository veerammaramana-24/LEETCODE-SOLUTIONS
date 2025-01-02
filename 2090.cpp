class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n, -1);
        if (2 * k + 1 > n) 
             return result;
        long long Sum = 0;
        int K = 2 * k + 1;
        for (int i = 0; i < K; ++i) {
            Sum += nums[i];
        }
        result[k] = Sum / K;
        for (int i = k + 1; i < n - k; ++i) {
            Sum += nums[i + k] - nums[i - k - 1]; 
            result[i] = Sum / K;
        }

        return result;
    }
};