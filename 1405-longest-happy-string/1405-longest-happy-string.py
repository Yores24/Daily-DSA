import heapq
class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        
        res,maxheap="",[]
        for c,ch in [(-a,'a'),(-b,'b'),(-c,'c')]:
            if c!=0:
                heapq.heappush(maxheap,(c,ch))
        
        while maxheap:
            c,ch=heapq.heappop(maxheap)
            if len(res)>1 and res[-1]==res[-2]==ch:
                if not maxheap:
                    break
                c1,ch1=heapq.heappop(maxheap)
                res+=ch1
                c1+=1
                if c1!=0:
                    heapq.heappush(maxheap,(c1,ch1))
            else:
                res+=ch
                c+=1
            if c:
                heapq.heappush(maxheap,(c,ch))
        return res

        
        
        
            
            
        