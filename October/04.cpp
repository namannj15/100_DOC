#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int ans = -1;
	    int current = 0;
	    for(char x: S){
	        
	       if(x == '1'){ 
	        current=current-1;
	       }
	       
	       else{
	        current=current+1;
	       }
	       
	       ans = max(ans , current);
	       
	       if(current < 0){
	        current = 0;
	       }
	       
	   }
	   return ans;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends
