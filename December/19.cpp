
 // } Driver Code Ends
class Solution {
  public:
    string encryptString(string S) {
        // code here
        map<char,int> m;
        for(int i=0;i<S.length();i++){
            m[S[i]]++;
        }
        for(auto i=m.rbegin();i!=m.rend();i++){
            printf("%x%c",(*i).second,(*i).first);
        }
    
    }
};

// { Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout<<ob.encryptString(S)<<endl;
    }
    return 0;
}  // } Driver Code Ends
