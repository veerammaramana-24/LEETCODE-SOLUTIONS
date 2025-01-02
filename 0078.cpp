class Solution {
public:
    void subset(vector<int>& A,vector<vector<int>>& res,vector<int>& ans,int index)
    {
        res.push_back(ans);
        for(int i=index;i<A.size();i++)
        {
            ans.push_back(A[i]);
            subset(A,res,ans,i+1);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& A) 
    {
       vector<int>ans;
       vector<vector<int>>res;
       int index=0;
       subset(A,res,ans,index);
       return res; 
    }
};