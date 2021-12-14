#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
         auto its = s.begin() , ite = s.begin();
       for(int i=0;i<s.size();i++){
           if(s[i]=='.'){
               reverse(its , ite);
               ite++;
               its = ite;
           }
           else    ite++;
       }
       reverse(its , s.end());
       return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends
