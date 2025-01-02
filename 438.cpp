class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.length();
        int k=p.length();
        int i=0;
        int j=0;
        vector<int>res;
        map<char,int>mp1,mp2;
        for(int m=0;m<k;m++){
            mp1[p[m]]++;
        }
        while(j<n){
            if((j-i+1)<k){
                mp2[s[j]]++;
                j++;
            }else{
                mp2[s[j]]++;
                if(mp1==mp2){ 
                    res.push_back(i);
                }
                mp2[s[i]]--;
                if(mp2[s[i]]==0){
                    mp2.erase(s[i]);
                }
                i++;
                j++;
            }
        }
        return res;
        
    }
};