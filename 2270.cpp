class Solution {
public:
    int waysToSplitArray(vector<int>& nums)
    {
        int n=nums.size();
        int counter=0;
        long long sum=0;
        long long add=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        for(int i=0;i<n-1;i++){
            add+=nums[i];
            if(add>=(sum-add)){
                counter++;
            }
        }
        return counter;   
    }
};