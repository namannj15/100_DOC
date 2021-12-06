/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
      int count(int m, int n, int k) {
        int ans = 0;
        for(int i=1; i<=m && i<=k; i++) {
            ans += i*n <= k? n : k/i;
        }
        return ans;
    }
public:
    int KthSmallest(int m, int n, int k) {
        //Write your code here
        int start = 1, end = m*n;
        while(start < end) {
            int mid = start + (end - start)/2;
            if(count(m,n,mid) >= k)
                end = mid;
            else
                start = mid+1;
        }
        return start;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n, k;
	    cin >> m >> n >> k;
	    Solution ob;
	    int ans = ob.KthSmallest(m, n, k);
	    cout << ans << endl;
	}
	return 0;
}
  // } Driver Code Ends
