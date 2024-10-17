class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        n=len(arr)
        best=0
        s=set(arr)
        for i in range(n):
            for j in range(i+1,n):

                a,b=arr[i],arr[j]
                c=1
                while(b in s):
                    a,b=b,a+b
                    c+=1
                if c>=3:
                    best=max(best,c)
        return best