class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) 
    {
       int n=arr.size();
        int sum=0;
        int counter=0;
        unordered_map<int,int>up{{0,1}};
        for(int i=0;i<n;i++){
            sum=(sum+(arr[i]%k)+k)%k;
            counter+=up[sum];
            up[sum]++;
            
        }
        return counter;
    }  
};