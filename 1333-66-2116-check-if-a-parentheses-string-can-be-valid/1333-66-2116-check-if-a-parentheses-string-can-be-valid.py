class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        
        lock=[]
        unlock=[]
        n=len(s)
        for i in range(0,n):

            if locked[i]=='0':
                unlock.append(i)
            else:
                if s[i]=='(':
                    lock.append(i)
                else:
                    if len(lock):
                        lock.pop()
                    elif len(unlock):
                        unlock.pop()
                    else:
                        return False
        if len(lock)==0:
            if len(unlock)%2:
                return False
            return True
        while len(lock):
            if lock[-1]>unlock[-1]:
                return False
            lock.pop()
            unlock.pop()
            if len(lock)==0 and len(unlock)==0:
                return True
            if len(unlock)==0:
                return False
        
        if len(unlock)%2==0:
            return True
        return False


