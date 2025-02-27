class Solution {
public:
    void solve(vector<vector<int>>& visited,vector<vector<char>>& grid,int i,int j)
    {
        if(i<0||i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0'||visited[i][j]== true)
        {
            return;
        }
        visited[i][j]= true;
        //top
        solve(visited,grid,i-1,j);
        //left
        solve(visited,grid,i,j-1);
        //down
        solve(visited,grid,i+1,j);
        //
        solve(visited,grid,i,j+1);

    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n =grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j] ==false && grid[i][j]=='1')
                {
                    solve(visited,grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};