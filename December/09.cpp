//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

// return a string formed by compressing string s
// do not print anything

class Solution{
    public:
     #define ll long long
    #define MOD 1000000007
    
    ll binpow(ll a,ll b){
        ll ans = 1;
        while(b>0){
            if(b&1){
                ans = (ans*a)%MOD;
            }
            a = (a*a)%MOD;
            b>>=1;
        }
        return ans;
    }
    string compress(string s)
    {
        // Your code goes here
        ll p = 31;
        ll n = s.length();
        vector<ll> hash(n+1),ppow(n+1,1),inv(n+1,1);
        for(ll i=1;i<=n;i++){
            ppow[i] = (ppow[i-1]*p)%MOD;
            inv[i] = binpow(ppow[i],MOD-2);
        }
        for(ll i=0;i<n;i++){
            hash[i+1] = (s[i]-'a'+1)*ppow[i];
            hash[i+1]%=MOD;
            hash[i+1] = (hash[i]+hash[i+1])%MOD;
        }
        string ans = "";
        ll i = n;
        while(i>=1){
            if(i&1){
                ans.push_back(s[--i]);
                continue;
            }
            ll m = i / 2;
            ll val1 = hash[m];
            ll val2 = (hash[i]-hash[m]+MOD)%MOD;
            val2 = (val2*inv[m])%MOD;
            if(val1==val2){
                ans.push_back('*');
                i = m;
            }
            else{
                ans.push_back(s[--i]);
            }
        }
        reverse(ans.begin(),ans.end());
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
        string s;
        cin>>s;
        Solution obj;
        cout<< obj.compress(s) << "\n";
    }
    return 0;
}
  // } Driver Code Ends
