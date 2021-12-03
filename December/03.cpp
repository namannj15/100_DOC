// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
         int c=0;
        for(int i=0;i<n;i++) {
            if(arr[i]<=k) c++;
        }
        int t=0;
        for(int i=0;i<c;i++) {
            if(arr[i]<=k) t++;
        }
        int res=c-t;
        for(int i=1;i+c<=n;i++) {
            if(arr[i-1]<=k) t--;
            if(arr[i+c-1]<=k) t++;
            res=min(res,c-t);
        }
        return res;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends
