#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here 
        sort(arr,arr+N);
        int maxsum = 0;
        int i = N-1;
        while(i > 0){
            int j = i-1;
            if(arr[i] - arr[j] < K) { 
                maxsum += arr[i] + arr[j];
                i = j - 1; 
            }
            else{
                i = j;
            }
        }
        return maxsum;
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
