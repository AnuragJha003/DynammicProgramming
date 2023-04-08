int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int totsum=0;
    for(int i=0;i<n;i++) totsum+=arr[i];
    int k=totsum;
vector<vector<bool>>dp(n,vector<bool>(k+1,0));//DEFINED FOR TABULATION TABULATION KE DEFINE ONLY IN TERMS OF 1 AND 0 AS BOOL H NA YEH 
    for(int i=0;i<n;i++)dp[i][0]=true;//MEANS FOR ANY INDEX WHEN TARGET BCMS ZERO THEN TRUE RHEGA 
    if(arr[0]<=k) dp[0][arr[0]]=true;//MEANS LAST INDEX TAK AAGYE AND THEN ARR[0]IS EQUAL TO TARGET THEN EQUATE IT TO ZERO 
    //RECURRNACE KA OPP FLOW HOTA H IN TABULATION
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool nottake=dp[ind-1][target];
            bool take=false;
            if(target>=arr[ind]) take=dp[ind-1][target-arr[ind]];
            dp[ind][target]=nottake|take;
        }
    }//last row of the dp formed in the 2d dp in here  CHECKED 
    //till here DP L14 TABULARISATION 
    //2d dp formed traverse thru the lasst row of the 2d dp table formed 
    int mini=1e9;
    //TRAVERSE FOR 0 TO TOTSUM 
    for(int s1=0;s1<=totsum;s1++){//try all possible sum for the 1st subset and it wil be for the last row of dp only as from there only the diff wil be minimum from there 
        if(dp[n-1][s1]==true){//means possible h for s1 then 
            mini=min(mini,abs((totsum-s1)-s1));//minimu of abs(totsum-s1)//totsum-s1=s2;
        }
    }
    return mini;
   
}

https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
