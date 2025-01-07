class Solution {
public:
void dfs(int sindex,vector<int> &res,vector<vector<int>> &ans,vector<bool> &use,int n,int k)
{
    if(k==0){
        ans.push_back(res);
        return;
    }
    for(int i=sindex;i<=n;i++){
        if(use[i]==false)
        {
            res.push_back(i);
            use[i]=true;
            dfs(i+1,res,ans,use,n,k-1);
            use[i]=false;
            res.pop_back();
        }
    }
}
vector<vector<int>> combine(int n,int k)
{
       vector<vector<int>> ans;
       vector<int> res;
       vector<bool> use(n+1,false); 
       dfs(1,res,ans,use,n,k);
       return ans;
}
};