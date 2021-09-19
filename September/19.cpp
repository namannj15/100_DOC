//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        int l=array1.size();
        int m=array2.size();
        
        for(int i=0;i<m;i++){
            array1.push_back(array2[i]);
        }
       
        sort(array1.begin(),array1.end());
       
        double med = 0;
       
        if((l+m)%2==0){
            med = (array1[(l+m)/2-1]+array1[(l+m)/2])/2.0;
        }
       
        else{
            med = array1[(l+m)/2];
        }
       
        return med;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends
