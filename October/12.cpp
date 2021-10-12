#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    int l,r;
        long int s=0;
        long int count=0;
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            l=i+1;
            r=n-1;
            while(l<r){
                
                s=arr[i]+arr[l]+arr[r];
                
                if (s>=sum){
                    r--;
                }
                
                else{
                    count+=r-l;
                    l++;
                }
                
            }
            
        }
        
        return count;
    
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
