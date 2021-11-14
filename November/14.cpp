#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
     if(s.size() & 1) return -1;
    int curr=0, res = 0;
    for(auto it:s) {
        if(it == '{') curr++;
        else if(it == '}') curr--;
        if(curr < 0) res++, curr+=2;
    }
    res += curr/2;
    return res;
}
