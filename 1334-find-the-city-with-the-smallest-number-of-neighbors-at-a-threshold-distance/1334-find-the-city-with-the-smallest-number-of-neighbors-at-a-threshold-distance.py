class Solution(object):
    def findTheCity(self, n, edges, distanceThreshold):
        
        adj=defaultdict(list)
        for v1,v2,dis in edges:
            adj[v1].append((v2,dis))
            adj[v2].append((v1,dis))



        def djsktra(src):
            heap=[(0,src)]
            visit=set()
            while heap:
                dist,node=heapq.heappop(heap)
                if node in visit:
                    continue
                visit.add(node)
                for nei,dist2 in adj[node]:
                    nd=dist+dist2
                    if nd<=distanceThreshold:
                        heapq.heappush(heap,(nd,nei))
            return len(visit)-1
        
        res,min_c=-1,n
        for src in range(n):

            count=djsktra(src)
            if count<=min_c:
                res,min_c=src,count
        return res