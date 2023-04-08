int f(int ind,int w,vector<int> &weight, vector<int> &value,vector<vector<int>> &dp){//w is the capacity of the knaosack
    if(ind==0){//if reached till end 
        if(weight[ind]<=w){//wieght of that particular index lesser than capaxity matlab le skte ho then 
            return value[0];//return that value 
        }
        else{
            return 0;//else dont return a value 
        }
    }//BASE CASE
    
    //0/1 means take not take types 
    if(dp[ind][w]!=-1) return dp[ind][w];
    int nottake=0+f(ind-1,w,weight,value,dp);//not take 
    int take=INT_MIN;//take initilae=sed with INT_MIN 
    if(weight[ind]<=w){//if max capaicty se kam h given weight ka index  
        take=value[ind]+f(ind-1,w-weight[ind],weight,value,dp);//add that value to take and then call the recurssive call max capacity reduced from w to w-weight[ind]
    }
    return dp[ind][w]=max(nottake,take);//max of the two options returned     
}
//ONLY REC WILL GIVE TLE 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));//2d dp with 2 changing parameters 
    return f(n-1,maxWeight,weight,value,dp);
    /*
    for(int w=0;w<maxWeight;w++){
    dp[0][w]=value[0];
    }
    for(int i=1;i<n;i++){
    for(int j=0;j<maxWeight;j++){
    recurance code here gg 
    }
    } */
}

https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
