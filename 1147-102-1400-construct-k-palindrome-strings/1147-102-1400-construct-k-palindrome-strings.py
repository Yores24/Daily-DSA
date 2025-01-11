class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        
        mp={}
        if len(s)<k:
            return False
        for i in s:
            if i in mp:
                mp[i]+=1
            else:
                mp[i]=1
        c=0
        for i in mp:
            if mp[i]%2:
                c+=1
        if c>k:
            return False
        return True
        