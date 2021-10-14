//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	// Your code here
    	unsigned int res = 0;
    	for(int i=31; i>0; i-=2){
    	    int firstPos = (n>>i)&1;//n&((unsigned int)1<<i);
    	    int secondPos = (n>>(i-1))&1;//n&((unsigned int)1<<(i-1));
    	    res = res*2+secondPos;
    	    res = res*2+firstPos;
    	}
    	return res;
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}  // } Driver Code Ends
