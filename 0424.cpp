class Solution 
{
  public:
  int characterReplacement(string s, int k) {
        int n=s.length();
        int i=0;
        int j=0;
        int maxi=0;
        int ans=0;
        unordered_map<char,int>up;
        while(j<n){
            up[s[j]]++;
            for(auto it : up){
                maxi=max(maxi,it.second);
                // cout<<maxi;
            }
            while((j-i+1)-maxi > k){
                up[s[i]]--;
                if(up[s[i]]==0){
                    up.erase(s[i]);
                }
                i++;
                for(auto&it : up){
                    maxi=max(maxi,it.second);
                    // cout<<maxi;
                }
            }
            for(auto it : up){
                maxi=max(maxi,it.second);
                // cout<<maxi;
            }
            ans=max(ans,j-i+1);
            j++;

        }
        return ans;
    }
};
