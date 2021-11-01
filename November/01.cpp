#include<bits/stdc++.h>
using namespace std;
class Solution{

 // } Driver Code Ends
	public:
void numbers_maker(int arr[],int n,int d)
{
    arr[0]=n;
    for(int i=1;i<d;i++)
    {
        arr[i]=arr[i-1]/10 + arr[i-1]%10 * pow(10,d-1);
    }
}
int primechecker(int num)
{
    if(num==1 )
        return 0;
   if(num==2)
    return 1;
    for(int i=2;i<num;i++)
    {
        if(num%i==0)
            return 0;
    }
        return 1;
}

int isCircularPrime(int n) {
       int d=0,p=n;
       while(p!=0)
       {
           p=p/10;
           d++;
       }
       int arr[d];
       numbers_maker(arr,n,d);
       for(int i=0;i<d;i++)
       {
           if(primechecker(arr[i])!=1)
               return 0;
       }
       return 1;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.isCircularPrime(n);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends
