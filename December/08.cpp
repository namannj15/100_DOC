#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            // your code here
             if(n == 1){
                return 2*arr[0];
            }
            sort(arr,arr+n);
            if(arr[n-1] < 0){
                return arr[n-1] + arr[n-2];
            }else if(arr[0] > 0){
                return arr[0] + arr[1];
            }
            int l=0,h=n-1,ans=INT_MAX;
            while(l<h){
                int sum = arr[l]+arr[h];
                if(abs(ans) > abs(sum)){
                    ans = sum;
                }else if(abs(ans) == abs(sum)){
                    ans = max(ans,sum);
                }
                if(sum < 0){
                    l++;
                }else{
                    h--;
                }
            }
            return ans;
        }
};

// { Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}  // } Driver Code Ends
