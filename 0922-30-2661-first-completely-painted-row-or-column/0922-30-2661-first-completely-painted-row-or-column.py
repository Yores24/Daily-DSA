class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        mp={}

        n=len(mat)
        m=len(mat[0])
        for i in range(n):
            for j in range(m):
                mp[mat[i][j]]=(i,j)
        
        a=[0]*n
        b=[0]*m

        for i in range(0,len(arr)):
            x,y=mp[arr[i]]
            a[x]+=1
            if a[x]==m:
                return i
            b[y]+=1
            if b[y]==n:
                return i
        