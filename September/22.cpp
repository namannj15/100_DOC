//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{

    public:
    int repeatedStringMatch(string A, string B) 
    {
        // Your code goes here
        int count=1;
        string s=A;
        while(A.find(B)==string::npos && A.size()<=B.size()+s.size()){
            A.append(s);
            count++;
        }
        if(A.find(B)==string::npos){
            return -1;
        }
        else{
            return count;
        }
    }
  
};

// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution obj;
        cout<<obj.repeatedStringMatch(A,B)<<"\n";
    }
    return 0;
}
  // } Driver Code Ends
