int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector
<int>> &dp){

     if(ind == 0){//if index is 0 
        if(target==0 && arr[0]==0)//2 possible ways
            return 2;
        if(target==0 || target == arr[0])//if target is 0 or equal to arr[0]
            return 1;//return 1 possible ways 
        return 0;//return 0
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = countPartitionsUtil(ind-1,target,arr,dp);//not take 
    int taken = 0;
    if(arr[ind]<=target)
        taken = countPartitionsUtil(ind-1,target-arr[ind],arr,dp);
        //take
    return dp[ind][target]= (notTaken + taken)%mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    
    /*int sum = 0;
    for(int x : arr)    sum += x;
    
    if(d > sum || (sum + d) % 2)    return 0;
    
    return countSubsets(arr, n, (sum + d) / 2);*/
    //int n = arr.size();
    int totSum = 0;
    for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-d<0) return 0;
    if((totSum-d)%2==1) return 0;
    
    int s2 = (totSum-d)/2;//count number of subset with this sum 
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return countPartitionsUtil(n-1,s2,arr,dp);//recurance called 
}

https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
