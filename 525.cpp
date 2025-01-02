class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {   
        int n=nums.size();
        unordered_map<int,int>up{{0,-1}};
        int len=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(nums[i]==0)?-1:1;
            cout<<sum;
            if(up.count(sum)){
                len=max(len,i-up[sum]);
                // cout<<len;
            }else{
                    
                up[sum]=i;
            }
        }
        
        return len; 
    }
};