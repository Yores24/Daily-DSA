class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int s=0;
        int n=difficulty.size();
        int m=worker.size();
        for(int i=0;i<m;i++){
            int x=0;
            for(int j=0;j<n;j++){
                if(worker[i]>=difficulty[j] && profit[j]>x){
                    x=profit[j];
                }
                
            }
            s+=x;
        }
        return s;
    }
};