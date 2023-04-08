int f(int ind,int sum,vector<int> &num, vector<vector<int>> &dp){
    //if(sum==0) return 1;
    if(ind==0){
        if(sum==0 && num[0]==0) return 2;//
        if(sum==0 || sum==num[0]) return 1;
        return 0;
    } //return (num[0]==sum);
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    int nottake=f(ind-1,sum,num,dp);
    int take=0;
    if(num[ind]<=sum) take=f(ind-1,sum-num[ind],num,dp);
    
    return dp[ind][sum]=nottake+take;
}


//ONY REC WILL GIVE TLE o(2^n)PICK NOT PICK GG  

int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    return f(n-1,tar,num,dp);
    // Write your code here.
}
TC IS O(N*SUM) SC IS O(N*SUM) FOR DP+O(N) FOR RECURSSIVE STACK SPACE  
https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
