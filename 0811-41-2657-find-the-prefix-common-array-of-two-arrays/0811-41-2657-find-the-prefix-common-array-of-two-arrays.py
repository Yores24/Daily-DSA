class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        
        mp={}
        x=0
        a=[]
        for i in range(0,len(A)):
            if A[i] in mp:
                mp[A[i]]+=1
                x+=1
            else:
                mp[A[i]]=1
            if B[i] in mp:
                mp[B[i]]+=1
                x+=1
            else:
                mp[B[i]]=1
            a.append(x)
        return a