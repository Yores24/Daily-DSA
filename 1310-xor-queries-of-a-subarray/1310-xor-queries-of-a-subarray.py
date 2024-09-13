class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        xor=[0]
    
        for i in arr:
            xor.append(xor[-1]^i)
        answer=[]
        for i in queries:
            answer.append(xor[i[0]]^xor[i[1]+1])

        return answer
            

       