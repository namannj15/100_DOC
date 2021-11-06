//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long a, long long b) 
    {
        //code here
        if(a== 0) return 0;
        int sign = 1;
        if(a<0 && b>0) sign = -1;
        if(b<0 && a>0) sign = -1;
        
        a = abs(a);
        b = abs(b);
        int x = b;
        int count,result=0;
        while(a - b >= 0){
            count = 1;
            while((a - (b<<1)) >= 0){
                count = count<<1;
                b = b<<1;
            }
            a = a-b;
            b = x;
            result = result+count;
        }
        
        return sign*result;
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}
  // } Driver Code Ends
