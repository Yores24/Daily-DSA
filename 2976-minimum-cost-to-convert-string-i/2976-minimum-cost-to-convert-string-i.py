class Solution(object):
    def minimumCost(self, source, target, original, changed, cost):
        
        adj=defaultdict(list)
        
        for src,tgt,cst in zip(original,changed,cost):
            adj[src].append((tgt,cst))
            
        def djkstra(src):
            heap=[(0,src)]
            mincs={}
            while heap:
                cost,node=heapq.heappop(heap)
                if node in mincs:
                    continue
                mincs[node]=cost
                for n,ncs in adj[node]:
                    heapq.heappush(heap,(cost+ncs,n))
            return mincs
        mincst={c:djkstra(c) for c in set(source)}
        
        res=0
        for src,tgt in zip(source,target):
            
            if tgt not in mincst[src]:
                 return -1
            res+=mincst[src][tgt]
        return res
        
        
     
        