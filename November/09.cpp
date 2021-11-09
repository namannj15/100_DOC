//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    
    public:
    int digitsum(int n){
        int sum=0;
        while(n>0){
            int rem=n%10;
            sum+=rem;
            n/=10;
        }
        return sum;
    }
    int RulingPair(vector<int> arr, int n) 
    { 
    	// Your code goes here
    	map<int,priority_queue<int>,greater<int>> mp;
    	for(int i=0;i<n;i++){
    	    mp[digitsum(arr[i])].push(arr[i]);
    	}
    	int ans=-1;
    	for(auto u:mp){
    	    if(u.second.size()>=2){
    	        int res=u.second.top();
    	        u.second.pop();
    	        res+=u.second.top();
    	        u.second.pop();
    	        ans=max(ans,res);
    	    }
    	}
    	return ans;
    }   
};


// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
	    Solution obj;
		cout << obj.RulingPair(arr,n)<<"\n";
	}
	return 0; 
} 

  // } Driver Code Ends
