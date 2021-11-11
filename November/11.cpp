//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
        // code here
            long long sumL = 0, sumM = 0, res = 0;
    int l = 0, r = 0, m = 0;
    while(r < N && sumL+A[r] < L) sumL += A[r++];
    sumM = sumL;
    while(r<N) {
        sumL += A[r];
        sumM += A[r];
        while(sumL > R) sumL -= A[l++];
        while(sumM - A[m] >= L) sumM -= A[m++];
        res += (m-l+1);
        r++;
    }
    return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}    // } Driver Code Ends
