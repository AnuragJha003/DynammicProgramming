int f(int ind,int T,vector<int> &num,vector<vector<int>> &dp){
    if(ind==0){
        if(T%num[ind]==0) return T/num[ind];
        else return 1e9;
    }
    if(dp[ind][T]!=-1) return dp[ind][T];
    int nt=0+f(ind-1,T,num,dp);
    int t=INT_MAX;//tkae int max initialise 
    if(T>=num[ind]) t=1+f(ind,T-num[ind],num,dp);
    return dp[ind][T]=min(nt,t);
}
//ONLY REC WILL GIVE TLE 
//MEMOIZATION WORKS 
//NOW TABULATION SEEN SUBMITTED SUXCCESS

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(x+1,0));
    for(int T=0;T<=x;T++){
        if(T%num[0]==0) dp[0][T]=T/num[0];
        else dp[0][T]=1e9;
    }//BASE CASE OF TABU 0 TO N-1 OPP OF RECURSSION 
    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=x;T++){
             int nt=0+dp[ind-1][T];
             int t=INT_MAX;
            if(T>=num[ind]) t=1+dp[ind][T-num[ind]];
            dp[ind][T]=min(nt,t);
        }
    }
    
    
    //int ans=f(n-1,x,num,dp);
    int ans=dp[n-1][x];
    if(ans>=1e9) return -1;//TO PREVENTY OVERFLOW 
    return ans;
}

https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dpseries&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dpseries
https://leetcode.com/problems/coin-change/
