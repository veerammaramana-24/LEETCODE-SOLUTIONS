class Solution {
public:
    int m=1e9+7;
    long long power(int x,long long n)
    {
        if(n==0){return 1;}
        if(x==0){return 0;}
        long long ans=power(x,n/2);
        ans=((ans)*(ans))%m;
        if(n%2!=0)
        {
            ans=(ans*(x%m))%m;
        }
        return ans;
    }
    int countGoodNumbers(long long n)
    {
       long long even=n/2 + n%2;
       long long odd=n/2;
       int res=(power(5,even)*power(4,odd))%m;
       return res; 
    }
};