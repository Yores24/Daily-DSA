class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        
        def all_prefixes(arr1):
    # Initialize an empty dictionary to store prefixes and their counts
            prefix_dict = {}
            
            # Iterate through each string in the array
            for word in arr1:
                # Generate all possible prefixes for the current word
                for i in range(1, len(word) + 1):
                    prefix = word[:i]
                    
                    # Increment the count of the prefix if it already exists, otherwise initialize it
                    if prefix in prefix_dict:
                        prefix_dict[prefix] += 1
                    else:
                        prefix_dict[prefix] = 1
            
            return prefix_dict
        x=all_prefixes(words)
        
        m=[]
        for i in words:
            l=0
            for j in range(1,len(i)+1):
                
                l+=x[i[:j]]
            m.append(l)

        return m
                    