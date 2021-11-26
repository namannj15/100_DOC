#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	const int mod = 1e9 + 7;
int64_t expo(int64_t a, int64_t b) {
    int64_t ans = 1;
    while (b) {
        if (b & 1)(ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}
    int totalWays(int n, int k) {
        // Code here.
          if (n < k)return 0;
    int64_t ans = 1;
    for (int i = n - k + 1; i <= n - 1; i++)(ans *= i) %= mod;
    for (int i = 1; i <= k - 1; i++)(ans *= expo(i, mod - 2)) %= mod;
    return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n , k;
		cin >> n >> k;
		Solution ob;
		int ans = ob.totalWays(n, k);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends
