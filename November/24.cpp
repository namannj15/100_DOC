#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long res = 0;
    int lMax = 0, rMax = 0, l = 0, r = n-1;
    while(l <= r) {
        if(arr[l] <= arr[r]) {
            if(arr[l] > lMax) lMax = arr[l];
            else res += lMax - arr[l];
            l++;
        } else {
            if(arr[r] > rMax) rMax = arr[r];
            else res += rMax - arr[r];
            r--;
        }
    }
    return res;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
