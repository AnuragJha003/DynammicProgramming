int f(int ind,vector<int>& height,int k,dp){
if(ind==0)return 0;
int mn=INT_MAX;
if(dp[ind]!=-1)return dp[ind];
for(int j=1;j<=k;j++){
if(ind-j>=0){
int d=f(ind-j,height,k) + abs(hegiht[ind]-height[ind-j]);
mn=min(mn,d);
}
}
return dp[ind]=mn;
}
vector<int> dp(n+1,-1);
//TIME COMPLEXITY IS:O(N *K) THAT IS FOR EACH N STATES/JUNCTIONS  OF THE HEIGHT THERE ARE K POSSIBILITIES IN THERE 
//SC IS O(N) RECURSSIVE STACK SPACE AND O(N) FOR MEMOIZATION DP K LIYE 

//TABULATION APPROACH O(N*K) WITH SC ONL O(N) FOR THE DP ARRAY 
dp[0]=0;
for(int i=1;i<=n;i++){
for(int j=1;j<=k;j++){
int mn=INT_MAX;
if(i-j>=0){
int d=dp[i-j] + abs(hegiht[i]-height[i-j]);
mn=min(mn,d);
}
}
dp[i]=mn;
}
return dp[n-1];

https://atcoder.jp/contests/dp/tasks/dp_b
