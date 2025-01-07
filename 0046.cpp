class Solution {
public:
void dfs(vector<int> &res,vector<vector<int>> &ans,vector<bool> &use,vector<int>nums)
{
    if(res.size()==nums.size()){
        ans.push_back(res);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(use[i]==false)
        {
            res.push_back(nums[i]);
            use[i]=true;
            dfs(res,ans,use,nums);
            use[i]=false;
            res.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int>& nums)
{
       vector<vector<int>> ans;
       vector<int> res;
       vector<bool> use(nums.size(),false); 
       dfs(res,ans,use,nums);
       return ans;
}
};