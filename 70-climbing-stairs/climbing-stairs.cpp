class Solution {
public:
    int dp[46];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = climbStairs(n-1) + climbStairs(n-2); //or + and * 
    }
};