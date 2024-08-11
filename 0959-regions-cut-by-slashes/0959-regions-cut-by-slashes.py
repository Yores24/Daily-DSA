class Solution:

    def func(self,mat:List[List[int]],i:int,j:int)->None:

        if i<0 or i>=len(mat) or j<0 or j>=len(mat[0]) or mat[i][j]==1:
            return
        
        mat[i][j]=1
        self.func(mat,i+1,j)
        self.func(mat,i-1,j)
        self.func(mat,i,j+1)
        self.func(mat,i,j-1)

    def regionsBySlashes(self, grid: List[str]) -> int:
        
        r=len(grid)
        c=len(grid[0])
        mat=[[0 for _ in range(c*3)] for _ in range(r*3)]

        for i in range(r):
            for j in range(c):
                if grid[i][j]=='/':
                    mat[i*3][j*3+2]=1
                    mat[i*3+1][j*3+1]=1
                    mat[i*3+2][j*3]=1
                elif grid[i][j]=='\\':
                    mat[i*3][j*3]=1
                    mat[i*3+1][j*3+1]=1
                    mat[i*3+2][j*3+2]=1
                
        s=0
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j]==0:
                    s+=1
                    self.func(mat,i,j)
        return s    