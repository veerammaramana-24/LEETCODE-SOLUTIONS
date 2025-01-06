class Solution {
public:
   bool hasAllCodes(string s, int k) {
        int n=s.length();
        set<string>s1;
        string str;
        int i=0;
        int j=0;
        while(j<n){
            if(j-i+1 < k){
                str=str+s[j];
                j++;
            }else{
                str=str+s[j];
                s1.insert(str);
                if(s1.size()==pow(2,k)){
                    return true;
                }
                str=str.erase(0,1);
                i++;
                j++;
            }
        }
            return false;
    }
};