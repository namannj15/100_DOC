
class Solution:
    def factorial(self, N):
        #code here
        ans=1
        if N==0:
            return str(1)
        else:
            while(N>=1):
                ans=ans*N
                N=N-1
        return str(ans)

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t=int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        ans = ob.factorial(N);
        for i in ans:
            print(i,end="")
        print()
    
# } Driver Code Ends
