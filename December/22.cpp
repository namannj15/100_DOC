#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
         long long int i = 0, sum = 0;
    sort(a,a+n);
    while(--k >= 0 && a[i] <= 0 && i<n) 
    	a[i++] *= (-1);
    if(k>=0 && (k+1)%2) 
    	sum = *min_element(a,a+n) * (-1);
    return accumulate(a, a + n, 0)+sum+sum;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends
