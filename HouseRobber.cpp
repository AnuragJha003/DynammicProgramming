int f(int ind,vector<int> &nums,vector<int> &dp){
    if(ind==0) return nums[ind];//WAHIN NUMBER KO RETURN KRDO
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick=f(ind-2,nums,dp)+nums[ind];
    int np=0+f(ind-1,nums,dp);
    return dp[ind]=max(pick,np);
    
}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n,-1);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int p=nums[i];int np=0;
        if(i>1){
            p+=dp[i-2];
        }
            np=dp[i-1];
        dp[i]=max(p,np);
    }
    return dp[n-1];
}

https://leetcode.com/problems/house-robber/
https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
