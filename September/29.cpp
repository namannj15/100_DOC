//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_set>
using namespace std; 

 // } Driver Code Ends
//User function Template for C++


class Solution{
    public:
    int candies(int m, int n) 
    { 
    	// Your code goes here
    	 if(m>n)
       {
           if(m%2==0)
           return (m/2)*(n-1) - (n/2);
           else
           return (m/2)*(n-1);
       }
       else
       {
           if(n%2==0)
           return (n/2)*(m-1) - (m/2);
           else
           return (n/2)*(m-1);
       }
    } 
};

// { Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		Solution obj;
		cout << obj.candies(m,n)<<endl; 
	}
	return 0; 
} 



  // } Driver Code Ends
