class Solution {
public:
    void dfs(vector<int>& candidates, int target, int index, vector<int>& ans, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(ans); 
            return;
        }
        if (target < 0)
        {
             return; 
        }
        for (int i = index; i < candidates.size(); i++) {
            ans.push_back(candidates[i]); 
            dfs(candidates, target - candidates[i], i, ans, res); 
            ans.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        dfs(candidates, target, 0, ans, res);
        return res;
    }
};