//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
    
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int largestPowerof2(int n){
        int x = 0;
        while((1 << x) <=n){
            x++;
        }
        return x-1;
    }
    int countSetBits(int n)
    {
        if(n==0){
            return 0;
        }
        
        int y = largestPowerof2(n);
        int setBitsY = y*(1 << y-1);
        int Bits2YtoN = n - (1 << y) + 1;
        int rem = n - (1 << y);
        int ans = setBitsY + Bits2YtoN + countSetBits(rem);
        
        return ans;
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends
