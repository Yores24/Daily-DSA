class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(begin(horizontalCut),end(horizontalCut),greater<int>());
        sort(begin(verticalCut),end(verticalCut),greater<int>());
        int i=0;
        int j=0;
        int horzp=1;
        int vertp=1;
        int res=0;
        while(i<m-1 && j<n-1){
            if(horizontalCut[i]>=verticalCut[j]){
                res+=horizontalCut[i]*vertp;
                horzp++;
                i++;
            }
            else{
                res+=verticalCut[j]*horzp;
                vertp++;
                j++;
            }
        }
        if(i<m-1){
            while(i<m-1){
                res+=horizontalCut[i]*vertp;
                i++;
            }
        }
        else{
            while(j<n-1){
                res+=verticalCut[j]*horzp;
                j++;
            }          
        }
        return res;
    }
};