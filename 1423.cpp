//METHOD-1

// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n = cardPoints.size();
//         int Sum = 0;
//         for (int i = 0; i < cardPoints.size(); ++i) {
//             int point = cardPoints[i];
//             Sum += point;
//         }
//         int K = n - k;
//         int minSubarraySum = 0, currentSum = 0;
//         for (int i = 0; i < n; ++i) {
//             currentSum += cardPoints[i];
//             if (i >= K) {
//                 currentSum -= cardPoints[i - K];
//             }
//             if (i >= K - 1) {
//                 minSubarraySum = (minSubarraySum == 0) ? currentSum : min(minSubarraySum, currentSum);
//             }
//         }
//         return Sum - minSubarraySum;
//     }
// };

//METHOD-2
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k)
    {
     int n=cardPoints.size();
     int window=n-k;
     int min_Sum=INT_MAX;
     int i=0,j=0,ws=0;
     int sum=0;
     for(int i=0;i<n;i++)
     {
        sum+=cardPoints[i];
     }
    
     if(k==n)
     {
        return sum;
     }
     while(j<n)
     {
        if(j-i+1<window)
        {
            ws+=cardPoints[j];
            j++;
        }
        else
        {
            ws=ws+cardPoints[j];
            min_Sum=min(min_Sum,ws);
            ws=ws-cardPoints[i];
            i++;
            j++;
        }
     } 
     
     return sum-min_Sum; 
    }
};