class Solution(object):
    def minimumDeletions(self, s):
        """
        :type s: str
        :rtype: int
        """
        if(len(s)==1):
            return 0
        m=0
        for i in s:
            if i=='a':
                m+=1
        res=len(s)
        b=0
    
        for i in range(len(s)):
            if s[i]=='a':
                m-=1
            res=min(m+b,res)
           
            if s[i]=='b':
                b+=1
        return res
        