class Solution {
public:
    void dfs(int k, int n, int index, vector<int>& ans, vector<vector<int>>& res) {
        if (ans.size() == k && n == 0) {
            res.push_back(ans);
            return;
        }
        if (ans.size() > k || n < 0) {
            return;
        }
        for (int i = index; i <= 9; i++)
        {
            ans.push_back(i); 
            dfs(k, n - i, i + 1, ans, res); 
            ans.pop_back(); 
        }
    }

vector<vector<int>> combinationSum3(int k, int n)
{
        vector<vector<int>> res;
        vector<int> ans;
        dfs(k, n, 1, ans, res); 
        return res;
}
};