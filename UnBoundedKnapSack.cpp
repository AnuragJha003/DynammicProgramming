int f(int ind,int W,vector<int> &val,vector<int> &wt,vector<vector<int>> &dp){
    if(ind==0){
        return ((int)(W/wt[0]) * val[0]);//can be taken as many times for the 0th index in there 
        //taking it in the int format to prevent overflow and fractional issues 
    }//INFINTE SUPPLY BASE CONDITION 
    if(dp[ind][W]!=-1) return dp[ind][W];
    int nt=f(ind-1,W,val,wt,dp);
    int take=0;
    //possible to take if the weight indexed elmnt is less than equal to the possible wiehgt capacity left 
    if(wt[ind]<=W) take=val[ind]+f(ind,W-wt[ind],val,wt,dp);//can be taken infinite times toh so index not changed to ind-1 rkhna 
    return dp[ind][W]=max(nt,take);
}
//ONLY REC WILL GIVE TLE 
//MEMO WORKS





int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    //vector<vector<int>>dp(n,vector<int>(w+1,-1));
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    //return f(n-1,w,profit,weight,dp);
    for(int wi=0;wi<=w;wi++){
        dp[0][wi]=(int)(wi/weight[0]) * profit[0];
    }//base case 
    for(int ind=1;ind<n;ind++){
        for(int wi=0;wi<=w;wi++){//2 nested loops applied 
            int nt=dp[ind-1][wi];
            int take=0;
            if(weight[ind]<=wi)
                take=profit[ind]+dp[ind][wi-weight[ind]];
            dp[ind][wi]=max(nt,take);
        }
    }
    return dp[n-1][w];
}
https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
