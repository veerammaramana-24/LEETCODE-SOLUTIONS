class Solution {
public:
    double helper(double x,long n)
    {
        if(n==0){return 1.0;}
        if(x==0){return 0.0;}
        if(n==1){return x;}
        double ans=helper(x,n/2);
        ans=ans*ans;
        if(n%2!=0)
        {
            ans=ans*x;
        }
        return ans;
    }
    double myPow(double x, int n) 
    { 
       long a=(long)n;
       double final=helper(x,abs(a));
       if(n>=0)
       {
        return final;
       }
       return 1/final; 
    }
};