class Solution:
    
    def ismagic(self,grid:List[List[int]],r:int,c:int):
        s=[]
        for i in range(3):
            for j in range(3):
                num=grid[r+i][c+j]
                if num<1 or num>9 or num in s:
                    return False
                else:
                    s.append(num)
        
        rsum=grid[r][c]+grid[r+1][c]+grid[r+2][c]
        for i in range(3):
            if grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2]!=rsum:
                return False
            elif grid[r+1][c+i]+grid[r+2][c+i]+grid[r][c+i]!=rsum:
                return False
        if grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=rsum:
            return False
        elif grid[r+2][c]+grid[r+1][c+1]+grid[r][c+2]!=rsum:
            return False
        return True
            
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        
        r=len(grid)
        c=len(grid[0])
        count =0
        for i in range(0,r-2):
            for j in range(0,c-2):
                if self.ismagic(grid,i,j):
                    count+=1
        return count