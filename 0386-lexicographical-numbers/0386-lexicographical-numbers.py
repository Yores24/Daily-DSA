class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        numbers=[]
        for i in range(1,n+1):
            numbers.append(i)
        lexicographical_sorted = sorted(map(str, numbers))
        lexicographical_sorted = list(map(int, lexicographical_sorted))
        return lexicographical_sorted