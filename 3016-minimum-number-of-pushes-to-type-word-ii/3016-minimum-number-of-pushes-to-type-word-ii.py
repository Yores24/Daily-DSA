class Solution(object):
    def minimumPushes(self, word):
        """
        :type word: str
        :rtype: int
        """
        dict1={}
        for i in range(len(word)):
            if word[i] in dict1:
                dict1[word[i]]+=1
            else:
                dict1[word[i]]=1
        dict2 = sorted(dict1.items(), key=lambda item: item[1], reverse=True)
        c=0
        s=0
        for _,i in dict2:
            s+=((c/8)+1)*i
            # print(i)
            c+=1
        return s
         