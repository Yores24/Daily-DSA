class Solution:
    def shortestPalindrome(self, s: str) -> str:
        prefix=0
        suffix=0
        base=29
        power=1
        last=0
        for i,c in enumerate(s):
            char=(ord(c)-ord('a')+1)
            prefix=prefix*base
            prefix=prefix+char
            
            suffix=suffix+char*power
            power=power*base
            
            if prefix==suffix:
                last=i
        
        suffix=s[last+1:]
        return suffix[::-1]+s