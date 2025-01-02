class Solution {
public:
    int findMiddleIndex(vector<int>& nums) 
    {
        int n=nums.size();
        int sum=0;
        int add=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            if(add==(sum-add-nums[i]))
            {
                return i;
            }
            add+=nums[i];
        }
        return -1;
    }
};