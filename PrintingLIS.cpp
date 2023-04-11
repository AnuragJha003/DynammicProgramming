   vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+1, 0));
   //BASE CASE INITILIASTION DONE 
   for(int i=n-1;i>=0;i--){
   for(int prev=i-1;prev>=-1;prev--){
   //nested loop for the changing parameters in the opposite flow of recurance 
     int maxi=-1e9, not_take=0, take=0;
        //copy the recurance
         not_take=0+dp[i+1][prev+1];//not take index i moved ahead just and prev+1 for the 1 based shifting  IN DP WE HV 1 BASED SHIFTING FOR THE PREV INDEX TO AVOID NEGATIVE VALUES OF INDEX  
         if(prev==-1 || nums[i]>nums[prev]){
            take= 1+dp[i+1][i+1];//1 based shifting for the previous one   
        }//u can take only if prev is the very first u can for the first case as no prev and 
        //u can take if the current elmnt is greater than prev and it is a increasing subsequence 
         maxi=max(take, not_take);//take the maximum 
         dp[i][prev+1]=maxi;
         }
         }
         
         return dp[0][-1+1];
         }//TABULATION FOR THE LIS QUESTION TC IS O(N2) WILL GIVE TLE IF N IS 10^5 .. U WILL USE BINARY SEARCH FOR THAT NLOGN 
  
  
  //DP[I] RETURNS THE LENGHT OF THE LIS ENDING AT INDEX I 
  //ANOTHER TABULATION APPROACH WITH SC O(N)
  int mx=1;int last_index=0;//last index of the lis 
  vector<int> dp(n,1),hash(n);
  //hash will store the previous index of the current element in its increasing subsequence 
  for(int i=0;i<n;i++){
  hash[i]=i;
  for(int prev=0;prev<i;prev++){
  if(nums[i]>nums[prev] && 1+dp[prev]>dp[i]){
  dp[i]=1+dp[prev];//if nums i is mre than previous index in here then dp[i] length of lis till index i will be dp[i] or 1 +dp[prev] as ith index ko uss LIS m consider krle then 
  hash[i]=prev;//PREV INDEX IN THE LIS FOR THE ITH ELEMENT 
   }
   }
   if(dp[i]>mx){
  mx=dp[i]);//storing the max of lis ending at index i for all index i
  last_index=i;//storing the last index of a possible LIS 
   }
   }
   vector<int>temp;
   temp.push_back(nums[last_index]);//LAST ELMNT OF THE LIS
   while(hash[last_index]!=last_index){
   last_index=hash[last_index];//move to the previous index for the lis // 5 6 11 H LIS 11 IS STORED GO THE INDEX POINTING THE LEMNT 6 
   temp.push_back(nums[last_index]);
   }
   reverse(temp.begin(),temp.end());
   return temp;//RETURN THE LIS 
  //return mx;
  }
