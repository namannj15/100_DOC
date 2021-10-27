#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    string convert(string s, int n) {
        //code
        if(n == 1){
            return s;
        }
        // sine wave traversal, just like spiral traversal
        string ans = "";
        string flag = "";
        int cnt = 0;
        vector<string> v(n);
        for(int i=0; i<(int)s.size(); i++){
            v[cnt] += s[i];
            if(cnt == n-1){
                flag = "up";
            }
            if(cnt == 0){
                flag = "down";
            }
            if(flag == "up"){
                cnt -= 1;
            }
            else{
                cnt += 1;
            }
        }
        for(int i=0; i<n; i++){
            ans += v[i];
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while (t--){
        string str;
        cin>>str;
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.convert(str, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends