class Solution {
public:
    void recur(vector<int>& nums,vector<vector<int>>&ans,vector<int>&current,  int n,int index)
    {
        if(index>=n){
            ans.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        recur(nums,ans,current,n,index+1);
        current.pop_back();
        while(index+1<n && nums[index]==nums[index+1]){
            index++;
        }
        recur(nums,ans,current,n,index+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          vector<vector<int>>ans;
            vector<int>current;
            int n = nums.size();
            sort(nums.begin(),nums.end());
            recur(nums,ans,current,n,0);
            reverse(ans.begin(),ans.begin());
            return ans;
    }   
    
};