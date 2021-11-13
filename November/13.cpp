#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
         stack<char>st;
       string cl = "])}";
       string op = "[({";
       for(int i=0;i<x.size();i++)
       {
           if(!st.empty() && cl.find(x[i])!= string::npos)
           {
               while(!st.empty() && st.top()==op[cl.find(x[i])])
               {
                   st.pop();
                   i++;
               }
           }
           if(x[i]!='\0')
               st.push(x[i]);
       }
       
       return st.empty();
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
