class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int n=gain.size();
        int sum=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi+=gain[i];
            sum=max(sum,maxi);
        }
        return sum;
    }
};