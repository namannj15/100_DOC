//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool find4Numbers(int A[], int n, int X);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, x;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin>>x;
        cout << find4Numbers(a, n, x) << endl;

    }
    return 0;
}// } Driver Code Ends


//User function Template for C++

bool find4Numbers(int a[], int n, int X)  
{
   sort(a,a+n);
    for(int i=0; i<n-3; i++){
        for(int j=i+1; j<n-2; j++){
            int start = j+1,end = n-1;
            int target = X-a[i]-a[j];
            while(start < end){
                if(a[start]+a[end] == target){
                    return true;
                }
                else if(a[start]+a[end] < target){
                    start += 1;
                }
                else{
                    end -= 1;
                }
            }
        }
    }
    
    return false; 
}
