class Solution {
public:
  int f(int i,int j,vector<int>& a,vector<vector<int>>& dp){
    if(i>j) return 0;//LIKE IF I J WALA INTERBVAL SE AAGE BAD GYA SO NOT POSSIBLE FOR COIN COLLECTION SO RETURN 0 
    if(dp[i][j]!=-1) return dp[i][j];
    int maxi=INT_MIN;
    //IN THIS FOR EACH SUBINTERVAL TO BE SILVED INDEPENDELTY WE START FRO THE POSSIBLITY OF BALLOON TO BE BURST AT LAST 
    for(int ind=i;ind<=j;ind++){//THIS FOR LOOP IS CONSIDERING EACH ELMNT IN THAT INTERVAL TO BE THE LAST 
        int cost=(a[i-1]*a[ind]*a[j+1]) + f(i,ind-1,a,dp)+f(ind+1,j,a,dp);
        maxi=max(maxi,cost);
    }//CONSIDERED OPP FLOW THAT IS FROM THE LAST BALLOON TO BE BURST WE TAKE THE SUBINTERVALS CAN BE SOLVED INDIVUALLY 
    return dp[i][j]=maxi;;
}

   int maxCoins(vector<int>& a)
{
    int n=a.size();
    a.push_back(1);
    a.insert(a.begin(),1);//1 and 1 inserted at the beginning and end of the arrray to go out of bounds 
    vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
    return f(1,n,a,dp);
   }
};
//tabulation 
int maxCoins(vector<int>& a)
{
    int n=a.size();
    a.push_back(1);
    a.insert(a.begin(),1);
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    //return f(1,n,a,dp);
    //BASE CASE ALREADY COPIED AS EVERYTHING IS INITLIASED WITH 0 FROM THE BEGINNING NO NEED TO WRITE AGAIN 
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
             if(i>j) continue;//IMPORTANT OTHERWISE RUN NHI KREGA:) 
             int maxi=INT_MIN;
            for(int ind=i;ind<=j;ind++){
         int cost=(a[i-1]*a[ind]*a[j+1]) + dp[i][ind-1]+dp[ind+1][j];
        maxi=max(maxi,cost);
    }
            dp[i][j]=maxi;
        }
	// Write your code here.
}
    return dp[1][n];
}
 https://leetcode.com/problems/burst-balloons/
