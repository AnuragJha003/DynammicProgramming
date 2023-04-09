
class Solution{
  public:
    /*int cutRod(int price[], int n) { THIS IS THE CORRECT GREEDY APPROACH 
        //code here
        int len=0;
        int pr=0;int mxp=INT_MIN;
        for(int i=0;i<n-1;i++){
            len=(i+1);
            pr=price[i];
            for(int j=i+1;j<n;j++){
                if(n-2==(i+j)){
                    pr=pr+price[j];
                    mxp=max(mxp,pr);
                }
            }
        }
        return mxp;
    }*/
    int cutRodUtil(int price[], int ind, int N, vector<vector<int>>& dp){
        if(ind == 0){
        return N*price[0];
        }//can tkae that price or item n times as it is of length 1
    
    if(dp[ind][N]!=-1)

        return dp[ind][N];
    
    int notTaken = 0 + cutRodUtil(price,ind-1,N,dp);
    int taken = INT_MIN;
    int rodLength = ind+1;//current rod length is index +1 for the 1 based indexin in there 
    
    
    if(rodLength <= N)//if rod lenght is less than the available amt of rod lenght required then u 
        taken = price[ind] + cutRodUtil(price,ind,N-rodLength,dp);//price + f(price,ind-1,n-rodlength which will be th
    return dp[ind][N] = max(notTaken,taken);

}
int cutRod(int a[],int n) {
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    //return cutRodUtil(a,n-1,n,dp);
    for(int i=0;i<n;i++){
        dp[0][i]=i*a[0];
    }//base case 
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){//nested for loop parameter change in the opposite flow of recurance 
         int notTaken = 0 + dp[i-1][j];
    int taken = INT_MIN;
    int rodLength = i+1;//current rod length is index +1 for the 1 based indexin in there 
    
    
    if(rodLength <= j)//if rod lenght is less than the available amt of rod lenght required then u 

        taken = a[i] + dp[i][j-rodLength]; 
     dp[i][j] = max(notTaken,taken);
        }
    }
    return dp[n-1][n];
}
};

https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rod-cutting0840
