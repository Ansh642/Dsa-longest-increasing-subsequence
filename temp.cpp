class Solution
{
    public:
    
    int solve(int n, int a[],int curr,int prev,vector<vector<int>> &dp)
    {
        if(curr==n)
        return 0;
        
        if(dp[curr][prev+1]!=-1)
        return dp[curr][prev+1];      //  +1 becoz prev starts from -1 to avoid error
        
        int include=0;         // RECURSION + MEMOIZATION
        
        if(prev==-1 || a[curr]>a[prev])
          include= 1+ solve(n,a,curr+1,curr,dp);
         
          int exclude=solve(n,a,curr+1,prev,dp);
         
         dp[curr][prev+1]=max(include,exclude);
         
         return dp[curr][prev+1];
    }
    
    int solve2(int n,int a[])
    {
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        //int include=0;
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev=curr-1; prev>=-1; prev--)
            {
                int include=0;
                if(prev==-1 || a[curr]>a[prev])      //TABULATION
                 include= 1+ dp[curr+1][curr+1];
         
               int exclude=dp[curr+1][prev+1];
         
               dp[curr][prev+1]=max(include,exclude);
            }
        }
        return dp[0][0];
        
    }
    
    int longestSubsequence(int n, int a[])
    {
       vector<vector<int>> dp(n,vector<int> (n+1,-1));
       //return solve(n,a,0,-1,dp);
       
       return solve2(n,a);
     cout<<endl<<"Hello";  
    }
};