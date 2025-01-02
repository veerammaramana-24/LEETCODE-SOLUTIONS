class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n=nums.size();
        int mul=1;
        int mul2=1;
        int counter=0;
        for(int i=0;i<n;i++){
            mul=mul*nums[i];
            if(nums[i]!=0){
                mul2=mul2*nums[i];
            }
            if(nums[i]==0){
                counter++;
            }
        }
        vector<int>arr;
        for(int i=0;i<n;i++){
            if(nums[i]==0 && counter>1){
                 arr.push_back(0);
            }else if(nums[i]==0 && counter<=1){
                arr.push_back(mul2);
            }
            else if(nums[i]!=0){
                arr.push_back(mul/nums[i]);
            }
        }
        return arr;
    }
};