class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        int n=arr.size();
        int pre[n];
        pre[0]=arr[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]^arr[i];
        }
        
        int m=queries.size();
        vector<int>arr2;
        for(int i=0;i<m;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            if(l==0){
                arr2.push_back(pre[r]);
            }
            else{
                int x=pre[r]^pre[l-1];
                arr2.push_back(x);
            }
        }
        return arr2;   
    }
};