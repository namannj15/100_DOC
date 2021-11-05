#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {
    sort(a1,a1+n);
    sort(a2,a2+m);
    int flag=0,check;
    for(int i=0;i<n-m+1;i++){
        if (a1[i]==a2[0]){
            check=1;
            int mate=i+1;
            while(check<m){
                if(a2[check]==a1[mate]){
                    check++;
                    mate++;
                }
                
                else{
                    mate++;
                }
                
                if(mate>=n)
                    break;
            }
        }
        
        if (check==m){
            flag=1;
            break;
        }
        
    }
    
    if(flag==1)
        return "Yes";
        
    else
        return "No";
}
