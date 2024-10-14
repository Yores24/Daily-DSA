import heapq
import math
class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        
        pq=[]
        
        for i in nums:
            heapq.heappush(pq,-i)
            
        
        s=0
        while(k):
            m=-heapq.heappop(pq)
            s+=m
            heapq.heappush(pq,-math.ceil(m/3))
            k-=1
        return s
        