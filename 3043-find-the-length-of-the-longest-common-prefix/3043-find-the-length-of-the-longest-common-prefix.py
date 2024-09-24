class Solution:
    
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        arr1=list(map(str,arr1))
        arr2=list(map(str,arr2))
        def all_prefixes(arr1):
    # Initialize an empty set to store the prefixes
            prefix_set = set()
            
            # Iterate through each string in the array
            for word in arr1:
                # Generate all possible prefixes for the current word
                for i in range(1, len(word) + 1):
                    prefix_set.add(word[:i])  # Add the prefix to the set
                    
            return prefix_set
        arr1=all_prefixes(arr1)
        res=0
        for i in arr2:

            for j in range(1,len(i)+1):
                if i[:j] in arr1:
                    res=max(res,j)
        return res