
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    { 
        // Your code goes here
        int i=0;
        int j = n-1;
        int res = 0;
        while(i<j){
            int temp = (j-i-1)*min(height[i],height[j]);
            res = max(res,temp);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
       }
       return res;
    }   
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int height[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>height[i];
    	}
    	
    	Solution obj;
    	
    	cout << obj.maxCandy(height,n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
