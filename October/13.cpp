
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
 bool recursion(string A,string B,string C,int l,int m,int n)
    {
        if(l==A.length() && m==B.length() && n==C.length())
        {
            return true;
        }
        if(n==C.length())
        {
            return false;
        }
        return (A[l]==C[n] && recursion(A,B,C,l+1,m,n+1)) || (B[m]==C[n] && recursion(A,B,C,l,m+1,n+1));
    }
    bool isInterleave(string A, string B, string C) 
    {
        return recursion(A,B,C,0,0,0);
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends
