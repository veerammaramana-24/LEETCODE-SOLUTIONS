class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.length();
        int i=0,j=0;
        int ans=0;
        int k=3;
        unordered_map<char,int> freq;
        while(j<n){
            if(j-i+1<k){
                freq[s[j]]++;
                j++;
            }
            else{
                freq[s[j]]++;
                if(freq.size()==k){
                    ans++;
                }
                freq[s[i]]--;
                if(freq[s[i]]==0){
                    freq.erase(s[i]);
                }
                i++;
                j++;
            }
        
        }
        return ans;
    }
};