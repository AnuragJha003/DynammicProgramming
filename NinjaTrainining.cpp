int f(int day,int last, vector<vector<int>> &points,vector<vector<int>> &dp){
    if(day==0){
        int maxi=0;
        for(int j=0;j<3;j++){//traversing for all possible tasks which could be performed 
            if(j!=last){//if not equal to the last task done as consecutive nhi ho skta na 
                maxi=max(maxi,points[0][j]);//maxi is keeping max of them 
            }
        }
        return maxi;
    }//if day reached to the last day base case 
    if(dp[day][last]!=-1) return dp[day][last];
    int maxi=0;int point=0;
   //a
    for(int i=0;i<3;i++){//tasks traversal 
        if(i!=last){//if it is not the last performed task so gg 
           point=points[day][i]+f(day-1,i,points,dp);
           maxi=max(maxi,point);
        }
    }
    return dp[day][last]=maxi;
}
//time complexity is o(n*4) *3(for every tasks)
//sc is o(n)recurssive stack space +o(n*4)dp size 
int ninjaTraining(int n, vector<vector<int>> &points)
{
    //vector<vector<int>> dp(n,vector<int>(4,-1));//MEMOIZATION STEP 
    //0 1 2  3 means none of them hv been performed 
    vector<int> prev(4,0);
    //return f(n-1,3,points,dp);//REC APPROACH TLE SO MEMOIZATION
    // Write your code here.
    //TABULATION
    /*dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));
    for(int day=1;day<n;day++){//opposite to recurssive flow
        for(int last=0;last<4;last++){//now last can be 0 1 2 and 3(none performed)
            dp[day][last]=0;//INITILASED the two for loops above are the changing parameters in here for the day and last 
        for(int task=0;task<3;task++){//traversing all the possible tasks in here 
            if(task!=last){
                int point=points[day][task]+dp[day-1][task];
                dp[day][last]=max(dp[day][last],point);
            }
        }//similar to loop a in recurance and memoization 
    }
    }
    return dp[n-1][3]; */
    }
    https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
