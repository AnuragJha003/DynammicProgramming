int findWays(vector<int> &num, int tar)
{
    //int n=num.size();
    //vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    //return f(n-1,tar,num,dp);
    //TABULtion approach
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,0));
    //for(int i=0;i<n;i++){
    //    dp[i][0]=1;
   //THIS REMVED AS SUM 0 WALA PRT YEH  }
    if(num[0]==0) dp[0][0]=2;
    else dp[0][0]=1;
    
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]]=1;
    
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=tar;sum++){
            int notTake=dp[ind-1][sum];
            int take=0;
            if(num[ind]<=sum) take=dp[ind-1][sum-num[ind]];
    
             dp[ind][sum]=(take+notTake);
        }
    }
    return dp[n-1][tar];
}
// Write your code here.
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    //s1-s2=tar s2=totsum-d/2 
    int totsum=0;
    for(auto &it:arr) totsum+=it;
    if(totsum-d<0 || (totsum-d)%2!=0) return false;//base case this is 
    return findWays(arr,(totsum-d)/2); //findways tabulated code call kro 
    //s1-s2=d/target 
    //s1+s2=totsum 
    //so find s1 as fnc of totsuma and d and then search for it in the array if possible 
}
int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    //all positives go to s1 and it is +ve s1 and all -ves assigned go to s2
    //and we have s1-s2=target we count the partition with given difference like in earlier questions 
    return  countPartitions(n,target,arr);
}


https://leetcode.com/problems/target-sum/
https://www.codingninjas.com/codestudio/problems/target-sum_4127362?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
