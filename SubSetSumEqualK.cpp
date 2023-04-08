bool f(int ind,int target,vector<int> &arr,vector<vector<int>> &dp){
    if(target==0) return true;
    if(ind==0) return (arr[ind]==target);
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool nottake=f(ind-1,target,arr,dp);
    bool take=false;
    if(arr[ind]<=target){
        take=f(ind-1,target-arr[ind],arr,dp);
    }
    return dp[ind][target]=take|nottake;
}
//RECURSSION WILL GIVE TLE  TC IS O(2^N TAKE NOT TAKE)
//MEMOIZATION WORKS

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    //vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    //return f(n-1,k,arr,dp);
   // vector<bool>prev(k+1,0),curr(k+1,0);
   vector<vector<bool>> dp(n,vector<bool>(k+1,false)); //DEFINED FOR TABULATION TABULATION KE DEFINE ONLY IN TERMS OF 1 AND 0 AS BOOL H NA YEH 
   for(int i=0;i<n;i++){
       dp[i][0]=true;
   }//base case 
   dp[0][arr[0]]=true;//BASE CASES 
   for(int i=1;i<n;i++){
       for(int tar=1;tar<=k;tar++){
            bool nottake=dp[i-1][tar];
    bool take=false;
    if(arr[i]<=tar){
        take=dp[i-1][tar-arr[i]];
    }
     dp[i][tar]=take|nottake;
       }
   }

    return dp[n-1][k];
   // return prev[k];
}

https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
