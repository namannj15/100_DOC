//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++


class Solution{
    
    public:
    long long ValidPair(int a[], int n) 
    { 
    	// Your code goes here 
    	sort(a,a+n);
        int i=0,j=n-1;
        long long count=0;
        while(i!=j){
            if(a[i]+a[j]>0){
                count+=j-i;
                j--;
            }
            
            else if(a[i]+a[j]<=0){
                i++;
            }
        }
        return count;
    }   
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int array[n];
		for (int i = 0; i < n; ++i)
			cin>>array[i];
	    Solution obj;
		cout << obj.ValidPair(array, n) <<"\n";
	}
	return 0; 
} 

  // } Driver Code Ends
