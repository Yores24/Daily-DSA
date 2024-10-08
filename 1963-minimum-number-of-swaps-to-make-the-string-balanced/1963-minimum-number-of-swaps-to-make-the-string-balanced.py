class Solution:
    def minSwaps(self, s: str) -> int:
        
        c=0
        x=0
        for i in s:
            if i==']':
                c+=1
            else:
                c-=1
                
            x=max(x,c)
        
        x=x+1
        return int(x/2)
        
        
            
            