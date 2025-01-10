class Solution:
    def issub(self,temp,mp):
        for i in range(0,26):
            if temp[i]<mp[i]:
                return False
        return True
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        
        a=[]

        mp=[0]*26

        for i in words2:
            temp=[0]*26

            for j in i:
                temp[ord(j)-ord('a')]+=1

                mp[ord(j)-ord('a')]=max(mp[ord(j)-ord('a')],temp[ord(j)-ord('a')])
        
        for i in words1:
            temp=[0]*26
            for j in i:

                temp[ord(j)-ord('a')]+=1
            if self.issub(temp,mp):
                a.append(i)
        return a

