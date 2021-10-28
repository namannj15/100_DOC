//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>> dp(a,vector<int>(b,0));
        
        /* 
        Filling dp array
        intially all set to 0 
             0 0 0 
             0 0 0
             0 0 0
             0 0 0 
        first row and first column set to 1 
        // but for dp[0][0] should be 0 but it's giving wrong so make it 1      
             1 1 1 
             1 0 0 
             1 0 0
             1 0 0
           // now run loop for each row starting from 1 and then for each column of each row from 1th column
           // and fill dp array 
           // dp[i][j]=dp[i-1][j]+dp[i][j-1]
           
             0 1 1 
             1 2 3 
             1 3 6
             1 4 10
             
             
            // last element of dp array is ans
        */
        dp[0][0]=1;
        for(int i=1;i<b;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<a;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<a;i++){
           for(int j=1;j<b;j++){
               dp[i][j]=dp[i-1][j]+dp[i][j-1];
           }   
        }
        return dp[a-1][b-1];
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends