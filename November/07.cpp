//https://practice.geeksforgeeks.org/problems/anagram-1587115620/1#
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
         if(a.size()!=b.size())
         return 0;
         
         unordered_map<int,int> m;
         for(int i=0;i<a.size();i++)
         {
             m[a[i]]++;
         }
         
         for(int i=0;i<a.size();i++)
         {
              if(m[b[i]]==0)
              return 0;
              m[b[i]]--;
         }
          return 1;
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends
