maxl = 10**5
arr = [True] * (maxl + 1)
arr[0] = arr[1] = False

# Using Sieve of Eratosthenes to mark non-prime numbers
for i in range(2, int(maxl**0.5) + 1):
    if arr[i]:
        for j in range(i * i, maxl + 1, i):
            arr[j] = False

class Solution(object):
    def nonSpecialCount(self, l, r):
        """
        :type l: int
        :type r: int
        :rtype: int
        """
        res = r - l + 1
        c = 0
        sqrt_r = int(r**0.5)
        sqrt_l = int(l**0.5)
        
        for i in range(max(sqrt_l, 2), sqrt_r + 1):
            if arr[i]:
                square = i * i
                if l <= square <= r:
                    c += 1
                    
        return res - c