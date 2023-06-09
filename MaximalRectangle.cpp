class Solution {
public:
    //HEIGHT VECTOR CREATE KRO
    //IF 1 THEN KEEP ADDING AND IF 0 THEN RESET IT 
    //THEN MAX AREA OF HISTOGRAM TYPE 
    
    int largestRectangleArea(vector<int>& heights) {
        int ns[heights.size()],ps[heights.size()];//VECTOR FOR PUSHING NEXT AND PREVIOUS SMALLER ELEMTNS INDEX
        stack<int> nss,pss;//STACK FOR THE ABOVE SAME 
        int maxi=INT_MIN;//MAXI IS INT_MIN OF THE PART 
        
		//To find Previous smaller element
        for(int i=0;i<heights.size();i++){
            while(!pss.empty() && heights[pss.top()]>=heights[i]){//LARGER OR EQUAL ELEMT KO POP OUT KRTE RHO THATS IT FROM THE STACK PORTION
                pss.pop();
            }
            if(pss.empty()){
                ps[i]=(-1);//EMPTY H MEANS THERS NO PREVIOUS SMALLER ELEMNT 
            }else{
                ps[i]=(pss.top());//ELSE TOPMOST WALA HI HOGA  PSS VECTOR IS STROING THE NUMBER 
            }
            
            pss.push(i);/// WE R PUSHINHG THE INDEX AT THAT LOCATION IN HERE
        }
		
		//To find next smaller element
        for(int i=heights.size()-1;i>=0;i--){
            while(!nss.empty() && heights[nss.top()]>=heights[i]){
                nss.pop();
            }
            if(nss.empty()){
                ns[i]=(heights.size());//AUR KOI NEXT GREATR ELMNT NA MILE THEN PUSH BACK THE SIZED INDEX IN HERE
            }else{
                ns[i]=(nss.top());
            }
            nss.push(i);///....SAME IN HERE
        }
        
		 //To find height of each rectangle formed using given formula
         for(int i=0;i<heights.size();i++){
             int cur=(ns[i]-ps[i]-1)*heights[i];//CURRENT AREA FORMULA
             maxi=max(maxi,cur);//HAR BAAR MAXIMUM CHAHIYE SO USED
         }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();int m=matrix[0].size();
        vector<int> v(m,0);
        //for(int j=0;j<m;j++){
        //    v.push_back((int)(matrix[0][j]));
        //}
        //int mx=largestRectangleArea(v);//MAX AREA HISTOGRAM TYPE
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    v[j]=0;//RESET TO 0
                }
                else{
                    v[j]++;
                }
            }
            mx=max(mx,largestRectangleArea(v));
        }
        
        return mx;
        
        
    }
};

/*
 int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> curr(n, 0);
        
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')     curr[j]++;
                else    curr[j]=0;
            }
            int area = maxarea(curr);
            ans=max(ans, area);
        }
        
        return ans;
    }
};*/


https://leetcode.com/problems/maximal-rectangle/
