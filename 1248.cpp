#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        auto countAtMostK = [&](int k) 
        {
            int count = 0;
            int i = 0;
            int oddCount = 0;
            for (int j = 0; j < nums.size(); j++) 
            {
                if (nums[j] % 2 == 1) 
                {
                    oddCount++;
                }
                while (oddCount > k) 
                {
                    if (nums[i] % 2 == 1) 
                    {
                        oddCount--;
                    }
                    i++;
                }
                count += j - i + 1;
            }
            return count;
        };
        return countAtMostK(k) - countAtMostK(k - 1);
    }
};
